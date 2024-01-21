#pragma once
#include<iostream>
using namespace std;

const int defaultsize = 100;
class minheap
{
	int* heap;
	int maxheapsize;
	int currentsize;
	void siftup(int start);
	void siftdown(int start, int end);

public:
	minheap(int sz);
	bool insert(const int& data);
	bool remove(int& data);
	~minheap() { delete[]heap; }
	bool IsEmpty()const
	{
		return currentsize == 0;
	}
	bool IsFull()const
	{
		return currentsize == maxheapsize;
	}
};

minheap::minheap(int sz)
{
	maxheapsize = sz > defaultsize ? sz : defaultsize;
	heap = new int[maxheapsize];
	currentsize = 0;
}

void minheap::siftup(int start)
{
	int i = start, j = (i - 1) / 2;
	int temp = heap[i];
	while (i > 0)
	{ //沿父结点路径向上直达根
		if (heap[j] <= temp)break;
		
		heap[i] = heap[j];
		i = j;
		j = (j - 1) / 2;
	}
	heap[i] = temp; //回放temp中暂存的元素
}

void minheap::siftdown(int start, int end)
{
	int i = start, j = 2 * i + 1; // j是左孩子位置  
	int temp = heap[i];
	while (j <= end)
	{
		// 如果右孩子存在且右孩子的值小于左孩子的值，则指向右孩子  
		if (j + 1 <= end && heap[j + 1] < heap[j]) j++;
		if (temp <= heap[j]) break; // 当前节点已经小于或等于其子节点，无需交换  
		heap[i] = heap[j]; // 将当前节点的值下移  
		i = j; // 移动到子节点的位置  
		j = 2 * j + 1; // 获取新的左孩子的位置  
	}
	heap[i] = temp; // 将temp放到正确的位置上  
}

bool minheap::insert(const int& data)
{
	if (currentsize == maxheapsize)
	{
		cout << "堆满！" << endl;
		return false;
	}
	heap[currentsize] = data;
	siftup(currentsize);
	currentsize++;
	return true;
}

bool minheap::remove(int& data)
{
	if (currentsize == 0)
	{
		cout << "堆空！" << endl;
		return false;
	}
	data = heap[0];
	heap[0] = heap[currentsize - 1];
	currentsize--;
	siftdown(0, currentsize - 1);
	return true;
}