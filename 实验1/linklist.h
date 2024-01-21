//��������linklist.h
//      �����ܣ�˳��洢�ṹģ�����ʵ�֣��������룬ɾ���Ȳ�����ʵ�֣�
//          ���ߣ�hsq
//          ���ڣ�2023.9.26
//          �汾��1.0
//      �޸����ݣ���
//      �޸����ڣ���
//      �޸����ߣ���
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
class linklist:public linknode<T>//�������ඨ��
{
	linknode<T>* head;
	int maxsize;

public:
	linklist() { head = new linknode<T>; } //��Ӧlinknode�е�һ�����캯��
	linklist(const T& x) { head = new linknode<T>(x); }//��Ӧlinknode�еڶ������캯��
	linknode<T>* creat();//�½�����ͷ
	linknode<T>* add(T& x, int size);//����³�Ա
	linknode<T>* location(long long number);//������ַΪnumber/addresscoord��Ԫ�ص�ַ
	int insert(string addresscoord, T& x);//�ڵ�ַaddresscoord�����x
	int remove(string number);//ɾ��ѧ��Ϊnumber������
	void modify(string number);//��x�޸�ѧ��Ϊnumber��ֵ
	void sort(T& x);//��������
	void search(string number);//����ѧ��Ϊnumber��ѧ����Ϣ
	void Out();//���
	void In();//����
	void Outfile(ofstream& outfile, string filename);//������ļ�
	void Infile(ifstream& infile, string filename, int size, T& x);//���ļ�����
};

//�½�����ͷ
template<class T>
linknode<T>* linklist<T>::creat()
{
	linklist();
	return head;
}

//����³�Ա
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

//����λ��
template<class T>
linknode<T>* linklist<T>::location(long long number)
{
	if (number < 0)return NULL;
	linknode<T>* p = head;
	int k;
	if (number < 100) k = 0;
	else k = 10000;
	while (p != NULL && k < number)//ѭ����number/addresscoord���ڽڵ�
	{
		k++;
		p = p->node;
	}
	return p;
}

//��ѧ��ͨѶ¼�����µ�ѧ����Ϣ����λ�ú�����������㣩
template<class T>
int linklist<T>::insert(string addresscoord, T& x)
{
	long long num = stoll(addresscoord);
	linknode<T>* p = location(num);
	if (p == NULL)return 0;//����ʧ��
	cin >> x;
	linknode<T>* newnode = new linknode<T>(x);
	if (newnode == NULL)
	{
		cerr << "ERROR!!!" << endl;
		exit(1);
	}
	newnode->node = p->node;
	p->node = newnode;//���뵽p֮��
	maxsize++;
	return 1;
}

//��ͨѶ¼ɾ��ָ��ѧ������Ϣ����ѧ�Ų�����
template<class T>
int linklist<T>::remove(string number)
{
	long long num = stoll(number);
	linknode<T>* p = location(num - 1);
	if (p == NULL || p->node == NULL)return 0;//ɾ��ʧ��
	
	linknode<T>* q = p->node;
	p->node = q->node;
	delete q;
	return 1;
}

//Ϊĳ��ѧ���޸�ͨѶ¼��ַ�����ַλ�õ���Ϣ����ѧ�Ų�����
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

//��ѧ����ѧ��������ʾ���
template<class T>
void linklist<T>::sort(T& x)
{
	linknode<T>* p = head, * q, * min;
	T temp;
	while (p)
	{
		q = p->node;
		min = p;
		while (q != NULL)//������Сѧ��
		{
			if (q->data.number < min->data.number)
				min = q;
			q = q->node;
		}
		if (p != min)//����λ��
		{
			temp = min->data;
			min->data = p->data;
			p->data = temp;
		}
		p = p->node;
	}

}

//��ͨѶ¼�в�ѯѧ����Ϣ����ѧ��ѧ�������в��ң�
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

//����Ļ�����ȫ��ѧ����Ϣ
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

//����Ļ������ȫ��ѧ����Ϣ
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

//���ļ��ж�ȡ����ѧ��ͨѶ¼��Ϣ
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

//���ļ�д������ѧ��ͨѶ¼��Ϣ
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


