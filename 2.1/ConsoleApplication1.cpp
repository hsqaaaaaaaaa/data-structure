#include<iostream>
using namespace std;

class L
{
	int data;
public:
	L* node;
	void input()
	{
		cin >> data;
	}
	void output()
	{
		cout << data << ' ';
	}
};

int main()
{
	int size;
	cin >> size;
	while (size != -1)
	{
		L* head = new L;
		L* p, * tail;
		p = tail = head;

		for (int i = 0; i < size; i++)
		{	
			p->input();
			p->output();
			p = new L;
			tail->node = p;
			tail = p;
		}
		cout << endl;

		L* l, * q;
		l = NULL;
		p = head;
		for (int i = 0; i < size; i++)
		{
			q = p->node;
			p->node = l;
			l = p;
			p = q;
		}

		while (l != NULL)
		{
			l->output();
			l = l->node;
		}
		cout << endl;
	}

}