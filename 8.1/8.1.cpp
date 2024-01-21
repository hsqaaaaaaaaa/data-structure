#include<iostream>
using namespace std;

int quicksort(int s[], int start, int end)
{
	int down = start, up = end;
	s[0] = s[start];
	while (down < up)
	{
		while (down < up && s[up] >= s[0])//从右到左
			up--;
		if (down < up)
			s[down++] = s[up];
		while (down < up && s[down] <= s[0])//从右到左
			down++;
		if (down < up)
			s[up--] = s[down];
	}
	s[down] = s[0];
	return up;//返回down也是一样的 因为此时的down=up
}

void quickSort(int s[], int start, int end)
{
	int mid = 0;
	if (start < end)//递归进行快速排序
	{
		mid = quicksort(s, start, end);
		quickSort(s, mid + 1, end);
		quickSort(s, start, mid - 1);
	}
}

int main()
{
	int num;
	int* s;
	cout << "请输入待排序的元素个数：";
	while (cin >> num)
	{
		s = new int[num];//创建一个数组
		if (num == -1)break;
		cout << "输入待排序的元素（整数):";
		for (int i = 1; i <= num; i++)
		{
			cin >> s[i];
		}
		cout << "排序前的元素序列:";
		for (int i = 1; i <= num; i++)
			cout << s[i] << ' ';
		quickSort(s, 1, num);

		cout << endl << "排序后的元素序列:";
		for (int i = 1; i <= num; i++)
			cout << s[i] << ' ';

	}
}