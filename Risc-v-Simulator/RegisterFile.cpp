#include "RegisterFile.h"

RegisterFile& RegisterFile::getinstance()
{
	static RegisterFile RF;
	return RF;
}

RegisterFile::RegisterFile() {
	create_RF();
}

bool RegisterFile::validate(string rd)
{

	if (rd.size() != 2) return false;
	else {
		return rd == "x0" ? false : true;

		if (rd[0] == 'a')
		{
			if (rd[1] > 7 || rd[1] < 0)
				return false;
		}
		if (rd[0] == 's') {
			if (rd[1] > 11 || rd[1] < 0)
				return false;
		}

		if (rd[0] == 't') {
			if (rd[1] > 6 || rd[1] < 0)
				return false;
		}

	}

	return true;
}

string RegisterFile::Iread(string r1)
{
	bool validated = validate(r1);
	if (validated)
	{
		auto it = registers.find(r1);
		return it->second;
	}


	return "invalid Read";

}

read_reg RegisterFile::Iread(string r1, string r2)
{
	bool validated = validate(r1) && validate(r2);
	if (validated) {
		read_reg result;
		auto it = registers.find(r1);
		result.r1 = it->second;
		it = registers.find(r2);
		result.r2 = it->second;
		return result;
	}

	cout << endl << "invalid read" << endl;

}

bool RegisterFile::Iwrite(string rd, string value)
{
	bool validated = validate(rd);

		if (validated)
		{
			registers[rd] = bitset<32>(stoi(value)).to_string();
			return true;
		}
		cout << endl << "invalid Write." << endl;
		return false;


}

bool RegisterFile::Iwrite1(string rd, string value)
{
	bool validated = validate(rd);
	
	if (validated)
	{
		registers[rd] = value;
		return true;
	}
	cout << endl << "invalid Write." << endl;
	return false;

}

void RegisterFile::create_RF()
{

	registers["zero"] = bitset<32>(0).to_string();
	registers["ra"] = bitset<32>(0).to_string();
	registers["sp"] = bitset<32>(0).to_string();
	registers["gp"] = bitset<32>(0).to_string();
	registers["tp"] = bitset<32>(0).to_string();

	//creating the temp registers
	for (int i = 0; i < 7; i++) {
		registers["t" + to_string(i)] = bitset<32>(0).to_string();

	}
	//creating the save registers
	for (int i = 0; i < 12; i++)
	{
		registers["s" + to_string(i)] = bitset<32>(0).to_string();

	}
	//creating the argument registers
	for (int i = 0; i < 8; i++)
	{
		registers["a" + to_string(i)] = bitset<32>(0).to_string();

	}


}
string decimal_hexa(string value)
{


	int val = stoi(value);
	if (val == 0) {
		return "0";
	}

	string result = "";
	int i = 0;
	while (val > 0) {
		int mod = val % 16;
		char c;
		c = mod < 10 ? mod + 48 : mod + 55;
		result += c;
		val = val / 16;
	}
	int size = result.size() - 1;
	while (i < size)
	{
		swap(result[i], result[size]);
		i++;
		size--;
	}

	return result;
}
void RegisterFile::Iprint_RF()
{
	cout << "BINARY|DECIMAL|HEXADECIMAL" << endl;
	for (auto& it : registers) {
		int val = bin_decimal(it.second);
		cout << it.first << "|" << setw(3) << it.second << "(" << val << ")" << "(" << decimal_hexa(to_string(val)) << ")" << endl;
	}
}

int RegisterFile::bin_decimal(string value)
{
	
	if (value[0] == '1')
	{
		int r1;
	   r1 = bitset<32>(value).to_ullong();
	
		r1 = -((1 << value.length()) - r1);
		return r1+1;
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



void RegisterFile::Idelete_rf()
{
	
	for (auto &it : registers) 
	{
		it.second= bitset<32>(0).to_string();
	}

}



