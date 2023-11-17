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
	void read_instructions();
	void dest_rs1(string s, string& dest, string& rs1);
	void dest_rs2(string s, string& dest, string& rs1, string& rs2);
	bool only_dst(string s, string& dest);
	void RemoveSpaces(string& s);
	void get_instruction(string& s, string& instruction);
	int commaNum(string s);
	bool col(string s);
	void RemoveSpaces(string& s, string& instruction);
	void dividel(string s);
};