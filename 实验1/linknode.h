//��������linknode.h
//      �����ܣ���������ڵ���
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

using namespace std;

template<class T>
struct linknode//����ڵ��ඨ��
{
	T data;//������
	linknode<T>* node;//��ָ����

	linknode(linknode<T>* ptr = NULL) { node = ptr; }//��ʼ��ָ���Ա�Ĺ��캯��
	linknode(const T& item, linknode<T>* ptr = NULL)//��ʼ��������ָ���Ա�Ĺ��캯��
	{
		data = item;
		node = ptr;
	}
};
