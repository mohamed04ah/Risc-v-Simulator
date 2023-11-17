#include "LS_instructions.h"

LS_instructions::LS_instructions()
{
	

}
int Bintoint(string value) {
	
	int result = 0;

	for (int i = value.size(); i >= 0; i--) {
		if (value[i] == '1') {

			result += pow(2, value.size() - i - 1);

		}
	}
	return result;

	
}
bool LS_instructions::Loadw(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int temp = Bintoint(base_add);
	int memory_address = stoi(offset) + temp;
	string data = Memory::read(to_string(memory_address));


	
	if (RegisterFile::write1(rd, data))
	{
		
		return true;
	}
	return false;
}

bool LS_instructions::storew(string rs1, string offset, string rs2)
{
	read_reg R;
	R=RegisterFile::read(rs1, rs2);
	string source = R.r1;
	string address = R.r2;
	int location = stoi(offset) + Bintoint(address);

	if (Memory::write1(to_string(location), R.r1))
		return true;
	return false; 
}

bool LS_instructions::loadhw(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int temp = Bintoint(base_add);
	int memory_address = stoi(offset) + temp;
	string data = Memory::read(to_string(memory_address));
	int sign = data[0] == '1' ? 1 : 0;
	string store = "";
	
	for (int i = 31; i > 15; i--)
	{
		store += data[i];
		
	}
	
	reverse(store.begin(), store.end());
	string t1 = "";
	if (sign)
	{
		
		for (int i = 0; i < 16; i++)
		{
			t1 += '1';
			
		}
		
	}
	else
	{
		
		for (int i = 0; i < 16; i++)
		{
			t1 += '0';
			
		}

	}
	
	t1 += store;
	
	if (RegisterFile::write1(rd, t1))
		return true;

	return false;
}

bool LS_instructions::loadhw_u(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int temp = Bintoint(base_add);
	int memory_address = stoi(offset) + temp;
	string data = Memory::read(to_string(memory_address));
	int sign = data[0] == '1' ? 1 : 0;
	string store = "";

	for (int i = 31; i > 15; i--)
	{
		store += data[i];

	}

	reverse(store.begin(), store.end());
	string t1 = "";
	

		for (int i = 0; i < 16; i++)
		{
			t1 += '0';

		}

	t1 += store;

	if (RegisterFile::write1(rd, t1))
		return true;

	return false;
}

bool LS_instructions::loadb(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int temp = Bintoint(base_add);
	int memory_address = stoi(offset) + temp;
	string data = Memory::read(to_string(memory_address));
	int sign = data[0] == '1' ? 1 : 0;
	string store = "";

	for (int i = 31; i > 23; i--)
	{
		store += data[i];

	}

	reverse(store.begin(), store.end());
	string t1 = "";
	if (sign)
	{

		for (int i = 0; i < 24; i++)
		{
			t1 += '1';

		}

	}
	else
	{

		for (int i = 0; i < 24; i++)
		{
			t1 += '0';

		}

	}

	t1 += store;

	if (RegisterFile::write1(rd, t1))
		return true;

	return false;
}

bool LS_instructions::loadb_u(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int temp = Bintoint(base_add);
	int memory_address = stoi(offset) + temp;
	string data = Memory::read(to_string(memory_address));
	int sign = data[0] == '1' ? 1 : 0;
	string store = "";

	for (int i = 31; i > 23; i--)
	{
		store += data[i];

	}

	reverse(store.begin(), store.end());
	string t1 = "";
	
		for (int i = 0; i < 24; i++)
		{
			t1 += '0';

		}


	t1 += store;

	if (RegisterFile::write1(rd, t1))
		return true;

	return false;
}

bool LS_instructions::storeB(string rs1, string offset, string rs2)
{

	read_reg R;
	R = RegisterFile::read(rs1, rs2);
	string source = R.r1;
	int sign = R.r1[0] == '1' ? 1 : 0;
	string address = R.r2;
	int location = stoi(offset) + Bintoint(address);
	string store = "";
	string temp = "";
	for (int i = 31; i > 23; i--)
	{
		store += source[i];

	}

	reverse(store.begin(), store.end());

	string t1 = "";
	if (sign)
	{

		for (int i = 0; i < 24; i++)
		{
			t1 += '1';

		}

	}
	else
	{

		for (int i = 0; i < 24; i++)
		{
			t1 += '0';

		}

	}

	t1 += store;

	if (Memory::write1(to_string(location), t1))
		return true;
	return false;



}

bool LS_instructions::storehw(string rs1, string offset, string rs2)
{

	read_reg R;
	R = RegisterFile::read(rs1, rs2);
	string source = R.r1;
	int sign = R.r1[0] == '1' ? 1 : 0;
	string address = R.r2;
	int location = stoi(offset) + Bintoint(address);
	string store = "";
	string temp = "";
	for (int i = 31; i > 15; i--)
	{
		store += source[i];

	}

	reverse(store.begin(), store.end());
	string t1 = "";
	if (sign)
	{

		for (int i = 0; i < 16; i++)
		{
			t1 += '1';

		}

	}
	else
	{

		for (int i = 0; i < 16; i++)
		{
			t1 += '0';

		}

	}

	t1 += store;

	if (Memory::write1(to_string(location), t1))
		return true;
	return false; 


}

bool LS_instructions::load_ui(string rd, string imm)
{
	string store= bitset<20>(stoi(imm)).to_string();
	
	for (int i = 0; i < 12; i++)
	{
		store += '0';
	}
	if (RegisterFile::write1(rd, store))
		return true; 

	return false; 
}

bool LS_instructions::fence()
{
	return true; 
	
}

bool LS_instructions::ecall()
{
	return false;
}

bool LS_instructions::ebreak()
{
	return false;
}
