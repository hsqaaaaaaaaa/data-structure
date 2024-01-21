#include<iostream>
#include<queue>
using namespace std;

struct graphlink
{
	int desk;
	graphlink* link;
};
struct list
{
	int data;
	graphlink* adj;
};

class graphlist
{
	list* table;
public:
	graphlist(){}
	graphlist(int sum);
	//~graphlist();
	void creatlist(int sum);
	void DFS(int note);
	void BFS(int note);
};

graphlist::graphlist(int sum)
{
	table = new list[sum];
	if (table == NULL)cout << "Error!" << endl;
	for (int i = 1; i <= sum; i++)
		table[i].adj = NULL;
}



void graphlist::creatlist(int sum)
{
	graphlink* p;
	for (int i = 1; i <= sum; i++)
	{
		cin >> table[i].data;
		while(1)
		{
			p = new graphlink;
			cin >> p->desk;
			if (p->desk == -1)
			{
				p = NULL;
				break;
			}
			p->link = table[i].adj;
			table[i].adj = p;
		} 
	}
}

void graphlist::DFS(int note)
{
	graphlink* p;
	cout << table[note].data << " ";
	p = table[note].adj;
	while (p != NULL)
	{
		DFS(p->desk);
		p = p->link;
	}
}

void graphlist::BFS(int note)
{
	graphlink* p;
	queue<int>q;
	q.push(note);

	while (!q.empty())
	{
		int loc = q.front();
		q.pop();
		cout << table[loc].data << ' ';
		p = table[loc].adj;
		while (p != NULL)
		{
			q.push(p->desk);
			p = p->link;
		}

	}
}

int main()
{
	int sum;
	int note;
	cout << "请输入图的结点总数：";
	while (cin >> sum)
	{
		if (sum == -1)break;
		graphlist gl(sum);
		cout << "请输入每个结点的邻接点序号（结束输入-1，按头插入顺序输入序列）：" << endl;
		gl.creatlist(sum);
		cout << "请输入遍历的出发点序号：";
		cin >> note;
		cout << "深度优先遍历序列：";
		gl.DFS(note);
		cout << endl;
		cout << "广度优先遍历序列：";
		gl.BFS(note);
		cout << endl;
		cout << "请输入图的结点总数：";
	}
}
