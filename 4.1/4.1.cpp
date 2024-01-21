#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int size;
	stack<int>t;
	while (cin >> size)
	{
		int counter = 0;
		if (size == -1)break;
		int* Tree = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> Tree[i];
		}
		int i = 0;
		do
		{
			while (2 * i + 1 < size)
			{
				t.push(i);
				i = 2 * i + 1;
			}
			if (i < size)
			{
				cout << Tree[i] << ' ';
				++counter;
			}
			if (!t.empty()&&2 * i + 2 >= size)
			{
				i = t.top();
				t.pop();
				cout << Tree[i] << ' ';
				++counter;
				i = 2 * i + 2;
			}
		} while (counter != size);
		cout << endl;
		delete[] Tree;
	}
}