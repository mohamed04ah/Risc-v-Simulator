#include "read.h"

void read::RemoveSpaces(string& s, string& instruction) {
	string temp = ""; int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
		}
		else if (!c) {
			instruction = temp;
			c++;
		}
	}
	s = temp;
}

bool read::col(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ':') {
			return 1;
		}
	}
	return 0;
}

int read::commaNum(string s) {
	int c;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			if (s[i - 1] == ',') {
				return -1;
			}
			c++;
		}
	}
	return c;
}

void read::get_instruction(string& s, string& instruction) {
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
			s[i] = ' ';
		}
		else {
			instruction = temp;
			return;
		}
	}
	s = temp;
}

void read::RemoveSpaces(string& s) {
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
		}
	}
	s = temp;
}

bool read::only_dst(string s, string& dest) {
	dest = s;
}

void read::dest_rs1(string s, string& dest, string& rs1) {
	dest = s.substr(0, s.find(','));
	rs1 = s.substr(s.find(',') + 1, s.length() - s.find(',') + 1);
}

void read::dest_rs2(string s, string& dest, string& rs1, string& rs2){
	dest = s.substr(0, s.find(','));
	rs1 = s.substr(s.find(',') + 1, s.find(',', s.find(',') + 1));
	rs2 = s.substr(s.find(',', s.find(',') + 1) + 1, s.length() - s.find(',', s.find(',') + 1));
}

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

	for (int i = 0;i < instructions.size();i++)
	{
		cout << instructions[i] << endl;
	}
	cout << initial_loc << endl;

	Mem.program_loc(to_string(initial_loc), instructions);
}

void read::dividel(string& s, string& inst, string& dest, string& rs1, string& rs2) {
	RemoveSpaces(s, inst);
	int comnum = commaNum(s);
	bool colb = col(s);
	if (colb) {
		string loop = s.substr(0, s.find(':'));
		s = s.substr(s.find(':') + 1, s.length() - s.find(':') + 1);
	}

	else if (comnum == 1) {
		dest_rs1(s, dest, rs1);
	}

	else if (comnum == 2) {
		dest_rs2(s, dest, rs1, rs2);
	}

	else {
		cout << "invalid input" << endl;
	}
}
