//程序名：linklist.h
//      程序功能：顺序存储结构模板类的实现（包括插入，删除等操作的实现）
//          作者：hsq
//          日期：2023.9.26
//          版本：1.0
//      修改内容：无
//      修改日期：无
//      修改作者：无
//
//
//
//

#include<iostream>
#include<string>
#include<fstream>
#include"linknode.h"
using namespace std;


template<class T>
class linklist:public linknode<T>//单链表类定义
{
	linknode<T>* head;
	int maxsize;

public:
	linklist() { head = new linknode<T>; } //对应linknode中第一个构造函数
	linklist(const T& x) { head = new linknode<T>(x); }//对应linknode中第二个构造函数
	linknode<T>* creat();//新建链表头
	linknode<T>* add(T& x, int size);//添加新成员
	linknode<T>* location(long long number);//搜索地址为number/addresscoord的元素地址
	int insert(string addresscoord, T& x);//在地址addresscoord后插入x
	int remove(string number);//删除学号为number的数据
	void modify(string number);//用x修改学号为number的值
	void sort(T& x);//链表排序
	void search(string number);//搜索学号为number的学生信息
	void Out();//输出
	void In();//输入
	void Outfile(ofstream& outfile, string filename);//输出到文件
	void Infile(ifstream& infile, string filename, int size, T& x);//从文件输入
};

//新建链表头
template<class T>
linknode<T>* linklist<T>::creat()
{
	linklist();
	return head;
}

//添加新成员
template<class T>
linknode<T>* linklist<T>::add(T& x, int size)
{
	linknode<T>* p, * tail;
	p = tail = head;
	for (int i = 0; i < size; i++)
	{
		//cin >> x;
		p = new linknode<T>(x);
		tail->node = p;
		tail = p;
	}
	p->node = NULL;
	return head;
}

//查找位置
template<class T>
linknode<T>* linklist<T>::location(long long number)
{
	if (number < 0)return NULL;
	linknode<T>* p = head;
	int k;
	if (number < 100) k = 0;
	else k = 10000;
	while (p != NULL && k < number)//循链找number/addresscoord所在节点
	{
		k++;
		p = p->node;
	}
	return p;
}

//向学生通讯录插入新的学生信息（按位置号来描述插入点）
template<class T>
int linklist<T>::insert(string addresscoord, T& x)
{
	long long num = stoll(addresscoord);
	linknode<T>* p = location(num);
	if (p == NULL)return 0;//插入失败
	cin >> x;
	linknode<T>* newnode = new linknode<T>(x);
	if (newnode == NULL)
	{
		cerr << "ERROR!!!" << endl;
		exit(1);
	}
	newnode->node = p->node;
	p->node = newnode;//插入到p之后
	maxsize++;
	return 1;
}

//在通讯录删除指定学生的信息（按学号操作）
template<class T>
int linklist<T>::remove(string number)
{
	long long num = stoll(number);
	linknode<T>* p = location(num - 1);
	if (p == NULL || p->node == NULL)return 0;//删除失败
	
	linknode<T>* q = p->node;
	p->node = q->node;
	delete q;
	return 1;
}

//为某个学生修改通讯录地址名或地址位置等信息（按学号操作）
template<class T>
void linklist<T>::modify(string number)
{
	long long num = stoll(number);
	if (num < 0)return;
	linknode<T>* p = location(num);
	if (p == NULL)return;
	else
	{
		cin >> p->data.locationname >> p->data.addresscoord;
	}
}

//按学生的学号排序并显示结果
template<class T>
void linklist<T>::sort(T& x)
{
	linknode<T>* p = head, * q, * min;
	T temp;
	while (p)
	{
		q = p->node;
		min = p;
		while (q != NULL)//查找最小学号
		{
			if (q->data.number < min->data.number)
				min = q;
			q = q->node;
		}
		if (p != min)//交换位置
		{
			temp = min->data;
			min->data = p->data;
			p->data = temp;
		}
		p = p->node;
	}

}

//在通讯录中查询学生信息（按学生学号来进行查找）
template<class T>
void linklist<T>::search(string number)
{
	linknode<T>* p = head;
	while (p->node != NULL)
		if (p->data.number == number)
		{
			cout << p->data;
			break;
		}
		else p = p->node;
}

//在屏幕中输出全部学生信息
template<class T>
void linklist<T>::Out()
{
	linknode<T>* p = head->node;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->node;
	}
}

//在屏幕中输入全部学生信息
template<class T>
void linklist<T>::In()
{
	linknode<T>* p = head->node;
	while (p != NULL)
	{
		cin >> p->data;
		p = p->node;
	}
}

//从文件中读取所有学生通讯录信息
template<class T>
void linklist<T>::Infile(ifstream& infile, string filename, int size, T& x)
{
	infile.open(filename, ios::in);
	if (infile.is_open()) {
		linknode<T>* p, * tail;
		p = tail = head;
		if(infile.is_open()){
		for (int i = 0; i < size; i++)
			{
				infile >> x;
				p = new linknode<T>(x);
				tail->node = p;
				tail = p;
			}
			p->node = NULL;
		}
		infile.close();
	}
	else {
		cout << "Failed to open file: " << filename << endl;
	}
}

//向文件写入所有学生通讯录信息
template<class T>
void linklist<T>::Outfile(ofstream& outfile, string filename)
{
	outfile.open(filename, ios::out);
	if (outfile.is_open()) {
		linknode<T>* p = head->node;
		while (p != NULL) {
			outfile << p->data << endl;
			p = p->node;
		}
		outfile.close();
	}
	else {
		cout << "Failed to open file: " << filename << endl;
	}
}


