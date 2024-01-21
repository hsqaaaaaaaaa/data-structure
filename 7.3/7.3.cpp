#include<iostream>
#include<stack>
using namespace std;

struct list
{
	int desk;//连接的结点序号
	list* link;
};

struct table
{
	int num;//结点序号
	list* adj;
};

class graphlist
{
	table* tables;
	int* count;
public:
	graphlist() {}
	graphlist(int sum);
	//~graphlist();
	void creatlist(int sum);
	void remove(int sum);
};

graphlist::graphlist(int sum)
{
	tables = new table[sum];
	count = new int[sum];
	if (tables == NULL || count == NULL)
	{
		cerr << "Error" << endl;
		delete[]count;
		delete[]tables;
		exit(1);
	}
	for (int i = 0; i < sum; i++)
	{
		tables[i].adj = NULL;
		count[i] = 0;
	}
}

void graphlist::creatlist(int sum)
{
	list* p;
	list* q = new list;
	for (int i = 0; i < sum; i++)
	{
		p = new list;
		cin >> tables[i].num;
		tables[i].adj = p;
		while (1)
		{	
			cin >> p->desk;
			if (p->desk == -1)
			{
				p->link = NULL;
				break;
			}
			count[p->desk]++;
			q = p; 
			p = new list;
			q->link = p;
		}
	}
}

void graphlist::remove(int sum)
{
	stack<int>s;
	int m = 0;
	list* p;
	for (int i = 0; i < sum; i++)
	{
		if (count[i] == 0)s.push(i);
	}
	while (!s.empty())
	{
		int v = s.top();
		s.pop();
		cout << tables[v].num << ' ';
		++m;
		p = tables[v].adj;
		while (p->link != NULL)
		{
			count[p->desk]--;
			if (count[p->desk] == 0)s.push(p->desk);
			p = p->link;
		}
	}
	if (m < sum)cout << endl << "图中有回路！" << endl;
	else cout << endl << "所有结点输出完毕！" << endl;
}


int main()
{
	int sum;
	
	cout << "请输入图的结点总数:";
	while (cin >> sum)
	{
		if (sum == -1)break;
		cout << "请输入每个结点的邻接点序号（结束输入-1）：" << endl;
		graphlist gl(sum);
		gl.creatlist(sum);
		cout << "结点输出顺序：";
		gl.remove(sum);
	}
}

/*
0 1 3 -1
1 5 -1
2 1 5 -1
3 -1
4 0 1 5 -1
5 -1
*/