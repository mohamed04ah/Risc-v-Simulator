#include "Memory.h"

Memory& Memory::getinstance()
{
	static Memory Mem; 
	
	return Mem;
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
	for (auto& it : memory)
	{
		cout << it.first << "|" << it.second << endl;
	}
}


