#include<iostream>
#include<vector>
using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;
	tree* parent;

	tree(int d)
	{
		data = d;
		left = right = NULL;
	}
};

void insert(tree*& root, int data, tree*& p)
{
	if (root == NULL)
	{
		root = new tree(data);
		root->parent = p;
		return;
	}
	else if (root->data < data)insert(root->right, data, root);
	else if (root->data > data)insert(root->left, data, root);
	else return;
}

tree* creat(tree*& root, int size, tree*& p)
{
	int data;
	cout << "输入建树数据：";
	while (size)
	{
		cin >> data;
		insert(root, data, p);
		size--;
	}
	return root;
}

bool search(tree* root, int idata)
{
	if (root == NULL) return false;
	else if (root->data == idata)return true;
	else if (root->data < idata)search(root->right, idata);
	else if (root->data > idata)search(root->left, idata);
}

tree* remove(tree*& root, int idata)
{
	if (root->data == idata)
	{
		tree* k = root;
		if (root->parent->left != NULL && root->parent->left->data == k->data)root->parent->left = k->left;
		if (root->parent->right != NULL && root->parent->right->data == k->data)root->parent->right = k->right;
		delete k;
	}
	else if (root->data < idata)remove(root->right, idata);
	else if (root->data > idata)remove(root->left, idata);
	return root;
}

int main()
{
	int size;
	int idata;
	bool ans = false;
	tree* root = NULL;
	tree* p = NULL;
	cout << "输入树节点个数：";
	while (cin >> size)
	{
		if (size == -1)break;

		root = creat(root, size, p);

		cout << "输入插入数据：";
		cin >> idata;
		insert(root, idata, p);

		ans = search(root, idata);
		if (!ans)cout << "该数据不存在，查找失败！" << endl;
		else cout << "查找成功！" << endl;

		root = remove(root, idata);
		ans = search(root, idata);
		if (!ans)cout << "该数据不存在，查找失败！" << endl;
		else cout << "查找成功！" << endl;

		cout << "输入树节点个数：";
	}
}