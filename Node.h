#pragma once
#include<iostream>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

using namespace std;
class Node
{
	string name;
	Node* father;
	Node* mother;

	Node();
	void setData(string, char);

};