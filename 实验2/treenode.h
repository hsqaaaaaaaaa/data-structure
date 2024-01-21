#include<iostream>

using namespace std;


template<class T>
struct treenode//树及其节点定义
{
	T data;
	treenode<T>* leftchild;
	treenode<T>* rightchild;
	treenode(treenode<T>* ptr = NULL) { leftchild = rightchild = ptr; }//初始化指针成员的构造函数
	treenode(const T& item, treenode<T>* ptr = NULL)//初始化数据与指针成员的构造函数
	{
		data = item;
		leftchild =rightchild = ptr;
	}
};