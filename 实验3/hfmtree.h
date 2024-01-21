#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include <bitset>  
#include"hfmnode.h"
#include"heap.h"
using namespace std;

class hfmtree
{
public:
	hfmnode* root = NULL;
	hfmnode* head = NULL;
	void deletehfm();
	void deletehfmtree(hfmnode* t);
	void creathfmtree(int n);
	void merge(hfmnode* leftchild, hfmnode* rightchild, hfmnode* &parent);
	void HFMtreecode(string s);
	void hfmtreecode(hfmnode* root, string s);
	void save_to_hfmtree(int n);
	void Print(ofstream& outfile);
	void print(hfmnode* root, ofstream& outfile);
	void encoding(string filein,string fileout);
	void Code(hfmnode* p, ofstream& outfile, char s,int notice);
	void decoding(string filein,string fileout);
	void decode(hfmnode* p, string str, ofstream& outfile, int& note);
	void show(string filein, string fileout);
	long long ststistic(string filename);
	void generateCodes(hfmnode* root, string code, map<char, string>& codeMap);
	long long compress(string filein, string fileout);
	void Output(string filename);
	void output(hfmnode* p, string str, ostream& out);
	bool compressionrate(const char* filein, const char* fileout);
};

//��������Ŀռ��ͷ���㺯��
void hfmtree::deletehfm()
{
	deletehfmtree(root);
	deletehfmtree(head);
}
//��������Ŀռ��ͷ��ڲ㺯��
void hfmtree::deletehfmtree(hfmnode*t)
{
	if (t != NULL)
	{
		deletehfmtree(t->left);
		deletehfmtree(t->right);
		delete t;
	}
}

//���������ϲ���������
void hfmtree::merge(hfmnode* left, hfmnode* right, hfmnode*& parent)
{
	parent = new hfmnode;
	parent->left = left;
	parent->right = right;
	parent->weight = left->weight + right->weight;
	left->parent = right->parent = parent;
}

//�½�һ�ù�������
void hfmtree::creathfmtree(int n)
{
	hfmnode* parent = NULL;
	MinHeap<hfmnode>hp(300);

	for (int i = 0; i < n; i++)
	{
		hfmnode* node = new hfmnode;
		cin >> node->c >> node->weight;
		if (node->c == '@')node->c = ' ';
		node->parent = node;
		hp.Insert(*node);
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		hfmnode* first = new hfmnode;
		hfmnode* second = new hfmnode;
		hp.RemoveMin(*first);
		hp.RemoveMin(*second);
		merge(first, second, parent);
		hp.Insert(*parent);
	}
	root = parent;
}

//�������������б�����㺯��
void hfmtree::HFMtreecode(string s)
{
	if (root != NULL)hfmtreecode(root, s);
	if (head != NULL)hfmtreecode(head, s);
}
//�������������б����ڲ㺯��
void hfmtree::hfmtreecode(hfmnode* root, string s)
{
	if (root == NULL) return;

	root->code = s;
	hfmtreecode(root->left, s + "0");
	hfmtreecode(root->right, s + "1");
	
}

//��ӡ����������㺯��
void hfmtree::Print(ofstream& outfile)
{
	if (root != NULL)print(root, outfile);
	if (head != NULL)print(head, outfile);
}
//��ӡ���������ڲ㺯��
void hfmtree::print(hfmnode* root,ofstream&outfile)
{
	if (root == NULL)return;

	
	print(root->left, outfile);
	print(root->right, outfile);
	if (root->left == NULL && root->right == NULL)outfile << "character:" << root->c << "\tweight:" << root->weight << "\tcode:" << root->code << "\tleftcild:" << root->left << "\trightchild:" << root->right << "\tparent:" << root->parent << endl;
}

//���������������ڶ�Ӧ�ļ���
void hfmtree::save_to_hfmtree(int n)
{
	ofstream outfile("hfmTree.txt", ios::out);
	if (!outfile)
	{
		cout << "Open Error!" << endl;
		exit(1);
	}

	Print(outfile);

	outfile.close();
}

//�ù���õĹ���������ָ���ļ��е����ݽ��б������
void hfmtree::encoding(string filein,string fileout)
{
	ifstream infile(filein, ios::in);
	ofstream outfile(fileout, ios::out);
	if (!infile)
	{
		cout << "Infile Open Error!" << endl;
		exit(1);
	}
	if (!outfile)
	{
		cout << "Outfile Open Error!" << endl;
		exit(1);
	}

	char s;
	hfmnode* p = NULL;
	int choice;
	if (root != NULL)
	{
		p = root;
		choice = 0;
	}
	if (head != NULL)
	{
		p = head;
		choice = 1;
	}
	while (infile.peek() != EOF)
	{
		infile.get(s);
		Code(p, outfile, s, choice);
	}
	infile.close();
	outfile.close();
}
//�ù���õĹ���������ָ���ļ��е����ݽ��б����ڲ�
void hfmtree::Code(hfmnode* p, ofstream& outfile, char s, int notice)
{
	
	if (p == NULL)return;
	if (notice == 0) if (s == '@')s = ' ';
	if (p->c == s)
	{
		outfile << p->code;
		return;
	}
	Code(p->left, outfile, s, notice);
	Code(p->right, outfile, s, notice);
	
}

//�ù���õĹ���������ָ���ļ��е����ݽ����������
void hfmtree::decoding(string filein, string fileout)
{
	ifstream infile(filein, ios::in);
	ofstream outfile(fileout, ios::out);
	if (!infile)
	{
		cout << "Infile Open Error!" << endl;
		exit(1);
	}
	if (!outfile)
	{
		cout << "Outfile Open Error!" << endl;
		exit(1);
	}

	string code = "";
	char c;
	hfmnode* p = NULL;
	if (root != NULL)p = root;
	if (head != NULL)p = head;
	while (infile.peek()!=EOF)
	{
		int note = 0;
		infile >> c;
		code += c;
		decode(p, code, outfile,note);
		if (note == 1)code = "";
	}
	
	infile.close();
	outfile.close();
}
//�ù���õĹ���������ָ���ļ��е����ݽ��������ڲ�
void hfmtree::decode(hfmnode*p,string str,ofstream&outfile,int &note)
{
		if (p == NULL || note == 1)return;

		if (p->code == str && p->c != '^')
		{
			outfile << p->c << flush;
			note = 1;
			return;
		}
		decode(p->left, str, outfile, note);
		decode(p->right, str, outfile, note);
	
	
}

//��������ڶ�Ӧ�ļ��еı�����
void hfmtree::show(string filein, string fileout)
{
	ifstream infile(filein, ios::in);
	ofstream outfile(fileout, ios::out);
	if (!infile)
	{
		cout << "Infile Open Error!" << endl;
		exit(1);
	}
	if (!outfile)
	{
		cout << "Outfile Open Error!" << endl;
		exit(1);
	}

	string str;
	infile >> str;
	cout << str << endl;
	outfile << str;

	infile.close();
	outfile.close();
}

//ͳ�������г��ֵ��ַ��������������һ���¹�������
long long hfmtree::ststistic(string filename)
{
	ifstream infile(filename, ios::in);
	if (!infile)
	{
		cout << "Infile Open Error!" << endl;
		exit(1);
	}

	hfmnode* parent = NULL;
	MinHeap<hfmnode> HP(300);
	long long sum = 0;

	vector<long long>total(256, 0); // Assuming ASCII characters.  

	while (infile.peek() != EOF) 
	{
		char s;
		infile.get(s);
		if (static_cast<unsigned char>(s) < total.size()) {
			total[static_cast<unsigned char>(s)] += 1;
		}
	}

	for (long long i = 0; i < total.size(); i++)
	{
		if (total[i] != 0) {
			cout << char(i) << "->" << total[i] << endl;
			hfmnode* node = new hfmnode;
			node->c = char(i);
			node->weight = total[i];
			node->parent = node;
			HP.Insert(*node);
			sum++;
		}
	}

	for (long long i = 0; i < sum - 1; i++)
	{
		hfmnode* first = new hfmnode;
		hfmnode* second = new hfmnode;
		HP.RemoveMin(*first);
		HP.RemoveMin(*second);
		merge(first, second, parent);
		HP.Insert(*parent);
	}
	head = parent;
	infile.close();
	return sum;
}

//����ӳ��
void hfmtree::generateCodes(hfmnode* node, string code, map<char, string>& codeMap)
{
	if (node == NULL)
	{
		return;
	}
	codeMap[node->c] = code;
	// ��Ҷ�ڵ㣬�ݹ��������������ı���ӳ��    
	generateCodes(node->left, code + "0", codeMap);
	generateCodes(node->right, code + "1", codeMap);
}
// ѹ������ 
long long hfmtree::compress(string filein, string fileout)

{

	ifstream infile(filein, ios::in);
	ofstream outfile(fileout, ios::binary | ios::out);

	if (!infile)
	{
		cout << "Infile Open Error!" << endl;
		exit(1);
	}

	if (!outfile)
	{
		cout << "Outfile Open Error!" << endl;
		exit(1);
	}

	char ch;
	unsigned char cd = 0;
	int count = 0;
	int num_code = 0;
	vector<unsigned char> compressedData;

	// ���ɱ���ӳ��    
	map<char, string> codeMap;
	if (root != NULL)generateCodes(root, "", codeMap);
	if (head != NULL)generateCodes(head, "", codeMap);

	while (infile.get(ch))
	{
		cd <<= 1;
		if (ch == '1')
			cd |= 1;
		count++;
		if (count == 8)//�������8λ
		{
			compressedData.push_back(cd);
			cd = 0;
			count = 0;
			num_code++;
		}
	}
		if (count != 0)//û����8λ�ж�
		{
			//remain = 8 - count_8;
			cd = cd << (8 - count);
			num_code++;
			compressedData.push_back(cd);
		}
	
		for (int i = 0; i < compressedData.size(); i++)
		{
			unsigned char temp = compressedData[i];
			outfile.write((char*)&temp, sizeof(temp));
		}

	infile.close();
	outfile.close();

	return 0; // �������ʵ��ķ���ֵ    

}

void hfmtree::Output(string filename)
{
	ofstream outfile(filename, ios::out);
	if (!outfile)
	{
		cout << "Outfile Open Error!" << endl;
		exit(1);
	}

	if (root != NULL)output(root, "", cout);
	if (head != NULL)output(head, "", cout);
	if (root != NULL)output(root, "", outfile);
	if (head != NULL)output(head, "", outfile);
}
//���������
void hfmtree::output(hfmnode* t, string str, ostream& out)
{
	if (!t)
	{
		return;
	}
	out << str << t->weight;
	if (t->left != NULL)
	{
		out << "����" << endl;
		if (t->right)
		{
			output(t->left, str + "����", out);
		}
		else
		{
			output(t->left, str + "����", out);
		}
	}
	if (t->right != NULL)
	{
		out << endl
			<< str << "������" << endl;
		output(t->right, str + "����", out);
	}
}

//ͳ������ѹ����
bool hfmtree::compressionrate(const char* filein, const char* fileout)
{
	if (filein == NULL || fileout == NULL)
	{
		cout << "���ļ������ڣ�" << endl;
		return false;
	}
	struct _stat64 in, out;
	_stat64(filein, &in);
	_stat64(fileout, &out);
	cout << "ѹ��ǰ�ļ���С��" << in.st_size << "B" << endl;
	cout << "ѹ�����ļ���С��" << out.st_size << "B" << endl;
	cout << "ѹ���ʣ�" << 100-((double)out.st_size / (double)in.st_size * (double)100) << "%" << endl;
}