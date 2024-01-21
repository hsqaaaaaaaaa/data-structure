#include<iostream>
using namespace std;

struct L
{
	int data;
	L* note;
	L(int x) { data = x; }
};

L* creat(int size)
{
	L* l = NULL;
	int x;
	if (size == 0)return NULL;
	else
	{
		cin >> x;
		l = new L(x);
		l->note = creat(size-1);
		return l;
	}
}

void out(L* l)
{
	if (l != NULL)
	{
		cout << l->data << ' ';
		out(l->note);
	}
}

L* reverse(L* l)
{
	if (l->note == NULL)
	{
		return l;
	}
	L* p = reverse(l->note);
	l->note->note = l;
	l->note = NULL;
	return p;
}

int main()
{
	int size, x;
	L* k = NULL;
	L* q = NULL;
	

	cin >> size;
	k = creat(size);
	out(k);
	cout << endl;
	q=reverse(k);
	out(q);
}