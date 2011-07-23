//****************************************************************************
// File  : Instruction.cpp
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The implementation for the Instruction class, which is nifty.
//****************************************************************************


using namespace std;

#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "SymbolTable.h"
#include "Instruction.h"


Instruction::Instruction(char * l, char * o, char * f0, char * f1)
{
  static int address_counter = 0;  // keep track o' the addresses
  
  // make sure they're all zero'd out to begin with
  memset(label, 0, sizeof(label));
  memset(opcode, 0, sizeof(opcode));
  memset(field0, 0, sizeof(field0));
  memset(field1, 0, sizeof(field1));
  
  address = address_counter++;

  if(l)  // if there was a label
  {
    strncpy(label, l, INSTR_LEN);
    symbolTable.addSymbol(label, address);
  }
  strncpy(opcode, o, INSTR_LEN);
  if(f0)
    strncpy(field0, f0, INSTR_LEN);
  if(f1)
    strncpy(field1, f1, INSTR_LEN);
}

void Instruction::print()
{
  cout << label << "\t";
  cout << opcode << "\t";
  if(strlen(field0))
    cout << field0 << "\t";
  if(strlen(field1))
    cout << field1 << "\t";
  cout << endl;
}

void Instruction::printSymbols()
{
  symbolTable.print();
}

bool Instruction::isLabel(char * opcode)
{
  return isalpha(opcode[0]);
}

// this is weird... but it works!
SymbolTable Instruction::symbolTable;


//
// INSTRUCTION TYPES
//
AType::AType(char * label, char * opcode, char * field0, char * field1)
  :Instruction(label, opcode, field0, field1)
{
}
unsigned int AType::encode()
{
  unsigned int ret = 0;  // return value
  int f0 = 0;  // field0, either an address or immediate value
  
  ret = getOpcode();
  ret <<= 24;  // shift opcode left

  if(isLabel(field0))  // if label then f0 = the address
    f0 = symbolTable.getAddress(field0);
  else  // otherwise f0 = the immediate value
    f0 = atoi(field0);  
  
  ret |= f0;  // bitwise or the opcode and field0
  
  return ret;
}

BType::BType(char * label, char * opcode, char * field0, char * field1)
  :Instruction(label, opcode, field0, field1)
{
}
unsigned int BType::encode()
{
  unsigned int ret = 0;
  int f0 = 0;
  int f1 = 0;

  int f0_mask = 0x000000ff;
  int f1_mask = 0x0000ffff;

  ret = getOpcode();
  ret <<= 24;  // shift opcode left

  f0 = atoi(field0);  // get the immediate value (field0)
  f0 &= f0_mask;      // make sure to ditch leading f's if f0 is negative
  f0 <<= 16;          // move it to the proper place

  ret |= f0;  // bitwise or the opcode and field0
  
  if(isLabel(field1))  // if it's a label then get the address
  {
    f1 = symbolTable.getAddress(field1);
    f1 -= (address + 1);
  }
  else
    f1 = atoi(field1);

  f1 &= f1_mask;  // gets rid of the tons of leading f's if f1 is negative

  ret |= f1;  // bitwise or opcode, f0, and f1
  
  return ret;
}

CType::CType(char * label, char * opcode, char * field0, char * field1)
  :Instruction(label, opcode, field0, field1)
{
}
unsigned int CType::encode()
{
  unsigned int ret = 0;

  ret = getOpcode();
  ret <<= 24;  // shift opcode left  
  
  return ret;
}

DType::DType(char * label, char * opcode, char * field0, char * field1)
  :Instruction(label, opcode, field0, field1)
{
}
unsigned int DType::encode()
{
  return atoi(field0);  // just returns the number for .fill
}


//
// A TYPES
//
Add::Add(char * label, char * opcode, char * field0, char * field1)
  :AType(label, opcode, field0, field1)
{
}

Load::Load(char * label, char * opcode, char * field0, char * field1)
  :AType(label, opcode, field0, field1)
{
}

Store::Store(char * label, char * opcode, char * field0, char * field1)
  :AType(label, opcode, field0, field1)
{
}


//
// B TYPES
// 
Beq::Beq(char * label, char * opcode, char * field0, char * field1)
  :BType(label, opcode, field0, field1)
{
}

Bne::Bne(char * label, char * opcode, char * field0, char * field1)
  :BType(label, opcode, field0, field1)
{
}


//
// C TYPES
//
Halt::Halt(char * label, char * opcode, char * field0, char * field1)
  :CType(label, opcode, field0, field1)
{
}


//
// D TYPES
//
Fill::Fill(char * label, char * opcode, char * field0, char * field1)
  :DType(label, opcode, field0, field1)
{
}

