#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class graphmtx
{
	int* visit;//顶点表
	int** edge;//邻接矩阵

public:
	graphmtx(int row,int col);
	~graphmtx();
	void DFS(int row, int note);//深度优先算法
	void BFS(int row,int note);//广度优先算法
};

graphmtx::graphmtx(int row, int col)
{
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
	delete[]edge;
}

void graphmtx::DFS(int row, int note)//深度优先算法
{
	memset(visit, 0, row * sizeof(int));
	stack<int>s;
	s.push(note - 1);
	visit[note - 1] = 1;

	while (!s.empty())
	{
		int loc = s.top();
		s.pop();
		cout << loc + 1 << ' ';

		for (int i = row - 1; i >= 0; i--)
		{
			if (edge[loc][i] == 1 && visit[i] == 0)
			{
				s.push(i);
				visit[i] = 1;
			}
		}
	}
}

void graphmtx::BFS(int row,int note)//广度优先算法
{
	memset(visit, 0, row * sizeof(int));
	queue<int>q;
	q.push(note - 1);
	visit[note - 1] = 1;

	while (!q.empty())
	{
		int loc = q.front();
		q.pop();
		cout << loc + 1 << ' ';

		for (int i = 0; i < row; i++)
		{
			if (edge[loc][i] == 1 && visit[i] == 0)
			{
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main()
{
	int row, col, note;
	cout << "请输入邻接矩阵的行列总数：";
	while (cin >> row >> col)
	{
		if (row == -1 || col == -1 || row != col) break;
		cout << "请输入邻接矩阵每行数据：" << endl;
		graphmtx gm(row, col);
		cout << "请输入遍历的出发点序号：";
		cin >> note;
		cout << "深度优先遍历序列：";
		gm.DFS(row, note);
		cout << endl;
		cout << "广度优先遍历序列：";
		gm.BFS(row,note);
		cout << endl;
		cout << "请输入邻接矩阵的行列总数：";
	}
}

