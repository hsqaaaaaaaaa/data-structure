#include<iostream>

using namespace std;


template<class T>
class treenode//������ڵ㶨��
{
	T data;
	treenode<T>* leftchild;
	treenode<T>* rightchild;
public:
	treenode(treenode<T>* ptr = NULL) { leftchild = rightchild = ptr; }//��ʼ��ָ���Ա�Ĺ��캯��
	treenode(const T& item, treenode<T>* ptr = NULL)//��ʼ��������ָ���Ա�Ĺ��캯��
	{
		data = item;
		leftchild = rightchild = ptr;
	}
};