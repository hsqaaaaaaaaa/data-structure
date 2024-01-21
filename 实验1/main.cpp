//程序名：main.cpp
//      程序功能：主函数 实现整个学生信息管理系统的运行
//          作者：hsq
//          日期：2023.9.26
//          版本：1.2
//      修改内容：无
//      修改日期：无
//      修改作者：无
//
//
#include<iostream>
#include<fstream>
#include"linklist.h"
#include"student.h"
#include <ctime>
#include <windows.h>


using namespace std;



//////////////////////////////////////////////////////////////////////////////
//  主函数
//参数返回值：无

int main()
{
	int finished = 0;
	int choice;
	int  size;
	string number, addresscoord;

	ifstream infile;
	ofstream outfile;

	DWORD begin = 0;
	DWORD end = 0;
	DWORD time = 0;

	cout << "Please enter the size of list:";
	cin >> size;

	linklist<student> StudentList;// StudentList object
	student data;//用于添加或新建的学生类数据

	while (!finished)
	{
		cout << "\n*********Menu*********\n";
		cout << "1:creat\n";
		cout << "2:add\n";
		cout << "3:insert\n";
		cout << "4:remove\n";
		cout << "5:modify\n";
		cout << "6:sort\n";
		cout << "7:search\n";
		cout << "8:display all\n";
		cout << "9:display data from file\n";
		cout << "10:store data into file\n";
		cout << "11:exit\n";
		cout << "Please choose a choice(1-11):";
		cin >> choice;
		switch (choice)
		{
		case 1://新建学生通讯录链表
			begin = GetTickCount();
			

			StudentList.creat();
			end = GetTickCount();

			time = end - begin;

			cout << time << endl;
			cout << endl << "a new list is created successfully" << endl;
			break;
		case 2://调用添加成员函数
			cout << "\nplease enter the element to add:\n";
			StudentList.add(data, size);
			StudentList.Out();
			break;
		case 3://调用插入函数
			cout << "\nplease enter the position(address coordinates) to insert:";
			cin >> addresscoord;
			cout << "\n please enter the data to insert\n";
			if (StudentList.insert(addresscoord, data) == 1)  // ok
				StudentList.Out();
			break;
		case 4://调用删除函数
			cout << "\nplease enter the position(student number) to remove:"; 
			cin >> number;
			if (StudentList.remove(number) == 1)
				StudentList.Out(); //ok
			break;
		case 5:  //调用修改函数
			cout << "\nThe element(student number) wants to be modified:\n";
			cin >> number;
			cout << "\nThe element in list Before modify:\n";
			StudentList.Out(); //调用输出函数 
			cout << "\nThe element in list After modify:\n";
			StudentList.modify(number);
			StudentList.Out(); //调用输出函数 
			break;
		case 6://调用排序函数
			cout << "\nSort by student number:\n";
			StudentList.sort(data);
			StudentList.Out(); //调用输出函数 
			break;
		case 7://调用查询函数
			cout << "\nThe element(student number) wants to be searched:\n";
			cin >> number;
			StudentList.search(number);
			break;
		case 8://调用输出函数
			cout << "\nAll student information:\n";
			StudentList.Out(); //输出全部学生信息
			break;
		case 9://调用函数取出在文件中的数据
			StudentList.Infile(infile, "in.txt", size, data);
			cout << "successfully!" << endl;
			break;
		case 10://调用函数将数据存入文件中
			StudentList.Outfile(outfile, "out.txt");
			break;
		case 11:
			exit(-1);//结束程序
			break;
		}  // switch
	} // while 
}// main			   
