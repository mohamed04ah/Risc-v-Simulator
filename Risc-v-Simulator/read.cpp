#include "read.h"

read::read()
{
	read_instructions();
	
}

void read::read_instructions()
{
	Memory& Mem = Memory::getinstance();
	int counter = 0;
	int location = 0;
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
				location = initial_loc;
			}
			else 
			{
				if (find_col(line))
				{
					Memory::label_set(line.substr(0, line.find(':')), to_string(location));
					
				}
				instructions.push_back(line);
				location+=4;
				no_inst++;
			}
		}
	}

	
	Mem.program_loc(to_string(initial_loc), instructions);
}



bool read::find_col(string s)
{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ':') {
				return 1;
			}
		}
		return 0;
}

void read::identify_inst(int pc)
{
	vector<string> breakdown;

	string inst= removespaces(Memory::read(to_string(pc)));
	if (inst == "EBREAK" || inst == "FENCE" || inst == "ECALL") {
		breakdown.push_back("-1");
		return;
	}
	int comnum = commaNum(inst);
	string action;
	int tag = find_col(inst);
	if (tag) 
	{
	
		int temp = inst.find(':');
		temp += 1;
	
		string search = inst.substr(temp, inst.find(','));
		int n1, n2, n3, n4, n5;
		n1 = search.find('s'); n2 = search.find('a'); n3 = search.find('z'); n4 = search.find('t'), n5 = search.find('r');
		if (n1 == -1)
			n1 = 100000;
		if (n2 == -1)
			n2 = 100000;
		if (n3 == -1)
			n3 = 100000;
		if (n4 == -1)
			n4 = 10000;
		if (n5 == -1)
			n5 = 10000;
		int N=min(n5,min(min(n1, n2),min(n3, n4)));
		action = search.substr(0, N);
	}
	else
	{
		
		string search = inst.substr(0, inst.find(','));
	
		int n1, n2, n3, n4, n5;
		n1 = search.find('s'); n2 = search.find('a'); n3 = search.find('z'); n4 = search.find('t'); n5 = search.find('r');
		
		if (n1 == -1) 
			n1 = 100000;
		if (n2 == -1)
			n2 = 100000;
		if (n3  == -1)
			n3 = 100000;
		if (n4  == -1)
			n4 = 10000;
		if (n5 == -1)
			n5 = 10000;
		int N = min(n5, min(min(n1, n2), min(n3, n4)));
		
		action = search.substr(0, N);
		
	}
	
	
	
	if (comnum == 1) 
	{
		comma_1(inst, action, tag,breakdown);
	}
	if (comnum == 2) 
	{
		comma_2(inst, action, tag, breakdown);
	}

}
void read::comma_1(string s,string action,int tag,vector<string>&breakdown)
{
	
	if (tag) 
	{
		
		s.erase(0,s.find(':')+1);
	}
	
		int comma_loc = s.find(',');
		
	
		s.erase(0, action.size() );
		
		string r1 = s.substr(0,s.find(','));
		breakdown.push_back(r1);
		s.erase(s.find(r1), s.find(',')+1);
		string offset = s.substr(0, s.find('('));
		
		breakdown.push_back(offset);
		s.erase(s.find(offset), s.find('(')+1);
		
		string r2 = s.substr(0, s.find(')'));
		breakdown.push_back(r2);
			
	
}
void read::comma_2(string s, string action, int tag, vector<string>& breakdown) 
{
	if (tag)
	{

		s.erase(0, s.find(':') + 1);
	}
	
	s.erase(0, action.size());
	string e1 = s.substr(0, s.find(','));
	breakdown.push_back(e1);
	s.erase(s.find(e1), s.find(',') + 1);
	string e2 = s.substr(0,s.find(','));
	breakdown.push_back(e2);
	s.erase(0, s.find(',')+1);
	breakdown.push_back(s);

	cout << e1 << endl << e2 << endl << s << endl;



}
string read::removespaces(string s)
{
	string temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] !=' ') {
				temp += s[i];
			}
		}
		
		return temp;
	
}
int read::commaNum(string s) 
{
	int c = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',') 
		{
			if (s[i - 1] == ',') 
			{
				return -1;
			}
			c++;
		}
	}
	return c;
}



