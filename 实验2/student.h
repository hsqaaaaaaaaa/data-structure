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
		cout << "姓名：";
		in >> s.name;
		cout << "学号：";
		in >> s.number;
		cout << "出生日期：";
		in >> s.date;
		cout << "年龄：";
		in >> s.age;
		cout << "性别：";
		in >> s.sex;
		cout << "地址名：";
		in >> s.addressname;
		cout << "地址坐标：";
		in >> s.xaddresscode >> s.yaddresscode;
		cout << "电话号码：";
		in >> s.phonenumber;
		
		return in;
	}
	friend ostream& operator << (ostream & out, student & s)
	{
		out << "姓名：" << s.name << endl;
		out << "学号：" << s.number << endl;
		out << "出生日期：" << s.date << endl;
		out << "年龄：" << s.age << endl;
		out << "性别：" << s.sex << endl;
		out << "地址名：" << s.addressname << endl;
		out << "地址坐标：" << '(' << s.xaddresscode << ',' << s.yaddresscode << ')' << endl;
		out << "电话号码：" << s.phonenumber << endl;
		return out;
	}
	friend ifstream& operator >>(ifstream& infile, student& s)
	{
		infile >> s.name >> s.number >> s.date >> s.age >> s.sex >> s.addressname >> s.xaddresscode >> s.yaddresscode >> s.phonenumber;
		return infile;
	}
	friend ofstream& operator << (ofstream& outfile, student& s)
	{
		outfile << "姓名：" << s.name << endl;
		outfile << "学号：" << s.number << endl;
		outfile << "出生日期：" << s.date << endl;
		outfile << "年龄：" << s.age << endl;
		outfile << "性别：" << s.sex << endl;
		outfile << "地址名：" << s.addressname << endl;
		outfile << "地址坐标：" <<  '(' << s.xaddresscode << ',' << s.yaddresscode << ')' << endl;
		outfile << "电话号码：" << s.phonenumber << endl;
		return outfile;
	}
};
