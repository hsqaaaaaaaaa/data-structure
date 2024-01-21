#include<iostream>

using namespace std;

struct tree
{
	int data;
	tree* leftchild;
	tree* rightchild;
};

struct node
{
	int data;
	node* note;
	node* head;
};

void creat(tree* & t)
{
	int value;
	cin >> value;
	
	if (value == 0)
	{
		t = NULL;
	}
	else
	{
		t = new tree;
		t->data = value;
		creat(t->leftchild);
		creat(t->rightchild);
	}	
}

void out(tree* &t)
{
	if (t == NULL)return;
	cout << t->data << ' ';
	out(t->leftchild);
	out(t->rightchild);
	cout << endl;
}

void levelorder(tree* t, node* n)
{
	tree* p = t;
	if (p == NULL)return;
	if (p->leftchild == NULL && p->rightchild == NULL)
	{
		n = new node;
		n->data = p->data;
		cout << n->data << ' ';
	}
	
	if (p->leftchild != NULL)levelorder(p->leftchild, n);
	if (p->rightchild != NULL)levelorder(p->rightchild, n);

}

int main()
{
	tree* p = NULL;
	node* n = NULL;
	int size;
	while (cin >> size)
	{
		if (size == -1)break;
		while (size)
		{
			creat(p);
			//out(p);
			levelorder(p, n);
			size--;
		}
	}
}