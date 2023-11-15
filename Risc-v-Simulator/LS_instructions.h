#pragma once
#include<string>
#include<iostream>
#include"RegisterFile.h"
#include"Memory.h"
#include "read.h"
using namespace std;
class LS_instructions
{
public: 
	LS_instructions();

	bool Loadw(string rd, string offset, string base_reg);
	bool storew(string rs1, string offset, string rs2);
	bool loadhw(string rd, string offset, string base_reg);

private: 
	

};

