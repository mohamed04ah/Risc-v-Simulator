#include "Memory.h"
#include<sstream>
#include<iomanip>
Memory& Memory::getinstance()
{
	static Memory Mem; 
	
	return Mem;
} 
string decimal_hexa1(string value)
{
	int n = stoi(value);
	stringstream hex_val;
	hex_val << hex << n;
	return hex_val.str();
}
int bin_decimal(string value)
{

	if (value[0] == '1')
	{
		int r1;
		r1 = bitset<32>(value).to_ullong();

		r1 = -((1 << value.length()) - r1);
		return r1 + 1;
	}
	else
	{
		int result = 0;
		for (int i = value.size(); i >= 0; i--)
		{
			if (value[i] == '1') {

				result += pow(2, value.size() - i - 1);

			}
		}
		return result;
	}

	return 0;
}
bool Memory::program_loc(string initial_loc, vector<string>instructions)
{
	Initial_loc = initial_loc;
		
		int temp = stoi(initial_loc);
		for (int i = 0; i < instructions.size(); i++)
		{
			memory[temp] = instructions[i];
			temp += 4;
		}

		instruction_bounds.push_back(initial_loc);
		instruction_bounds.push_back(to_string(temp));
		counter = 1;
	
		return true;
}



bool Memory::Iwrite(string address, vector<string> values)
{

	int temp = stoi(address);
	
	if (counter == 1 && (temp>stoi(instruction_bounds[1] )|| temp< stoi(instruction_bounds[0]) ) )
	{
		
		for (int i = 0; i < values.size(); i++)
		{
			memory[temp] = bitset<32>(stoi(values[i])).to_string();
			temp++;
		}
		return true;
	}
	else {
		cout << "Invalid write location!" << endl;
	}
	
	return false; 
}

bool Memory::Iwrite(string address, string value)
{
	int temp = stoi(address);
	if (counter == 1 && (temp > stoi(instruction_bounds[1]) || temp < stoi(instruction_bounds[0])))
	{
		int temp = stoi(address);
		memory[temp] = bitset<32>(stoi(value)).to_string();
		return true;
	}
	else {
		cout << "Invalid write location!" << endl;
	}

	return false;
}

bool Memory::Iwrite1(string address, string value)
{
	int temp = stoi(address);
	if (counter == 1 && (temp > stoi(instruction_bounds[1]) || temp < stoi(instruction_bounds[0])))
	{
		int temp = stoi(address);
		memory[temp] = value;
		return true;
	}
	else {
		cout << "Invalid write location!" << endl;
	}

	return false;
}

void Memory::Iprint_labels()
{
	for (auto& it : label_map)
	{
		cout << it.first << "|" << it.second << endl;
	}
}

string Memory::Iread(string address)
{
	auto it=memory.find(stoi(address));
	if (it == memory.end()) {
		return"";
	}
	else
	{

		return it->second;
	}
	return"";
}

void Memory::Iprint_memory()
{
	/*for (auto& it : memory)
	{
		cout << it.first << "|" << it.second << "(" endl;
	}*/
	for (auto& it : memory) {
		int val = bin_decimal(it.second);
		cout << it.first << "|" << setw(3) << it.second << "(" << val << ")" << "(" << decimal_hexa1(to_string(val)) << ")" << endl;
	}
}


