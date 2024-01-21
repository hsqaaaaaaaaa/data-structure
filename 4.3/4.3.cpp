#include<iostream>
#include<vector>

using namespace std;
vector<int>mid;//用vector可以构造未知长度的数组
vector<int>last;

void front(int x, int y, int p, int q)//x=数组第一个值的位置，y=数组最后一个值的位置（中序），pq相同意思为后序
{
	if (x > y || p > q)return;//当第一个叶子位置在根的后面
	int k = x;
	while (mid[k] != last[q])k++;//找根的位置
	int len = k - x;//求根到第一个叶子的距离
	cout << last[q] << ' ';//输出根
	front(x, k - 1, p, p + len - 1);//left
	front(k + 1, y, p + len, q - 1);//right
}
using namespace std;
int main()
{
	int size;
	int number;
	cout << "输入树的数目：";
	while (cin >> size)//树的数目
	{
		if (size == -1)break;
		cout << "输入树的中序遍历序列：";
		while(1)
		{
			cin >> number;
			mid.push_back(number);//中序遍历
			if (cin.get() == '\n')break;
		}
		int len = mid.size();
		cout << "输入树的后序遍历序列：";
		while (1)
		{
			cin >> number;
			last.push_back(number);//后序遍历
			if (cin.get() == '\n')break;
		}
		cout << "输出树的前序遍历序列：";
		front(0, len-1, 0, len-1);
	}
	
}