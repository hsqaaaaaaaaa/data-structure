#include<iostream>

using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;
	bool choice = true;

	tree(int d)
	{
		left = right = NULL;
		data = d;
	}
};

tree* creat()
{
	int data;
	cin >> data;
	tree* t = new tree(data);
	if (data == 0)return NULL;
	t->left = creat();
	t->right = creat();
	return t;
}

bool find(tree* t)
{
	if (t == NULL)return true;

	if (t->left != NULL && t->left->data > t->data)return false;
	if (t->right != NULL && t->right->data < t->data)return false;
	t->choice = find(t->left);
	t->choice = find(t->right);

}

bool search(tree* t)
{
	if (t == NULL)return true;

	if (t->left != NULL && t->left->choice == false )return false;
	else if(t->right != NULL && t->right->choice == false) return false;
	t->choice = search(t->left);
	t->choice = search(t->right);
	
}

int main()
{
	int count;
	cout << "请输入树的个数：";
	while (cin >> count)
	{
		if (count == -1)break;
		while (count)
		{
			cout << "请输入树的存储数据：";
			tree* root = creat();
			bool ans = find(root);
			search(root);
			if (ans == false)cout << "该树不是二叉查找树！" << endl;
			else cout << "该树是二叉查找树！" << endl;
			--count;
		}
		cout << "请输入树的个数：";
	}

}