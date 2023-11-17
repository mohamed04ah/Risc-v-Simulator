#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include<bitset>
#include<iomanip>
#include <sstream>
#include <map>
using namespace std;
int programCounter = 0;
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
    static bool write1(string rd, string value) { return getinstance().Iwrite1(rd, value); }
    static void print_RF() { getinstance().Iprint_RF(); }
    static void delete_rf() { getinstance().Idelete_rf(); }

private:
    RegisterFile();
    map<string, string> registers;
    bool validate(string rd);
    string Iread(string r1);
    read_reg Iread(string r1, string r2);
    bool Iwrite(string rd, string value);
    bool Iwrite1(string rd, string value);
    void create_RF();
    void Iprint_RF();
    int bin_decimal(string value);
    void Idelete_rf();



};

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
        registers[rd] = bitset<32>(Bintoint(value)).to_string();
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


    int val = Bintoint(value);
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



void RegisterFile::Idelete_rf()
{

    for (auto& it : registers)
    {
        it.second = bitset<32>(0).to_string();
    }

}
int Bintoint(string value)
{

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

void And_func(string dest, string r1, string r2)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int x2 = Bintoint(RegisterFile::read(r2));
    int result = x1 & x2;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void Andi_func(string dest, string r1, string imm)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int x2 = Bintoint(imm);
    int result = x1 & x2;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void or_func(string dest, string r1, string r2)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int x2 = Bintoint(RegisterFile::read(r2));
    int result = x1 | x2;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
   
}
void ori_func(string dest, string r1, string imm)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int x2 = Bintoint(imm);
    int result = x1 | x2;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void xor_func(string dest, string r1, string r2)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int x2 = Bintoint(RegisterFile::read(r2));
    int result = x1 ^ x2;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void xori_func(string dest, string r1, string imm)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int x2 = Bintoint(imm);
    int result = x1 ^ x2;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void sll_func(string dest, string r1, string shift)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int shiftAmount = Bintoint(shift);
    int result = x1 << shiftAmount;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void slli_func(string dest, string r1, string imm)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int shiftAmount = Bintoint(imm);
    int result = x1 << shiftAmount;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void srl_func(string dest, string r1, string shift)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int shiftAmount = Bintoint(shift);
    int result = x1 >> shiftAmount;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void srli_func(string dest, string r1, string imm)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int shiftAmount = Bintoint(imm);
    int result = x1 >> shiftAmount;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void sra_func(string dest, string r1, string shift)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int shiftAmount = Bintoint(shift);
    int result = x1 >> shiftAmount;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void srai_func(string dest, string r1, string imm)
{
    int x1 = Bintoint(RegisterFile::read(r1));
    int shiftAmount = Bintoint(imm);
    int result = x1 >> shiftAmount;
    RegisterFile::write(dest, to_string(result));
    programCounter += 4;
}
void jal_func(string dest, string offset)
{
    int offsetInt = Bintoint(offset);
    string nextInstruction = to_string(programCounter + 4);
    RegisterFile::write(dest, nextInstruction);
    programCounter += offsetInt;
}
