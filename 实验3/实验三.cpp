#include<iostream>
#include<cstring>
#include<fstream>
#include"hfmtree.h"
using namespace std;

int main()
{
	int finish = 0;
	int choice = 0;
	int n;
	int sum;
	int num;
	string s = "";
	string filename, filein, fileout;

	hfmtree hfm;

	while (!finish)
	{
		system("cls");
		cout << "------------哈夫曼树菜单功能-----------" << endl;
		cout << "基础功能：" << endl;
		cout << "1、新建一棵哈夫曼树" << endl;
		cout << "2、对哈夫曼树中的字符进行哈夫曼编码并保存至一文件中" << endl;
		cout << "3、通过新建的哈夫曼树对文件内容进行编码并保存至另一文件中" << endl;
		cout << "4、通过新建的哈夫曼树对文件内容进行译码并保存至另一文件中" << endl;
		cout << "5、将文件内容以紧凑格式显示在屏幕上并将此编码文件保存至另一文件中" << endl;
		cout << "6、打印生成的哈夫曼树并输出到屏幕上" << endl;
		cout << "7、退出" << endl;
		cout << "自定义功能：" << endl;
		cout << "8、统计文章中每个字符的出现个数" << endl;
		cout << "9、根据统计数据生成一棵新哈夫曼树" << endl;
		cout << "10、使用新生成的哈夫曼树进行编码" << endl;
		cout << "11、使用新生成的哈夫曼树进行译码" << endl;
		cout << "12、对指定文件内容进行压缩" << endl;
		cout << "13、统计压缩率" << endl;
		cout << "请选择要进行的操作(1-13)：";
		cin >> choice;

		switch (choice)
		{
		case 1:
			hfm.deletehfm();
			cout << "请输入字符集大小:";
			cin >> n;
			cout << "请输入字符及其权值大小:" << endl;
			hfm.creathfmtree(n);
			cout << "已成功建立哈夫曼树" << endl;
			break;
		case 2:
			hfm.HFMtreecode(s);
			hfm.save_to_hfmtree(n);
			cout << "对字符集编码已完成，并存放于文件hfmTree.txt中。" << endl;
			break;
		case 3:
			hfm.encoding("ToBeTran.txt", "CodeFile.txt");
			cout << "已对ToBeTran.txt中的正文进行编码，并将结果存放于CodeFile.txt中" << endl;
			break;
		case 4:
			hfm.decoding("CodeFile.txt", "TextFile.txt");
			cout << "已对CodeFile.txt中的文本进行译码，并将结果存放于TextFile.txt中" << endl;
			break;
		case 5:
			hfm.show("CodeFile.txt", "CodePrin.txt");
			cout << "已对CodeFile.txt文件完成打印，并将此形式的编码文件写入文件CodePrin.txt中" << endl;
			break;
		case 6:
			hfm.Output("TreePrin.txt");
			cout << "\n已将哈夫曼树打印并保存至文件TreePrin.txt中";
			break;
		case 7:
			hfm.deletehfm();
			cout << "已成功退出！";
			exit(0);
			break;
		case 8:
			hfm.deletehfm();
			cout << "请输入需要统计字符的文件名：" << endl;
			cin >> filename;
			cout << "文章中出现字符统计：" << endl;
			sum = hfm.ststistic(filename);
			//English1.txt
			break;
		case 9:
			hfm.HFMtreecode(s);
			hfm.save_to_hfmtree(sum);
			cout << "已成功使用统计字符数据建立新哈夫曼树,并储存在hfmTree.txt中" << endl;
			break;
		case 10:
			cout << "输入需要进行编码的文件名：" << endl;
			cin >> filein;
			cout << "输入编码储存文件名：" << endl;
			cin >> fileout;
			hfm.encoding(filein, fileout);
			cout << "已对" << filein << "中的正文进行编码，并将结果存放于" << fileout << "中" << endl;
			break;
		case 11:
			cout << "输入需要进行译码的文件名：" << endl;
			cin >> filein;
			cout << "输入译码储存文件名：" << endl;
			cin >> fileout;
			hfm.decoding(filein, fileout);
			cout << "已对" << filein << "中的文本进行译码，并将结果存放于" << fileout << "中" << endl;
			break;
		case 12:
			cout << "输入需要进行压缩的文件名：" << endl;
			cin >> filein;
			cout << "压缩后文件名：" << endl;
			cin >> fileout;
			num = hfm.compress(filein, fileout);
			cout << "已成功压缩文件" << endl;
			break;
		case 13:
			const char* in = filein.c_str();
			const char* out = fileout.c_str();
			hfm.compressionrate(in, out);
			break;
		}
		cout << endl;
		system("pause");
	}
}