#include<iostream>
#include<queue>

using namespace std;
const int maxsize = 100;
const int maxweight = 65535;

struct UFset
{
	int ufset[maxsize];

	UFset()
	{
		for (int i = 0; i < maxsize; i++)
			ufset[i] = -1;
	}
	int find(int head);
	void Union(int head, int tail);
};

struct MSTnode
{
	int head, tail;
	int cost;//权值

	bool operator>(const MSTnode& m)const
	{
		return cost > m.cost;
	}
	bool operator<(const MSTnode& m)const
	{
		return cost < m.cost;
	}
};

class graphmtx
{
	int* visit;//顶点表
	int** edge;//邻接矩阵
	int size;

public:
	graphmtx(int row, int col);
	~graphmtx();
	void kruskal();//找权值最小的边
	void prim(int node);//任意找一个顶点 找该顶点到别的顶点的最小权值边

};

int UFset::find(int head)
{
	//在并查集中查找并返回包含元素 x 的树的根
	if (ufset[head] >= 0)head = ufset[head];//寻找head是否在集合中
	return head;//返回ufset[head]的值
}

void UFset::Union(int head, int tail)
{
	
	if (head < tail) {//head是小树,将其加入大树中
		ufset[head] = tail;
	}

	else {//tail为小树,将其加入head中
		ufset[tail] = head;
	}

}

graphmtx::graphmtx(int row, int col)//生成邻接矩阵
{
	size = row;
	visit = new int[row];
	edge = (int**)new int* [row];
	for (int i = 0; i < row; i++)
		edge[i] = new int[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> edge[i][j];
}

graphmtx::~graphmtx()
{
	delete[]visit;
	for (int i = 0; i < size; i++)
		delete[] edge[i];
	delete[] edge;
}

void graphmtx::kruskal()
{
	priority_queue<MSTnode,vector<MSTnode>,greater<MSTnode>>p;
	int count = 0;
	MSTnode ed;
	UFset uf;
	int a, b;
	
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (edge[i][j] < maxweight)
			{
				ed.head = i;
				ed.tail = j;
				ed.cost = edge[i][j];
				p.push(ed);
			}
			
	count = 1;
	while (count < size)
	{
		ed = p.top();
		p.pop();
		a = uf.find(ed.head);
		b = uf.find(ed.tail);
		if (a != b)
		{
			uf.Union(a, b);
			cout << ed.head << "-->" << ed.tail << ' ' << "weight:" << ed.cost << endl;
			count++;
		}
	}
}
void graphmtx::prim(int node)
{
	int count = 0;
	int j;
	priority_queue<MSTnode, vector<MSTnode>, greater<MSTnode>>q;
	MSTnode ed;
	edge[node][node] = 1;
	count++;
	while (count < size)
	{
		for (int i = 0; i < size; i++)
		{
			if ((edge[i][i] == 0) && edge[node][i] < maxweight)
			{
				ed.head = i;
				ed.tail = node;
				ed.cost = edge[node][i];
				q.push(ed);
			}
		}

		while (!q.empty() && count < size)
		{
			ed = q.top();
			q.pop();
			if (edge[ed.head][ed.head] == 0)
			{
				cout << ed.tail << "-->" << ed.head << ' ' << "weight:" << ed.cost << endl;
				j = ed.head;
				edge[j][j] = 1;
				count++;
			}
		}
		
		node = ed.head;
	}

}


int main()
{
	int row, col;
	int node;
	cout << "请输入邻接矩阵的行列总数:";
	while (cin >> row >> col)
	{
		if (row == -1 || col == -1)break;
		cout << "请输入邻接矩阵对应的无向带权图的权值（无穷大请输入65535）:" << endl;
		graphmtx gm(row, col);
		cout << "Kruskal:" << endl;
		gm.kruskal();
		cout << "Prim:" << endl;
		cout << "请输入起始顶点的值:";
		cin >> node;
		gm.prim(node);
		

		cout << "请输入邻接矩阵的行列总数:";
	}
}

/*
0 28 65535 65535 65535 10 65535
28 0 16 65535 65535 65535 14
65535 16 0 12 65535 65535 65535
65535 65535 12 0 22 65535 18
65535 65535 65535 22 0 25 24
10 65535 65535 65535 25 0 65535
65535 14 65535 18 24 65535 0
*/