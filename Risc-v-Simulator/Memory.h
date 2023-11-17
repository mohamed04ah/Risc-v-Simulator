#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<bitset>
using namespace std; 


class Memory
{
	
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
	static void label_set(string label, string address) { getinstance().label_map[label] = address; }
	static void print_lables() { getinstance().Iprint_labels(); }
	static string read_label(string address) { return getinstance().label_map[address]; }
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
	void Iprint_labels();
	


	
	

};

