#include "Risc_v_Simulator.h"

Risc_v_Simulator::Risc_v_Simulator()
{
	read_instructions();
	
	Call_Instructions(PC);
	
}

void Risc_v_Simulator::read_instructions()
{
	Memory& Mem = Memory::getinstance();
	int counter = 0;
	int location = 0;
	string filename = "input.txt"; 
	ifstream inputfile(filename);
	vector<string> instructions;
	if (inputfile.is_open())
	{
	
		string line; 
		string element; 
		while (getline(inputfile, line))
		{
			if (counter == 0) 
			{
				initial_loc = stoi(line);
				counter++;
				location = initial_loc;
				PC = initial_loc;
			}
			else 
			{
				if (find_col(line))
				{
					Memory::label_set(line.substr(0, line.find(':')), to_string(location));
					
				}
				instructions.push_back(line);
				location+=4;
				no_inst++;
			}
		}
	}
	Mem.program_loc(to_string(initial_loc), instructions);
	//==========================
	counter = 0;
	string filename1 = "memory.txt";
	ifstream inputfile1(filename1);
	string fa;
	if (inputfile1.is_open()) 
	{

		string line;
		string element;
		while (getline(inputfile1, line))
		{
			
			if (counter == 0) 
			{
				fa = line;
				counter++;
			}
			else 
			{
				Mem.write(fa, line);
				fa = to_string(stoi(fa) + 4);
			}
		}
	}
	

}

void Risc_v_Simulator::Call_Instructions(int pc)
{
	static int  counter = 1;
	cout << counter << endl;
	cout << PC << endl;
	vector<string> v;
	identify_inst(removespaces(Memory::read(to_string(pc))), v);
	string action = v[0];
	if (action == "ECALL" || action == "EBREAK" || action == "FENCE")
		return; 
	 static LS_instructions x;

	if (action == "ADD")
	{
		x.add(v[1], v[2], v[3]);
	

	}
	else if (action == "SUB")
	{
		x.sub(v[1], v[2], v[3]);
	}
	else if (action == "ADDI")
	{
		x.addi(v[1], v[2], v[3]);
	}
	else if (action == "LUI")
	{
		x.load_ui(v[1],v[2]);
	}
	 else if (action == "JAL") // to be adjusted
	{
		x.jal(v[1], v[2]);
	}
	 else if (action == "JALR") // to be adjusted 
	{
		x.jalr(v[1], v[2], v[3]);
		cout << v[1] << v[2] << v[3] << endl;
	}
	else if (action == "BEQ")
	{
		x.beq(v[1], v[2], v[3]);
		
	}
	else if (action == "BNE")
	{
		x.bne(v[1], v[2], v[3]);
	}
	else if (action == "BLT")
	{
		x.blt(v[1], v[2], v[3]);
	}
	else if (action == "BGE")
	{
		x.bgt(v[1], v[2], v[3]);
	}
	else if (action == "BLTU")
	{
		x.bltu(v[1], v[2], v[3]);
	}
	else if (action == "BGEU")
	{
		x.bgtu(v[1], v[2], v[3]);
	}
	else if (action == "LB")
	{
		x.loadb(v[1],v[2],v[3]);
	}
	else if (action == "LH")
	{
		x.loadhw(v[1], v[2], v[3]);
	}
	else if (action == "LW")
	{
		x.Loadw(v[1], v[2], v[3]);
	}
	else if (action == "LBU")
	{
		x.loadb_u(v[1], v[2], v[3]);
	}
	else if (action == "LHU")
	{
		x.loadhw_u(v[1], v[2], v[3]);
	}
	else if (action == "SB")
	{
		x.storeB(v[1], v[2], v[3]);
	}
	else if (action == "SH")
	{
		x.storehw(v[1], v[2], v[3]);
	}
	else if (action == "SW")
	{
		x.storew(v[1], v[2], v[3]);
	}
	else if (action == "SLTI")
	{
		x.slti(v[1], v[2], v[3]);
	}
	else if (action == "SLTIU")
	{
		x.sltiu(v[1], v[2], v[3]);
	}
	else if (action == "XORI")
	{
		x.xori(v[1], v[2], v[3]);
	}
	else if (action == "ORI")
	{
		x.ori(v[1], v[2], v[3]);
	}
	else if (action == "ANDI")
	{
		x.Andi(v[1], v[2], v[3]);
	}
	else if (action == "SLLI")
	{
		x.slli(v[1], v[2], v[3]);
		}
	else if (action == "SRLI")
	{
		x.srli(v[1], v[2], v[3]);
		}
	else if (action == "SRAI")
	{
		x.srai(v[1], v[2], v[3]);
		}
	else if (action == "SLL")
	{
		x.sll(v[1], v[2], v[3]);
		}
	else if (action == "SLT")
	{
		x.slt(v[1], v[2], v[3]);
		}
	else if (action == "SLTU")
	{
		x.sltu(v[1], v[2], v[3]);
		}
	else if (action == "XOR")
	{
		x.Xor(v[1], v[2], v[3]);
		}
	else if (action == "SRL")
	{
		x.srl(v[1], v[2], v[3]);
		}
	else if (action == "SRA")
	{
		x.sra(v[1], v[2], v[3]);
		}
	else if (action == "OR")
	{
		x.Or(v[1], v[2], v[3]);
		}
	else if (action == "AND")
	{
		x.And(v[1], v[2], v[3]);
		}

	Print_all();
	counter++;
	
	Call_Instructions(PC);

}



bool Risc_v_Simulator::find_col(string s)
{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ':') {
				return 1;
			}
		}
		return 0;
}

void Risc_v_Simulator::identify_inst(string inst,vector<string>&breakdown)
{
	

	if (inst == "EBREAK" || inst == "FENCE" || inst == "ECALL") {
		breakdown.push_back(inst);
		return;
	}
	int comnum = commaNum(inst);
	string action;
	int tag = find_col(inst);
	if (tag) 
	{
	
		int temp = inst.find(':');
		temp += 1;
	
		string search = inst.substr(temp, inst.find(','));
		int n1, n2, n3, n4, n5;
		n1 = search.find('s'); n2 = search.find('a'); n3 = search.find('z'); n4 = search.find('t'), n5 = search.find('r');
		if (n1 == -1)
			n1 = 100000;
		if (n2 == -1)
			n2 = 100000;
		if (n3 == -1)
			n3 = 100000;
		if (n4 == -1)
			n4 = 10000;
		if (n5 == -1)
			n5 = 10000;
		int N=min(n5,min(min(n1, n2),min(n3, n4)));
		action = search.substr(0, N);
	}
	else
	{
		
		string search = inst.substr(0, inst.find(','));
		
		int n1, n2, n3, n4, n5;
		n1 = search.find('s'); n2 = search.find('a'); n3 = search.find('z'); n4 = search.find('t'); n5 = search.find('r');
		
		if (n1 == -1) 
			n1 = 100000;
		if (n2 == -1)
			n2 = 100000;
		if (n3  == -1)
			n3 = 100000;
		if (n4  == -1)
			n4 = 10000;
		if (n5 == -1)
			n5 = 10000;
		int N = min(n5, min(min(n1, n2), min(n3, n4)));
		
		action = search.substr(0, N);
		
		
	}
	
	breakdown.push_back(action);
	
	if (comnum == 1) 
	{
		comma_1(inst, action, tag,breakdown);
	}
	if (comnum == 2) 
	{
		comma_2(inst, action, tag, breakdown);
	}
	return;

}
void Risc_v_Simulator::comma_1(string s,string action,int tag,vector<string>&breakdown)
{
	
	if (tag) 
	{
		
		s.erase(0,s.find(':')+1);
	}
	
		int comma_loc = s.find(',');
		
	
		s.erase(0, action.size() );
		
		string r1 = s.substr(0,s.find(','));
		breakdown.push_back(r1);
		s.erase(s.find(r1), s.find(',')+1);
		string offset = s.substr(0, s.find('('));
		
		breakdown.push_back(offset);
		s.erase(s.find(offset), s.find('(')+1);
		
		string r2 = s.substr(0, s.find(')'));
		breakdown.push_back(r2);
		return;
	
}
void Risc_v_Simulator::comma_2(string s, string action, int tag, vector<string>& breakdown)
{
	if (tag)
	{

		s.erase(0, s.find(':') + 1);
	}
	
	s.erase(0, action.size());
	string e1 = s.substr(0, s.find(','));
	
	breakdown.push_back(e1);
	s.erase(s.find(e1), s.find(',') + 1);

	string e2 = s.substr(0,s.find(','));
	
	breakdown.push_back(e2);
	s.erase(0, s.find(',')+1);
	
	breakdown.push_back(s);

	

	return; 

}
string Risc_v_Simulator::removespaces(string s)
{
	string temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] !=' ') {
				temp += s[i];
			}
		}
		
		return temp;
	
}
int Risc_v_Simulator::commaNum(string s)
{
	int c = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',') 
		{
			if (s[i - 1] == ',') 
			{
				return -1;
			}
			c++;
		}
	}
	return c;
}



