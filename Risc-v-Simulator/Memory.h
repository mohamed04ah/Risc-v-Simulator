#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<bitset>
using namespace std; 


class Memory
{
	// leaves the string as it is. 
public: 
	static  Memory& getinstance();
	//stores the program instructions in the memory (not functional yet)
	bool program_loc(string initial_loc,vector<string>intstructions);
	static bool write(string address, vector<string>values) { return getinstance().Iwrite(address, values); }
	static bool write(string address, string value) { return getinstance().Iwrite(address, value); }
	static  string read(string address) { return getinstance().Iread(address); }
	static void print_memory() {
		getinstance().Iprint_memory();
	}
	vector<string>read_instruction(string adress);
private: 
	string Initial_loc;
	int counter = 0; 
	map<int, string> memory;
	map<string, string>label_map;
	vector<string> instruction_bounds;
	Memory() {};
	Memory(const Memory&) = delete;
	bool Iwrite(string address, vector<string>values);
	bool Iwrite(string address, string value);
	string Iread(string address);
	void Iprint_memory();
	


	
	

};

