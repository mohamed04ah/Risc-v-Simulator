#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<bitset>
#include"RegisterFile.h"
#include"Memory.h"
#include "Risc_v_Simulator.h"
#include"global.h"
using namespace std;
class LS_instructions
{
public: 
	LS_instructions();

	bool Loadw(string rd, string offset, string base_reg);  
	bool storew(string rs1, string offset, string rs2);  
	bool loadhw(string rd, string offset, string base_reg); 
	bool loadhw_u(string rd, string offset, string base_reg);  
	bool loadb(string rd, string offset, string base_reg); 
	bool loadb_u(string rd, string offset, string base_reg);
	bool storeB(string rs1, string offset, string rs2);
	bool storehw(string rs1, string offset, string rs2);
	bool load_ui(string rd, string imm);
	void beq(string r1, string r2, string label); 
	void bne(string r1, string r2, string label);
	void add(string dest, string r1, string r2); 
	void addi(string dest, string r1, string r2);
	void sub (string dest, string r1, string r2);
	void slt(string dest, string r1, string r2);
	void slti(string dest, string r1, string r2); 
	void sltu(string dest, string r1, string r2); 
	void sltiu(string dest, string r1, string r2); 
	void jal(string ra, string label); 
	void jalr(string dest, string offset, string r1);  
	void blt(string r1, string r2, string label);
	void bltu(string r1, string r2, string label);
	void bgt(string r1, string r2, string label);
	void bgtu(string r1, string r2, string label);
	void And(string dest, string r1, string r2); 
	void Andi(string dest, string r1, string imm); 
	void Or(string dest, string r1, string r2); 
	void ori(string dest, string r1, string imm); 
	void Xor(string dest, string r1, string r2); 
	void xori(string dest, string r1, string imm); 
	void sll(string dest, string r1, string shift); 
	void slli(string dest, string r1, string imm); 
	void srl(string dest, string r1, string shift);
	void srli(string dest, string r1, string imm); 
	void sra(string dest, string r1, string shift); 
	void srai(string dest, string r1, string imm);



private: 
	

};

