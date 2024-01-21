#include<iostream>
#include<fstream>
#include<vector>  
#include<queue>
#include"treenode.h"

using namespace std;

template<class T>
class tree:public treenode<T>//������
{
	treenode<T>* root;
	treenode<T>* target = NULL;
public:
	tree(){ root = new treenode<T>; }
	tree(const T&x) { root = new treenode<T>(x); }

	treenode<T>* creat(int size);//�½�ѧ��ͨѶ¼
	
	void insert();//����ѧ����Ϣ

	void Search(string number);
	treenode<T>* search(treenode<T>* t,string number);//��ѯѧ����Ϣ����ѧ��\�绰����\������ѯ��

	void Remove(string number);
	bool remove(treenode<T>* t, string number);//ɾ��ѧ����Ϣ����ѧ��\�绰����\������ѯ��

	void Agemix();
	void agemix(treenode<T>* t, T& x);//���������С��ѧ����Ϣ

	void preorder(treenode<T>* t, vector<treenode<T>*>& v);
	void depth();//�ҳ���ͬһ��ȵ�ѧ����Ϣ

	void Out(int size);
	void out(treenode<T>* t, int size);//���ȫ��ѧ����Ϣ

	void InFile(ifstream& infile, string filename, int size);
	treenode<T>* Infile(ifstream& infile, int size);// ���ļ���ȡѧ��ͨѶ¼��Ϣ

	void OutFile(ofstream& outfile, string filename);
	void Outfile(ofstream& outfile, treenode<T>* t);//���ļ�д��ѧ��ͨѶ¼��Ϣ
};

template<class T>
treenode<T>* tree<T>::creat(int size)//�½�ѧ��ͨѶ¼
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
void tree<T>::insert()//����ѧ����Ϣ  
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
	else cout << "��ѧ����Ϣ�����ڣ�";
}
template<class T>
treenode<T>* tree<T>::search(treenode<T>* t,string number)//��ѯѧ����Ϣ����ѧ��\�绰����\������ѯ��
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
	if (a == true)cout << "�ѳɹ�ɾ����"<<endl;
	else cout << "û�и�ѧ����Ϣ�������ԣ�"<<endl;
}
template<class T>
bool tree<T>::remove(treenode<T>* t, string number)//ɾ��ѧ����Ϣ����ѧ��\�绰����\������ѯ��
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
	else cout << "�Ҳ�����Ӧѧ����Ϣ��" << endl;
}
template<class T>
void tree<T>::agemix(treenode<T>* t, T& x) // ���������С��ѧ����Ϣ  
{
	if (t == NULL) return;
	// �����ǰ�ڵ������С����������������û�з��ؽڵ㣬�򷵻ص�ǰ�ڵ�  
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
		cout << "û�к�������ͬ��ѧ����";
	}
}


template<class T>
void tree<T>::Out(int size)
{
	out(root,size);
}
template<class T>
void tree<T>::out(treenode<T>* t,int size)//���ȫ��ѧ����Ϣ
{
	if (size == 0)//ǰ�����
	{
		if (t == NULL)return;
		if(t->data.age!=-1)
		cout << t->data;
		out(t->leftchild,0);
		out(t->rightchild,0);
	}
	else if (size == 1)//�������
	{
		if (t == NULL)return;
		out(t->leftchild, 1);
		if (t->data.age != -1)
		cout << t->data;
		out(t->rightchild, 1);
	}
	else if (size == 2)//�������
	{
		if (t == NULL)return;
		out(t->leftchild, 2);
		out(t->rightchild, 2);
		if (t->data.age != -1)
		cout << t->data;
	}
}

template<class T>
void tree<T>::InFile(ifstream& infile, string filename, int size)//������ò�α���������ȫ������
{

	infile.open(filename, ios::in);
	if (infile.is_open())
	{
		root = Infile(infile,size);
		cout << "�ѳɹ�д��!" << endl;
	}
	else
	{
		cerr << "�ļ�δ�ܳɹ��򿪣������ԣ�" << endl;
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
		cout << "�ѳɹ�����!" << endl;
	}
	else
	{
		cerr << "�ļ�δ�ܳɹ��򿪣������ԣ�" << endl;
	}
}
template<class T>
void tree<T>::Outfile(ofstream& outfile, treenode<T>* t)//����������ǰ�����
{
	if (t == NULL)return;
	if (t->data.age != 0)
	outfile << t->data << endl;
	Outfile(outfile, t->leftchild);
	Outfile(outfile, t->rightchild);

}