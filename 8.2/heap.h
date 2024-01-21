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
	{ //�ظ����·������ֱ���
		if (heap[j] <= temp)break;
		
		heap[i] = heap[j];
		i = j;
		j = (j - 1) / 2;
	}
	heap[i] = temp; //�ط�temp���ݴ��Ԫ��
}

void minheap::siftdown(int start, int end)
{
	int i = start, j = 2 * i + 1; // j������λ��  
	int temp = heap[i];
	while (j <= end)
	{
		// ����Һ��Ӵ������Һ��ӵ�ֵС�����ӵ�ֵ����ָ���Һ���  
		if (j + 1 <= end && heap[j + 1] < heap[j]) j++;
		if (temp <= heap[j]) break; // ��ǰ�ڵ��Ѿ�С�ڻ�������ӽڵ㣬���轻��  
		heap[i] = heap[j]; // ����ǰ�ڵ��ֵ����  
		i = j; // �ƶ����ӽڵ��λ��  
		j = 2 * j + 1; // ��ȡ�µ����ӵ�λ��  
	}
	heap[i] = temp; // ��temp�ŵ���ȷ��λ����  
}

bool minheap::insert(const int& data)
{
	if (currentsize == maxheapsize)
	{
		cout << "������" << endl;
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
		cout << "�ѿգ�" << endl;
		return false;
	}
	data = heap[0];
	heap[0] = heap[currentsize - 1];
	currentsize--;
	siftdown(0, currentsize - 1);
	return true;
}