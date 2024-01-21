//��������student.h
//      �����ܣ�����ѧ��ͨѶ¼ģ�����ѧ���ṹ������ѧ��ͨѶ��Ϣ�������������
//          ���ߣ�hsq
//          ���ڣ�2023.9.26
//          �汾��1.0
//      �޸����ݣ���
//      �޸����ڣ���
//      �޸����ߣ���
//
//

#include<iostream>
#include<fstream>

using namespace std;

class student
{
public:
	string name;//����
	string number;//ѧ��
	string sex;//�Ա�
	string locationname;//��ַ��
	string addresscoord;//��ַλ��
	int y;//��
	int m;//��
	int d;//��

	friend ifstream& operator>>(ifstream& infile, student& s)//�����ļ������������
	{
		infile >> s.name >> s.number >> s.sex >> s.y >> s.m >> s.d >> s.locationname >> s.addresscoord;
		return infile;
	}

	friend ofstream& operator<<(ofstream& outfile, const student& s)//�����ļ�����������
	{
		outfile << "������" << s.name << endl;
		outfile << "ѧ�ţ�" << s.number << endl;
		outfile << "�Ա�" << s.sex << endl;
		outfile << "�������ڣ�" << s.y << '.' << s.m << '.' << s.d << endl;
		outfile << "��ַ����" << s.locationname << endl;
		outfile << "��ַλ�ã�" << s.addresscoord << endl;
		return outfile;
	}

	friend istream& operator>>(istream& in, student& s)//���������������
	{
		cout << "������";
		in >> s.name;
		cout << "ѧ�ţ�";
		in >> s.number;
		cout << "�Ա�";
		in >> s.sex;
		cout << "�������ڣ�";
		in >> s.y >> s.m >> s.d;
		cout << "��ַ����";
		in >> s.locationname;
		cout << "��ַλ�ã�";
		in >> s.addresscoord;
		cout << endl;
		return in;
	}

	friend ostream& operator<<(ostream& out, const student& s)//��������������
	{
		out << "������" << s.name << endl;
		out << "ѧ�ţ�" << s.number << endl;
		out << "�Ա�" << s.sex << endl;
		out << "�������ڣ�" << s.y << '.' << s.m << '.' << s.d << endl;
		out << "��ַ����" << s.locationname << endl;
		out << "��ַλ�ã�" << s.addresscoord << endl;
		return out;
	}

};
