#pragma once
#include<iostream>
using namespace std;
class hfmnode
{
public:
	char c;
	int weight;
	string code;
	hfmnode* left;
	hfmnode* right;
	hfmnode* parent;

	hfmnode()
	{
		c = '^';
		weight = -1;
		code = "";
		left = right = parent = NULL;
	}

	bool operator<(const hfmnode& h)
	{
		return weight < h.weight;
	}
	bool operator<=(const hfmnode& h)
	{
		return weight <= h.weight;
	}
	bool operator>(const hfmnode& h)
	{
		return weight > h.weight;
	}
	bool operator>=(const hfmnode& h)
	{
		return weight >= h.weight;
	}
};
/*
@ 186
A 64
B 13
C 22
D 32
E 103
F 21
G 15
H 47
I 57
J 1
K 5
L 32
M 20
N 57
O 63
P 15
Q 1
R 48
S 51
T 80
U 23
V 8
W 18
X 1
Y 16
Z 1
*/