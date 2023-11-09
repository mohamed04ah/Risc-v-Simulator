#include"RegisterFile.h"
#include"Memory.h"
#include<vector>

int main() {

	vector<string> test = { "string1","string2","19" };
	RegisterFile& rf=RegisterFile::getinstance();
	Memory& mem = Memory::getinstance();
	mem.write("4000", test);
	mem.print_memory();
	rf.write("t0", mem.read("4002"));
	cout << rf.read("t0");
	//essentially a lw operation


}