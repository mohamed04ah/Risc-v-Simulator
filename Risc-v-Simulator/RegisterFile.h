#include <iostream>
#include <string>
#include <map>
#include<bitset>
#include<iomanip>
using namespace std;
struct read_reg
{
	// used for reading 2 registers at once
	string r1, r2;
};
class RegisterFile
{
	/* IMPORTANT NOTE: only one instance can be created of the RegisterFile as dictated by the class Design Pattern (Singleton).*/

	/* the class follows the singleton design pattern.to read or write to the register file
	* RegisterFile::read(<register name>) // returns string containing the value of the register
	* RegisterFile::write(<destination register>,<int value>) // returns bool to indicate success or failure of the write operation
	* RegisterFile::print_RF() //to print the current values in all registers
	*/
public:
	static RegisterFile& getinstance();
	RegisterFile(const RegisterFile&) = delete;
	static string read(string r1) { return getinstance().Iread(r1); }
	static read_reg read(string r1, string r2) { return getinstance().Iread(r1, r2); }
	static bool write(string rd, string value) { return getinstance().Iwrite(rd, value); }
	static void print_RF() { getinstance().Iprint_RF(); }
private:
	RegisterFile();
	map<string, string> registers;
	bool validate(string rd);
	string Iread(string r1);
	read_reg Iread(string r1, string r2);
	bool Iwrite(string rd, string value);
	void create_RF();
	void Iprint_RF();
	int bin_decimal(string value);
	


};
