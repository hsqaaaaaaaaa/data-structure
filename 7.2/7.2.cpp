#include<iostream>

using namespace std;

const int maxsize = 65535;

class graphmtx
{
	int* dist;//保存两个顶点之间的距离值
	int** edge;//邻接矩阵 已经访问过结点的值将对角线上对应位置的0变为1即可
	int size;//邻接矩阵大小

public:
	graphmtx(int row, int col);
	~graphmtx();
	void dijkstra(int n);//每次都找出剩余顶点到源顶点距离最短的顶点 目的是找所有顶点到源顶点的最短距离

};

graphmtx::graphmtx(int row, int col)//生成邻接矩阵
{
	size = row;
	dist = new int[row];
	memset(dist, 0, row);//初始化
	edge = (int**)new int* [row];
	for (int i = 0; i < row; i++)
		edge[i] = new int[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> edge[i][j];
}

graphmtx::~graphmtx()
{
	delete[]dist;
	for (int i = 0; i < size; i++)
		delete[] edge[i];
	delete[] edge;
}

void graphmtx::dijkstra(int n)
{
	int pos = 0;//结点位置
	for (int i = 0; i < size; i++)
	{
		dist[i] = edge[n][i];
	}
	edge[n][n] = 1;
	for (int p = 0; p < size - 1; p++)
	{
		int min = maxsize;
		for (int j = 0; j < size ; j++)
		{
			if (edge[j][j] == 0 && dist[j] < min)
			{
				pos = j;
				min = dist[j];
			}
		}

		edge[pos][pos] = 1;//找最小值 只有一个
		for (int k = 0; k < size; k++)
		{
			if (edge[k][k] == 0 && edge[pos][k] + min < dist[k])
			{
				dist[k] = edge[pos][k] + min;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << n << "-->" << i <<' '<< "distance:" << dist[i] << endl;
}

int main()
{
	int row, col;
	int node;
	cout << "请输入邻接矩阵的行列总数:";
	while (cin >> row >> col)
	{
		if (row == -1 || col == -1)break;
		cout << "请输入邻接矩阵的元素（无穷大填65535）:" << endl;
		graphmtx gm(row, col);
		cout << "Dijkstra:" << endl;
		cout << "请输入源顶点:";
		cin >> node;
		gm.dijkstra(node);
		cout << "请输入邻接矩阵的行列总数:";
	}
}
/*
0 10 65535 30 100
65535 0 50 65535 65535
65535 65535 0 65535 10
65535 65535 20 0 60
65535 65535 65535 65535 0
*/