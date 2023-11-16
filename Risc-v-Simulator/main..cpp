
#include"Ls_instructions.h"

int main() {


	Memory& mem = Memory::getinstance();
	vector<string> inst = { "1","2","3","4" };
	Memory::getinstance().program_loc("5200", inst);
	LS_instructions x;
	RegisterFile::write("t4", "7220");
	Memory::write("7200", "-276");
	cout << Memory::read("7200") << endl;

	x.loadb("t5", "-20", "t4");
	
   cout << RegisterFile::read("t5");



	

	
}