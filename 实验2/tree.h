#include<iostream>
#include<fstream>
#include<vector>  
#include<queue>
#include"treenode.h"

using namespace std;

template<class T>
class tree:public treenode<T>//树定义
{
	treenode<T>* root;
	treenode<T>* target = NULL;
public:
	tree(){ root = new treenode<T>; }
	tree(const T&x) { root = new treenode<T>(x); }

	treenode<T>* creat(int size);//新建学生通讯录
	
	void insert();//插入学生信息

	void Search(string number);
	treenode<T>* search(treenode<T>* t,string number);//查询学生信息（按学号\电话号码\姓名查询）

	void Remove(string number);
	bool remove(treenode<T>* t, string number);//删除学生信息（按学号\电话号码\姓名查询）

	void Agemix();
	void agemix(treenode<T>* t, T& x);//输出年龄最小的学生信息

	void preorder(treenode<T>* t, vector<treenode<T>*>& v);
	void depth();//找出在同一深度的学生信息

	void Out(int size);
	void out(treenode<T>* t, int size);//输出全部学生信息

	void InFile(ifstream& infile, string filename, int size);
	treenode<T>* Infile(ifstream& infile, int size);// 向文件读取学生通讯录信息

	void OutFile(ofstream& outfile, string filename);
	void Outfile(ofstream& outfile, treenode<T>* t);//向文件写入学生通讯录信息
};

template<class T>
treenode<T>* tree<T>::creat(int size)//新建学生通讯录
{
	queue<treenode<T>*>q;
	T x;
	cin >> x;
	root = new treenode<T>(x);
	q.push(root);
	size--;
	while (size)
	{
		treenode<T>* k = q.front();
		q.pop();
		cin >> x;
		k->leftchild = new treenode<T>(x);
		size--;

		if (size != 0)
		{
			cin >> x;
			k->rightchild = new treenode<T>(x);
			q.push(k->leftchild);
			q.push(k->rightchild);
			size--;
		}
	}
	return root;
}


template<class T>
void tree<T>::insert()//插入学生信息  
{
	T x;
	cin >> x;
	treenode<T>* p = new treenode<T>(x);
	if (!root) {
		root = p;
		return;
	}
	treenode<T>* k;
	queue<treenode<T>*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		k = Q.front();
		Q.pop();
		if (k->leftchild == NULL)
		{
			k->leftchild = p;
			break;
		}
		else if (k->leftchild) {
			Q.push(k->leftchild);
		}
		if (k->rightchild == NULL)
		{
			k->rightchild = p;
			break;
		}
		else if (k->rightchild) {
			Q.push(k->rightchild);
		}
	}
	queue<treenode<T>*> empty;
	Q.swap(empty);
}

template<class T>
void tree<T>::Search(string number)
{
	treenode<T>* p = search(root, number);
	if (p != NULL)cout << p->data;
	else cout << "该学生信息不存在！";
}
template<class T>
treenode<T>* tree<T>::search(treenode<T>* t,string number)//查询学生信息（按学号\电话号码\姓名查询）
{
	if (t == NULL)return NULL;
	else if (t->data.number == number || t->data.name == number || t->data.phonenumber == number)
	{
		target = t;
	}
	search(t->leftchild,number);
	search(t->rightchild,number);
	return target;
}

template<class T>
void tree<T>::Remove(string number)
{
	bool a = remove(root, number);
	if (a == true)cout << "已成功删除！"<<endl;
	else cout << "没有该学生信息，请重试！"<<endl;
}
template<class T>
bool tree<T>::remove(treenode<T>* t, string number)//删除学生信息（按学号\电话号码\姓名查询）
{
	treenode<T>* p = search(root, number);
	p->data.age = -1;
	return true;
}

template<class T>
void tree<T>::Agemix()
{
	T x = root->data;
	agemix(root, x);
	if (root != NULL)cout << x << endl;
	else cout << "找不到对应学生信息！" << endl;
}
template<class T>
void tree<T>::agemix(treenode<T>* t, T& x) // 输出年龄最小的学生信息  
{
	if (t == NULL) return;
	// 如果当前节点年龄更小，或者左右子树中没有返回节点，则返回当前节点  
	if ((t->data.age <= x.age && t->data.age != -1)) {
		x = t->data;
	}

	agemix(t->leftchild, x);
	agemix(t->rightchild, x);
}

template<class T>
void tree<T>::preorder(treenode<T>* t, vector<treenode<T>*>& v)
{
	if (t == NULL)return;
	v.push_back(t);
	preorder(t->leftchild, v);
	preorder(t->rightchild, v);
}
template<class T>
void tree<T>::depth()
{
	vector<treenode<T>*>stusamexadcode;
	preorder(root, stusamexadcode);
	bool find = false;
	for (int i = 0; i < stusamexadcode.size(); i++)
	{
		for (int j = i + 1; j < stusamexadcode.size(); j++)
		{
			if (stusamexadcode[i]->data.xaddresscode == stusamexadcode[j]->data.xaddresscode)
			{
				find = true;
				cout << stusamexadcode[i]->data << endl;
				cout << stusamexadcode[j]->data << endl;
			}
		}
	}
	if (!find)
	{
		cout << "没有横坐标相同的学生！";
	}
}


template<class T>
void tree<T>::Out(int size)
{
	out(root,size);
}
template<class T>
void tree<T>::out(treenode<T>* t,int size)//输出全部学生信息
{
	if (size == 0)//前序遍历
	{
		if (t == NULL)return;
		if(t->data.age!=-1)
		cout << t->data;
		out(t->leftchild,0);
		out(t->rightchild,0);
	}
	else if (size == 1)//中序遍历
	{
		if (t == NULL)return;
		out(t->leftchild, 1);
		if (t->data.age != -1)
		cout << t->data;
		out(t->rightchild, 1);
	}
	else if (size == 2)//后序遍历
	{
		if (t == NULL)return;
		out(t->leftchild, 2);
		out(t->rightchild, 2);
		if (t->data.age != -1)
		cout << t->data;
	}
}

template<class T>
void tree<T>::InFile(ifstream& infile, string filename, int size)//读入采用层次遍历建立完全二叉树
{

	infile.open(filename, ios::in);
	if (infile.is_open())
	{
		root = Infile(infile,size);
		cout << "已成功写入!" << endl;
	}
	else
	{
		cerr << "文件未能成功打开，请重试！" << endl;
	}

}
template<class T>
treenode<T>* tree<T>::Infile(ifstream& infile, int size)
{
	queue<treenode<T>*>qu;
	T x;
	infile >> x;
	root = new treenode<T>(x);
	qu.push(root);
	size--;
	while (size)
	{
		treenode<T>* k = qu.front();
		qu.pop();
		infile >> x;
		k->leftchild = new treenode<T>(x);
		size--;

		if (size != 0)
		{
			infile >> x;
			k->rightchild = new treenode<T>(x);
			qu.push(k->leftchild);
			qu.push(k->rightchild);
			size--;
		}
	}
	return root;
}

template<class T>
void tree<T>::OutFile(ofstream& outfile, string filename)
{
	outfile.open(filename, ios::out);
	if (outfile.is_open())
	{
		Outfile(outfile,root);
		cout << "已成功保存!" << endl;
	}
	else
	{
		cerr << "文件未能成功打开，请重试！" << endl;
	}
}
template<class T>
void tree<T>::Outfile(ofstream& outfile, treenode<T>* t)//读出都采用前序遍历
{
	if (t == NULL)return;
	if (t->data.age != 0)
	outfile << t->data << endl;
	Outfile(outfile, t->leftchild);
	Outfile(outfile, t->rightchild);

}