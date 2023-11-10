#include "Memory.h"

Memory& Memory::getinstance()
{
	static Memory Mem; 
	
	return Mem;
} 

bool Memory::program_loc(string initial_loc, string inst)
{
	if (counter == 0)
		Initial_loc = initial_loc;
		memory[stoi(initial_loc)] = inst;
	
		counter = 1;
		no_inst++;
		return true;
}

bool Memory::Iwrite(string address, vector<string> values)
{

	int temp = stoi(address);
	
	if (counter == 1)
	{
		//&& (temp > (stoi(Initial_loc) + no_inst))
		for (int i = 0; i < values.size(); i++)
		{
			memory[temp] = values[i];
			temp++;
		}

	}

	
	return true;
}

bool Memory::Iwrite(string address, string value)
{
	int temp = stoi(address);
	memory[temp] = value;
	return true;
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


