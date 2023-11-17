#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include <sstream>
#include <map>
using namespace std;
int And_func(int r1, int r2)
{
    int result = r1 & r2;
    return result;
}
int or_func(int r1, int r2)
{
    int result = r1 | r2;
    return result;
}
unsigned int shiftLeft_func(unsigned int value, int shift) {
    return value << shift;
}
unsigned int shiftright_func(unsigned int value, int shift) {
    return value >> shift;
}
void jal_func(map<string, string>& myMap, const vector<string>& com) {
    try {
        if (stoul(myMap[com[2]]) < stoul(com[3])) {
            myMap[com[1]] = "1";
        }
        else {
            myMap[com[1]] = "0";
        }
        cout << myMap[com[1]];
    }
    catch (const std::invalid_argument& ia) {
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
    catch (const std::out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << '\n';
    }
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

   

void add(string dest, string r1, string r2) {
    int res = 0;
    int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
    res = x1 + x2;
    RegisterFile::write(dest, res);
}

void sub(string dest, string r1, string r2) {
    int res = 0;
    int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
    res = x1 - x2;
    RegisterFile::write(dest, res);
}

void slt(string dest, string r1, string r2) {
    int res = 0;
    int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
    if (x1 < x2) { RegisterFile::write(dest, 1); return; }
    RegisterFile::write(dest, 0);
}

void slti(string dest, string r1, string r2) {
    int res = 0;
    int x1 = Bintoint(RegisterFile::read(r1));
    if (x1 < stoi(r2)) { RegisterFile::write(dest, 1); return; }
    RegisterFile::write(dest, 0);
}

void sltu(string dest, string r1, string r2) {
    int res = 0;
    int x1 = Bintoint(RegisterFile::read(r1)), x2 = Bintoint(RegisterFile::read(r2));
    if (x1 < 0) { x1 *= -1; }
    if (x1 < x2) { RegisterFile::write(dest, 1); return; }
    RegisterFile::write(dest, 0);
}

void sltiu(string dest, string r1, string r2) {
    int res = 0;
    int x1 = Bintoint(RegisterFile::read(r1));
    if (x1 < 0) { x1 *= -1; }
    if (x1 < stoi(r2)) { RegisterFile::write(dest, 1); return; }
    RegisterFile::write(dest, 0);
}

void jal() {
    
}

void sra(string dest, string r1, string r2) {
    signed int x1 = stoi(RegisterFile::read(r1)), x2 = stoi(RegisterFile::read(r2));
    int r = x1 >> (x2 & 0b11111);
    RegisterFile::write(dest, Bintoint(to_string(r)));
}

void srai(string dest, string r1, string r2) {
    signed int x1 = stoi(RegisterFile::read(r1));
    int r = x1 >> stoi(r2);
    RegisterFile::write(dest, Bintoint(to_string(r)));
}

int main() {
    map<string, string> myMap;
    int lineNumber = 0;
    myMap["x5"] = "0";
    myMap["x6"] = "0";
    myMap["x7"] = "0";
    myMap["x28"] = "0";
    myMap["x29"] = "0";
    myMap["x30"] = "0";
    myMap["x31"] = "0";
    myMap["x9"] = "0";
    myMap["x18"] = "0";
    myMap["x19"] = "0";
    myMap["x20"] = "0";
    myMap["x21"] = "0";
    myMap["x22"] = "0";
    myMap["x23"] = "0";
    myMap["x24"] = "0";
    myMap["x25"] = "0";
    myMap["x26"] = "0";
    myMap["x27"] = "0";
    vector<string>com;
    string filename = "example.txt";
    ifstream inputFile(filename);//open file
    if (inputFile.is_open()) {
        string line;
        string element;
        while (getline(inputFile, line)) {//get line by line
            stringstream ss(line); 
            com.clear();
            while (ss >> element) { // Read each element
               element= element.substr(0, element.find(","));
                com.push_back(element); // Add the element to the vector
            }// all of the functions in assembly
            if (com[0] == "li") 
            {
                myMap[com[1]] = com[2];
            }
            if (com[0] == "addi")
            {
                myMap[com[1]] =to_string(stoi(myMap[com[2]]) + stoi(com[3]));
                //cout << myMap[com[1]];
            }
            if (com[0] == "and")
            {
             
                int result = And_func(stoi(myMap[com[2]]),stoi(myMap[com[3]]));
                myMap[com[1]] = to_string(result);
                //cout << myMap[com[1]];
            }
            if (com[0] == "or")
            {

                int result = or_func(stoi(myMap[com[2]]), stoi(myMap[com[3]]));
                myMap[com[1]] = to_string(result);
               //cout << myMap[com[1]]<<endl;
            }
            if (com[0] == "andi")
            { 
                myMap[com[1]] = to_string(stoi(myMap[com[2]]) & stoi(com[3])); 
                //cout << myMap[com[1]]<<endl;
            }
            if (com[0] == "ori")
            {
                myMap[com[1]] = to_string(stoi(myMap[com[2]]) | stoi(com[3]));
                //cout << myMap[com[1]]<<endl;
            }
            if (com[0] == "xor")
            {
                myMap[com[1]] = to_string(stoi(myMap[com[2]]) ^ stoi(myMap[com[3]]));
                cout << myMap[com[1]];
            }
            if (com[0] == "xori")
            {
                myMap[com[1]] = to_string(stoi(myMap[com[2]]) ^ stoi(com[3]));
                cout << myMap[com[1]];
            }
            if (com[0] == "sll")
            {
                int result = shiftLeft_func(stoi(myMap[com[2]]), stoi(myMap[com[3]]));
                myMap[com[1]] = to_string(result);
                cout << myMap[com[1]];
            }
            if (com[0] == "slli")
            {
                myMap[com[1]] = to_string(stoi(myMap[com[2]]) << stoi(com[3]));
                cout << myMap[com[1]];
            }
            if (com[0] == "srl")
            {
                int result = shiftright_func(stoi(myMap[com[2]]), stoi(myMap[com[3]]));
                myMap[com[1]] = to_string(result);
                cout << myMap[com[1]];
            }
            if (com[0] == "srli")
            {
                myMap[com[1]] = to_string(stoi(myMap[com[2]]) >> stoi(com[3]));
                cout << myMap[com[1]];
            }
            if (com[0] == "jal")
            {
                jal_func(myMap, com);

            }
            if (com[0] == "jalr")
            {
                jal_func(myMap, com);
            }
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}
