#include<iostream>
#include<fstream>

using namespace std;

class student
{
public:
	string name;
	string number;
	string date;
	int age;
	string sex;
	string addressname;
	string phonenumber;
	string xaddresscode;
	string yaddresscode;

	friend istream& operator >>(istream& in, student& s)
	{
		cout << "������";
		in >> s.name;
		cout << "ѧ�ţ�";
		in >> s.number;
		cout << "�������ڣ�";
		in >> s.date;
		cout << "���䣺";
		in >> s.age;
		cout << "�Ա�";
		in >> s.sex;
		cout << "��ַ����";
		in >> s.addressname;
		cout << "��ַ���꣺";
		in >> s.xaddresscode >> s.yaddresscode;
		cout << "�绰���룺";
		in >> s.phonenumber;
		
		return in;
	}
	friend ostream& operator << (ostream & out, student & s)
	{
		out << "������" << s.name << endl;
		out << "ѧ�ţ�" << s.number << endl;
		out << "�������ڣ�" << s.date << endl;
		out << "���䣺" << s.age << endl;
		out << "�Ա�" << s.sex << endl;
		out << "��ַ����" << s.addressname << endl;
		out << "��ַ���꣺" << '(' << s.xaddresscode << ',' << s.yaddresscode << ')' << endl;
		out << "�绰���룺" << s.phonenumber << endl;
		return out;
	}
	friend ifstream& operator >>(ifstream& infile, student& s)
	{
		infile >> s.name >> s.number >> s.date >> s.age >> s.sex >> s.addressname >> s.xaddresscode >> s.yaddresscode >> s.phonenumber;
		return infile;
	}
	friend ofstream& operator << (ofstream& outfile, student& s)
	{
		outfile << "������" << s.name << endl;
		outfile << "ѧ�ţ�" << s.number << endl;
		outfile << "�������ڣ�" << s.date << endl;
		outfile << "���䣺" << s.age << endl;
		outfile << "�Ա�" << s.sex << endl;
		outfile << "��ַ����" << s.addressname << endl;
		outfile << "��ַ���꣺" <<  '(' << s.xaddresscode << ',' << s.yaddresscode << ')' << endl;
		outfile << "�绰���룺" << s.phonenumber << endl;
		return outfile;
	}
};
