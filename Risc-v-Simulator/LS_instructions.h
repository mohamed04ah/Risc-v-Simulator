#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<bitset>
#include"RegisterFile.h"
#include"Memory.h"
#include "read.h"
using namespace std;
class LS_instructions
{
public: 
	LS_instructions();

	bool Loadw(string rd, string offset, string base_reg);  // tested
	bool storew(string rs1, string offset, string rs2);  // tested 
	bool loadhw(string rd, string offset, string base_reg); // tested 
	bool loadhw_u(string rd, string offset, string base_reg);  // tested
	bool loadb(string rd, string offset, string base_reg); 
	bool loadb_u(string rd, string offset, string base_reg);
	bool storeB(string rs1, string offset, string rs2);
	bool storehw(string rs1, string offset, string rs2);
	bool load_ui(string rd, string imm);
	bool fence();
	bool ecall();
	bool ebreak();


private: 
	

};

