#include "LS_instructions.h"

LS_instructions::LS_instructions()
{
	

}

bool LS_instructions::Loadw(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);// RegisterFile::getinstance().read(base_reg);
	int memory_address = stoi(offset) + stoi(base_add);
	
	if (RegisterFile::write(rd, Memory::read(to_string(memory_address))))
	{
		
		return true;
	}
	return false;
}

bool LS_instructions::storew(string rs1, string offset, string rs2)
{

	read_reg temp = RegisterFile::read(rs1,rs2);
	string store = temp.r1;
	string address = temp.r2;

	int memory_address = stoi(offset) + stoi(address);
	Memory::write(to_string(memory_address), store);

	return true;
}

bool LS_instructions::loadhw(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int memory_address = stoi(offset) + stoi(base_add);
	string temp = Memory::read(to_string(memory_address));
	string store = "";
	for (int i = 0; i < temp.size() / 2; i++) {
		store += temp[i];
	}
	if (RegisterFile::write(rd, store))
	{

		return true;
	}
	return false;
	
}
