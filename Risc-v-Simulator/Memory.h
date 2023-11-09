#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std; 


class Memory
{
public: 
	static  Memory& getinstance();
	//stores the program instructions in the memory (not functional yet)
	bool program_loc(string initial_loc,string inst);
	static bool write(string address, vector<string>values) { return getinstance().Iwrite(address, values); }
	static  string read(string address) { return getinstance().Iread(address); }
	void print_memory();
private: 
	
	int counter = 1; 
	int no_inst = 0;
	string Initial_loc="0";
	map<int, string> memory;
	Memory() {};
	Memory(const Memory&) = delete;
	
	bool Iwrite(string address, vector<string>values);
	string Iread(string address);

	
	

};

