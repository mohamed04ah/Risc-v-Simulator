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
	static  Memory& getinstance(); // returns an instance of the current memory 
	bool program_loc(string initial_loc,vector<string>intstructions);
	static bool write(string address, vector<string>values) { return getinstance().Iwrite(address, values); }
	static bool write(string address, string value) { return getinstance().Iwrite(address, value); }
	static bool write1(string address, string value) { return getinstance().Iwrite1(address, value); }
	static  string read(string address) { return getinstance().Iread(address); }
	static void print_memory() {
		getinstance().Iprint_memory();
	}

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
	bool Iwrite1(string address, string value);
	string Iread(string address);
	void Iprint_memory();
	


	
	

};

