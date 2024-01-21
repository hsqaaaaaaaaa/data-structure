#include<iostream>
#include<fstream>
#include"tree.h"
#include"student.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
//  主函数
//参数返回值：无

int main()
{
	int finished = 0;
	int choice;
	int  size;
	string number, filename;

	ifstream infile;
	ofstream outfile;

	tree<student> StudentTree;// StudentTree object
	student data;//用于添加或新建的学生类数据

	while (!finished)
	{
		cout << "*********Menu*********\n";
		cout << "1:creat\n";
		cout << "2:insert\n";
		cout << "3:search by number\n";
		cout << "4:search by name\n";
		cout << "5:search by phonenumber\n";
		cout << "6:remove\n";
		cout << "7:display the youngest student\n";
		cout << "8:display students in same row\n";
		cout << "9:display all\n";
		cout << "10:display data from file\n";
		cout << "11:store data into file\n";
		cout << "12:exit\n";
		cout << "Please choose a choice(1-12):";
		cin >> choice;
		switch (choice)
		{
		case 1://新建学生通讯录链表
			cout << "请输入需要录入的学生数量：";
			cin >> size;
			StudentTree.creat(size);
			//StudentTree.Out(size);
			cout << endl << "a new list is created successfully" << endl;
			break;
			
		case 2://调用插入函数
			cout << "\n please enter the data to insert\n";
			StudentTree.insert();  // ok
			//cin >> size;
			//StudentTree.Out(size);
			cout << endl << "data is inserted successfully" << endl;
			break;

		case 3://调用查询函数（按学号）
			cout << "\nThe element wants to be searched:\n";
			cin >> number;
			StudentTree.Search(number);
			break;
			
		case 4://调用查询函数（按姓名）
			cout << "\nThe element wants to be searched:\n";
			cin >> number;
			StudentTree.Search(number);
			break;

		case 5:// 调用查询函数（按电话号码）
			cout << "\nThe element wants to be searched:\n";
			cin >> number;
			StudentTree.Search(number);
			break;
		
		case 6://调用删除函数
			cout << "\nThe element wants to be removed:\n";
			cin >> number;
			StudentTree.Remove(number);
			break;
		
		case 7://调用输出最小年龄学生信息函数
			cout << "\nThe youngest student's information:\n";
			StudentTree.Agemix();
			break;

		case 8://调用找出在同一深度的学生函数
			cout<<"\nThe student's in same row:\n";
			StudentTree.depth();
			break;

		case 9://调用输出函数
			cout << "\nAll student information:\n";
			cout << "前序遍历=0 中序遍历=1 后序遍历=2" << endl;
			cout << "请输入您想要的格式：";
			cin >> size;
			StudentTree.Out(size); //输出全部学生信息
			break;
			
		case 10://调用函数将数据从文件中提取
			cout << "请输入需要提取的文件地址：" << endl;
			cin >> filename;
			//in2.txt
			cout << "输入要导入的学生人数：" << endl;
			cin >> size;
			StudentTree.InFile(infile, filename, size);
			break;
			
		case 11://调用函数将数据存入文件中
			cout << "请输入需要存入的文件地址：" << endl;
			cin >> filename;
			//out2.txt
			StudentTree.OutFile(outfile, filename);
			break;

		case 12:
			exit(-1);//结束程序
			break;
		}  // switch
	} // while 
}// main			   