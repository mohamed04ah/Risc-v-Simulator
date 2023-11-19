#include "LS_instructions.h"

LS_instructions::LS_instructions()
{
	

}
int Bintoint(string value) {
	
	/*int result = 0;

	for (int i = value.size(); i >= 0; i--) {
		if (value[i] == '1') {

			result += pow(2, value.size() - i - 1);

		}
	}
	return result;*/
	if (value[0] == '1')
	{
		int r1;
		r1 = bitset<32>(value).to_ullong();

		r1 = -((1 << value.length()) - r1);
		return r1 + 1;
	}
	else
	{
		int result = 0;
		for (int i = value.size(); i >= 0; i--)
		{
			if (value[i] == '1') {

				result += pow(2, value.size() - i - 1);

			}
		}
		return result;
	}

	return 0;

	
}
bool LS_instructions::Loadw(string rd, string offset, string base_reg)
{
	string base_add = RegisterFile::read(base_reg);
	int temp = Bintoint(base_add);
	int memory_address = stoi(offset) + temp;
	string data = Memory::read(to_string(memory_address));


	
	if (RegisterFile::write1(rd, data))
	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
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

	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
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
	{
		PC += 4;
		return true;
	}
	PC += 4;
	return false; 
}

void  LS_instructions::add(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
	res = x1 + x2;
	RegisterFile::write(dest, to_string(res));
	PC += 4;
}

void  LS_instructions::addi(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = stoi(r2);
	res = x1 + x2;
	RegisterFile::write(dest, to_string(res));
	PC += 4;
}


void  LS_instructions::sub(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
	res = x1 - x2;
	RegisterFile::write(dest, to_string(res));
	PC += 4;
}

void  LS_instructions::slt(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
	if (x1 < x2)
	{ RegisterFile::write(dest, "1");
	}
	else 
	{
		RegisterFile::write(dest, "0");
		 
	}
	PC += 4;
	return; 
}

void  LS_instructions::slti(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1));
	if (x1 < stoi(r2)) { RegisterFile::write(dest, "1");  }
	else 
	RegisterFile::write(dest, "0");
	PC += 4;
	return; 
}

void  LS_instructions::sltu(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
	if (x1 < 0) { x1 *= -1; }
	if (x2 < 0) { x2 *= -1; }
	if (x1 < x2) { RegisterFile::write(dest, "1");  }
	else 
   RegisterFile::write(dest, "0");
	PC += 4;
	return;
}

void  LS_instructions::sltiu(string dest, string r1, string r2) {
	int res = 0;
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = stoi(r2);
	if (x1 < 0) { x1 *= -1; }
	if (x2 < 0) x2 *= -1;

	if (x1 < x2) { RegisterFile::write(dest, "1");  }
	else 
	RegisterFile::write(dest, "0");
	PC += 4;
	return;
}

void  LS_instructions::jal(string ra, string label) 
{
		RegisterFile::write(ra, to_string(PC+4));
		PC = stoi((Memory::read_label(label)));
		cout << "wrote to ra" << RegisterFile::read(ra) << endl;
}



void LS_instructions::blt(string r1, string r2, string label) {
	bool t = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
	t = x1 < x2;
	if (t) {
		PC = stoi(Memory::read_label(label));
	}
}

void  LS_instructions::bltu(string r1, string r2, string label)
{
	bool t = 0;
	int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
	if (x1 < 0) { x1 *= -1; }
	if (x2 < 0) { x2 *= -1; }
	t = x1 < x2;
	if (t) {
		PC = stoi(Memory::read_label(label));
	}
	else 
	PC += 4;
}

void LS_instructions::bgt(string r1, string r2, string label)
	{
		bool t = false;
		int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
		t = (x1 >= x2);
		if (t) 
		{
			PC = stoi(Memory::read_label(label));
		}
		else
			PC += 4;
	}

void LS_instructions::bgtu(string r1, string r2, string label) {
		bool t = 0;
		int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
		if (x1 < 0) { x1 *= -1; }
		if (x2 < 0) { x2 *= -1; }
		t = x1 >= x2;
		if (t) {
			PC = stoi(Memory::read_label(label));
		}
		else
			PC += 4;
	}

void LS_instructions::beq(string r1, string r2, string label)
{
	read_reg R; 
	R=RegisterFile::read(r1, r2); 
	

	if (R.r1 == R.r2)
	{
		PC= stoi((Memory::read_label(label)));
		return; 
	}
	PC += 4;

	return;

}
void LS_instructions::bne(string r1, string r2, string label)
{
	read_reg R;
	R = RegisterFile::read(r1, r2);
	
	
	if (R.r1 != R.r2)
	{
		PC = stoi((Memory::read_label(label)));
		return;
	}
	PC += 4;


	return;

}

void LS_instructions::And(string dest, string r1, string r2)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = Bintoint(RegisterFile::read(r2));
	int result = x1 & x2;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::Andi(string dest, string r1, string imm)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = stoi(imm);
	int result = x1 & x2;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::Or(string dest, string r1, string r2)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = Bintoint(RegisterFile::read(r2));
	int result = x1 | x2;
	RegisterFile::write(dest, to_string(result));
	PC += 4;

}
void  LS_instructions::ori(string dest, string r1, string imm)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = stoi(imm);
	int result = x1 | x2;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::Xor(string dest, string r1, string r2)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = Bintoint(RegisterFile::read(r2));
	int result = x1 ^ x2;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void LS_instructions::xori(string dest, string r1, string imm)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int x2 = stoi(imm);
	int result;
	if (x2 == -1) {
		result = ~x1;
	}
	else 
	{
		int result = x1 ^ x2;
	}
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void LS_instructions::sll(string dest, string r1, string shift)
{
	cout << "from sll func" << endl;
	int x1 = Bintoint(RegisterFile::read(r1));
	int shiftAmount =Bintoint( RegisterFile::read(shift));
	cout << shiftAmount << endl;
	int result = x1 << shiftAmount;
	cout << "the result is" << result << endl;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::slli(string dest, string r1, string imm)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int shiftAmount = stoi(imm);
	int result = x1 << shiftAmount;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::srl(string dest, string r1, string shift)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int shiftAmount = Bintoint(RegisterFile::read(shift));
	int result = x1 >> shiftAmount;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::srli(string dest, string r1, string imm)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int shiftAmount = stoi(imm);
	int result = x1 >> shiftAmount;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::sra(string dest, string r1, string shift)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int shiftAmount = Bintoint(RegisterFile::read(shift));
	int result = x1 >> shiftAmount;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}
void  LS_instructions::srai(string dest, string r1, string imm)
{
	int x1 = Bintoint(RegisterFile::read(r1));
	int shiftAmount = stoi(imm);
	int result = x1 >> shiftAmount;
	RegisterFile::write(dest, to_string(result));
	PC += 4;
}

void  LS_instructions::jalr(string dest, string offset, string r1)
{ 
	cout << "recieved" << dest << offset << r1 << endl;
	if (dest == "zero") 
	{
		PC = Bintoint(RegisterFile::read(r1));
	}
	else
	{
		string nextInstruction = to_string(PC + 4);
		RegisterFile::write(dest, nextInstruction);
		int offsetInt = Bintoint(offset);
		int x1 = Bintoint(RegisterFile::read(r1));
		
		PC = x1 + offsetInt;
	}	
}
