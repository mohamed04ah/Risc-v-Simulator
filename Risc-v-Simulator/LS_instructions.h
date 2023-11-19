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

	bool Loadw(string rd, string offset, string base_reg);  //tested
	bool storew(string rs1, string offset, string rs2);  //tested
	bool loadhw(string rd, string offset, string base_reg); //tested
	bool loadhw_u(string rd, string offset, string base_reg); //tested 
	bool loadb(string rd, string offset, string base_reg); //tested
	bool loadb_u(string rd, string offset, string base_reg);//tested
	bool storeB(string rs1, string offset, string rs2);//tested
	bool storehw(string rs1, string offset, string rs2);//tested
	bool load_ui(string rd, string imm);//tested
	void beq(string r1, string r2, string label); //tested
	void bne(string r1, string r2, string label);//tested
	void add(string dest, string r1, string r2); //tested
	void addi(string dest, string r1, string r2);//tested
	void sub (string dest, string r1, string r2);//tested
	void slt(string dest, string r1, string r2);//tested
	void slti(string dest, string r1, string r2); //tested
	void sltu(string dest, string r1, string r2); //tested
	void sltiu(string dest, string r1, string r2); //tested
	void jal(string ra, string label); //tested
	void jalr(string dest, string offset, string r1); //tested 
	void blt(string r1, string r2, string label);/// tested
	void bltu(string r1, string r2, string label);//tested
	void bgt(string r1, string r2, string label);//tested
	void bgtu(string r1, string r2, string label);//tested
	void And(string dest, string r1, string r2); //tested
	void Andi(string dest, string r1, string imm); //tested
	void Or(string dest, string r1, string r2);
	void ori(string dest, string r1, string imm);
	void Xor(string dest, string r1, string r2); //tested
	void xori(string dest, string r1, string imm);
	void sll(string dest, string r1, string shift);
	void slli(string dest, string r1, string imm); //tested
	void srl(string dest, string r1, string shift);
	void srli(string dest, string r1, string imm);
	void sra(string dest, string r1, string shift);
	void srai(string dest, string r1, string imm);



private: 
	

};

