#pragma once
#include<iostream>
using namespace std;

const int defaultsize = 10;
template<typename T>
class MinHeap
{
	T* heap;
	int currentSize;
	int maxheapsize;
	void siftdown(int start, int m);
	void siftup(int start);
public:
	MinHeap(int sz = defaultsize);
	~MinHeap() { delete[]heap; }
	bool Insert(const T& x);
	bool RemoveMin(T& x);
	bool IsEmpty()const
	{
		return currentSize == 0;
	}
	bool IsFull()const
	{
		return currentSize == maxheapsize;
	}
};

template<typename T>
MinHeap<T>::MinHeap(int sz)
{
	maxheapsize = defaultsize < sz ? sz : defaultsize;
	heap = new T[maxheapsize];
	currentSize = 0;
}

template<typename T>
void MinHeap<T>::siftdown(int start, int m)
{
	int i = start, j = 2 * i + 1; //j��i������Ůλ��
	T temp = heap[i];
	while (j <= m) //����Ƿ����λ��
	{
		//��jָ�����ڵ��е�С��
		if (j < m && heap[j] > heap[j + 1])	j++;

		if (temp <= heap[j]) break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp; //�ط�temp���ݴ��Ԫ��
}

template<typename T>
void MinHeap<T>::siftup(int start)
{
	int j = start, i = (j - 1) / 2;
	T temp = heap[j];
	while (j > 0)
	{ //�ظ����·������ֱ���
		if (heap[i] <= temp)
		{
			break;
		}
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp; //�ط�temp���ݴ��Ԫ��
}

template<typename T>
bool MinHeap<T>::Insert(const T& x)
{
	if (currentSize == maxheapsize)
	{ //����
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x; //����
	siftup(currentSize);   //���ϵ���
	currentSize++;		   //�Ѽ�����1
	return true;
}

template<typename T>
bool MinHeap<T>::RemoveMin(T& x)
{
	if (!currentSize)
	{ //�ѿ�, ����false
		cout << "Heap empty!!" << endl;
		return false;
	}
	x = heap[0];					 // ������СԪ��
	heap[0] = heap[currentSize - 1]; //���Ԫ����������
	currentSize--;
	siftdown(0, currentSize - 1); //�������µ���Ϊ��
	return true;
}