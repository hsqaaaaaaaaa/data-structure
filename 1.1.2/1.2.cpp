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
	L* search(int j);
	int insert(L* l, int j);
	void setdata(int i, L* l);

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
	return head;
}

void L::input()
{
	L* tail = head;
	while (tail->note != NULL)
	{
		cin >> tail->data;
		tail = tail->note;
	}

}

void L::output()
{
	L* tail = head;
	while (tail->note != NULL)
	{
		cout << tail->data << ' ';
		tail = tail->note;
	}
	cout << endl;
}

L* L::search(int j)
{
	L* tail = head;
	while (tail->note != NULL)
	{

		if (j >= tail->data && j <= tail->note->data)return tail;
		tail = tail->note;
	}
	return 0;
}

int L::insert(L* l, int j)
{
	L* q = search(j);
	if (q == NULL)return 0;
	l->note = q->note;
	q->note = l;
	return 1;
}

void L::setdata(int i, L* l)
{
	if (i <= 0)return;
	if (l == NULL)return;
	else l->data = i;
}

int main()
{

	L list;
	L* ex;
	ex = new L;

	int size, target;
	cin >> size;

	while (size != -1)
	{
		list.creat(size);
		list.input();
		list.output();

		cin >> target;

		int num =list.insert(ex, target);
		list.setdata(target, ex);
		list.output();

		cin >> size;
	}


}