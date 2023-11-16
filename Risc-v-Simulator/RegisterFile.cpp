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

void RegisterFile::Iprint_RF()
{
	for (auto& it : registers) {
		cout << it.first << "|" << setw(3) << it.second << "(" << bin_decimal(it.second) << ")" << endl;
	}
}

int RegisterFile::bin_decimal(string value)
{
	int result = 0;

	for (int i = value.size(); i>=0; i--) {
		if (value[i] == '1') {
		
			result += pow(2, value.size() - i - 1);
				
		}
	}
	return result;
}



