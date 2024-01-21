//时间复杂度：O（n）

#include<iostream>
#include<fstream>

using namespace std;

class L
{
	int data;
	L* note;
	L* head;

public:
	L();
	~L();

	L* creat(int size);
	void input();
	void output();
	L* search();
	void remove();

	friend ostream& operator<<(ostream&out, L&l)
	{
		out << l.data;
		return out;
	}
	friend istream& operator>>(istream&in, L&l)
	{
		in >> l.data;
		return in;
	}
};

L::L()
{
	head = NULL;
	note = NULL;
	data = 0;
}

L::~L()
{
	delete note;
}


L* L::creat(int size)
{
	L* p, * tail;
	head = new L;
	tail = head;
	for (int i = 0; i < size; i++)
	{
		p = new L;
		tail->note = p;
		tail = p;
	}
	tail->note = head;
	return head;
}

void L::input()
{
	L* tail = head;
	while (tail->note != head)
	{
		cin >> tail->data;
		tail = tail->note;
	}

}

void L::output()
{
	L* tail = head;
	while (tail->note != head)
	{
		cout << tail->data << ' ';
		tail = tail->note;
	}
	cout << endl;
}

L* L::search()
{
	L* tail = head, * p = tail->note;
	while (tail->note != head)
	{
		if (p->data >= tail->data)
		{
			p = tail;
		}
		tail = tail->note;
	}
	return p;
}

void L::remove()
{
	L* q = search();
	if (q == NULL)return;
	if (q == head)head = q->note;
	L* p = head;
	while (p->note != head)
	{
		if (p->note->data == q->data)
		{
			p->note = q->note;
			break;
		}
		p = p->note;
	}
}

int main()
{

	L list;

	int size, target;
	cin >> size;

	while (size != -1)
	{
		list.creat(size);
		list.input();
		list.output();


		list.remove();
		list.output();

		cin >> size;
	}

}