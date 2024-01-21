//程序名：linknode.h
//      程序功能：定义链表节点类
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

using namespace std;

template<class T>
struct linknode//链表节点类定义
{
	T data;//数据域
	linknode<T>* node;//链指针域

	linknode(linknode<T>* ptr = NULL) { node = ptr; }//初始化指针成员的构造函数
	linknode(const T& item, linknode<T>* ptr = NULL)//初始化数据与指针成员的构造函数
	{
		data = item;
		node = ptr;
	}
};
