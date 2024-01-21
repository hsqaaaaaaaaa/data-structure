#include<iostream>
#include"heap.h"

using namespace std;

int main()
{
	int num;
	int* s;
	int data;
	cout << "请输入待排序的元素个数:";
	while (cin >> num)
	{
		if (num == -1)break;
		s = new int[num];
		minheap hp(num);
		if (num == -1)break;
		cout << "输入待排序的元素（整数):";
		for (int i = 0; i < num; i++)
		{
			cin >> s[i];
			hp.insert(s[i]);
		}
		cout << "排序前的元素序列:";
		for (int i = 0; i < num; i++)
			cout << s[i] << ' ';

		cout << endl << "排序后的元素序列:";
		for (int i = 0; i < num; i++)
		{
			hp.remove(s[i]);
			cout << s[i] << ' ';
		}
		
	}
}