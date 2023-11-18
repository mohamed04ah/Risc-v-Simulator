#pragma once
#include<iostream>
#include<fstream>
#include<string> 
#include<sstream>
#include"Memory.h"
#include"LS_instructions.h"
#include"global.h"
using namespace std;
class read
{
public: 
	read();
	read(int n) {};
	void read_instructions();
	void Call_Instructions(int pc);
	bool find_col(string s);
	void identify_inst(string inst,vector<string>& breakdown);
	string removespaces(string  s);
	int commaNum(string s);
	void comma_1(string s,string action,int tag,vector<string>&breakdown);
	void comma_2(string s, string action, int tag, vector<string>& breakdown);
	/*int& get_pc() { return PC; }
	void set_PC(string address) { PC = stoi(address); }*/
	void Print_all() 
	{
		cout << "PC|RegisterFile|Memory" << endl;
		Memory::print_memory();
		cout << endl;
	     RegisterFile::print_RF();
	cout << endl; 
	
	}
private: 
	int initial_loc = 0;
	int no_inst = 0;
      
};

