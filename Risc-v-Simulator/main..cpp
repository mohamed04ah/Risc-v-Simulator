
#include"Ls_instructions.h"


 string two_comp(string value)
{

	string temp = "";

	for (int i = value.size(); i >= 1; i--)
	{
		if (value[i] == '1') {
			temp += '0';
		}

	}

	reverse(temp.begin(), temp.end());

	temp[temp.size() - 1] = '1';
	return temp;

}

int main() {

	
	vector<string> test = { "string1","string2","19" };
	RegisterFile::write("a0", "13");
	Memory& mem = Memory::getinstance();
    mem.program_loc("4000", test);
	Memory::print_memory();



}