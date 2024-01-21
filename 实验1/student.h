//程序名：student.h
//      程序功能：定义学生通讯录模板类的学生结构，重载学生通讯信息的输入输出函数
//          作者：hsq
//          日期：2023.9.26
//          版本：1.0
//      修改内容：无
//      修改日期：无
//      修改作者：无
//
//

#include<iostream>
#include<fstream>

using namespace std;

class student
{
public:
	string name;//姓名
	string number;//学号
	string sex;//性别
	string locationname;//地址名
	string addresscoord;//地址位置
	int y;//年
	int m;//月
	int d;//日

	friend ifstream& operator>>(ifstream& infile, student& s)//重载文件输入流运算符
	{
		infile >> s.name >> s.number >> s.sex >> s.y >> s.m >> s.d >> s.locationname >> s.addresscoord;
		return infile;
	}

	friend ofstream& operator<<(ofstream& outfile, const student& s)//重载文件输出流运算符
	{
		outfile << "姓名：" << s.name << endl;
		outfile << "学号：" << s.number << endl;
		outfile << "性别：" << s.sex << endl;
		outfile << "出生日期：" << s.y << '.' << s.m << '.' << s.d << endl;
		outfile << "地址名：" << s.locationname << endl;
		outfile << "地址位置：" << s.addresscoord << endl;
		return outfile;
	}

	friend istream& operator>>(istream& in, student& s)//重载输入流运算符
	{
		cout << "姓名：";
		in >> s.name;
		cout << "学号：";
		in >> s.number;
		cout << "性别：";
		in >> s.sex;
		cout << "出生日期：";
		in >> s.y >> s.m >> s.d;
		cout << "地址名：";
		in >> s.locationname;
		cout << "地址位置：";
		in >> s.addresscoord;
		cout << endl;
		return in;
	}

	friend ostream& operator<<(ostream& out, const student& s)//重载输出流运算符
	{
		out << "姓名：" << s.name << endl;
		out << "学号：" << s.number << endl;
		out << "性别：" << s.sex << endl;
		out << "出生日期：" << s.y << '.' << s.m << '.' << s.d << endl;
		out << "地址名：" << s.locationname << endl;
		out << "地址位置：" << s.addresscoord << endl;
		return out;
	}

};
