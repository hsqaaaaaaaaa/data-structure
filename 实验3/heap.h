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
	int i = start, j = 2 * i + 1; //j是i的左子女位置
	T temp = heap[i];
	while (j <= m) //检查是否到最后位置
	{
		//让j指向两节点中的小者
		if (j < m && heap[j] > heap[j + 1])	j++;

		if (temp <= heap[j]) break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp; //回放temp中暂存的元素
}

template<typename T>
void MinHeap<T>::siftup(int start)
{
	int j = start, i = (j - 1) / 2;
	T temp = heap[j];
	while (j > 0)
	{ //沿父结点路径向上直达根
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
	heap[j] = temp; //回放temp中暂存的元素
}

template<typename T>
bool MinHeap<T>::Insert(const T& x)
{
	if (currentSize == maxheapsize)
	{ //堆满
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x; //插入
	siftup(currentSize);   //向上调整
	currentSize++;		   //堆计数加1
	return true;
}

template<typename T>
bool MinHeap<T>::RemoveMin(T& x)
{
	if (!currentSize)
	{ //堆空, 返回false
		cout << "Heap empty!!" << endl;
		return false;
	}
	x = heap[0];					 // 返回最小元素
	heap[0] = heap[currentSize - 1]; //最后元素填补到根结点
	currentSize--;
	siftdown(0, currentSize - 1); //自上向下调整为堆
	return true;
}