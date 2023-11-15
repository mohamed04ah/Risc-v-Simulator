#include "read.h"

void read::read_instructions()
{
	Memory& Mem = Memory::getinstance();
	int counter = 0;
	int initial_loc = 0;
	string filename = "input.txt"; 
	ifstream inputfile(filename);
	vector<string> instructions;
	if (inputfile.is_open())
	{
	
		string line; 
		string element; 
		while (getline(inputfile, line))
		{
			if (counter == 0) 
			{
				initial_loc = stoi(line);
				counter++;
			}
			else 
			{
				instructions.push_back(line);
			}
		}
	}

	for (int i=0;i<instructions.size();i++)
	{
		cout << instructions[i] << endl;
	}
	cout << initial_loc << endl;

	Mem.program_loc(to_string(initial_loc), instructions);
}
