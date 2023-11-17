#pragma once
#include<iostream>
#include<fstream>
#include<string> 
#include<sstream>
#include"Memory.h"
using namespace std;
class read
{
public: 
	read();
	void read_instructions();
	bool find_col(string s);
	void identify_inst(int pc);
	string removespaces(string  s);
	int commaNum(string s);
	void comma_1(string s,string action,int tag,vector<string>&breakdown);
	void comma_2(string s, string action, int tag, vector<string>& breakdown);
private: 
	int initial_loc = 0;
	int no_inst = 0;
};

