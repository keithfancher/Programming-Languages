//****************************************************************************
// File  : Instruction.h
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The header for the Instruction class, which is nifty.
//****************************************************************************


#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__


#include "SymbolTable.h"


class Instruction
{
  public:
    Instruction(char * label, char * opcode, char * field0, char * field1);

    virtual unsigned int encode() = 0;

    void print();         // prints the instruction
    void printSymbols();  // prints the static symbolTable

    const static int INSTR_LEN = 20;  // max length for a single field

  protected:
    bool isLabel(char * opcode);
    virtual unsigned int getOpcode() = 0;
    
    unsigned int address;           // the address of instruction
    char label[INSTR_LEN];          // label field
    char opcode[INSTR_LEN];         // opcode field
    char field0[INSTR_LEN];         // field0
    char field1[INSTR_LEN];         // field1
    static SymbolTable symbolTable; // the SymbolTable for the program
};


//
// INSTUCTION TYPES
//
// - These all have the same format: a constructor, and an encode() function
//   that returns the int value of the instruction to be converted to hex
//   then outputted to the *.hex file.
class AType : public Instruction
{
  public:
    AType(char * label, char * opcode, char * field0, char * field1 = NULL);  // ATypes don't use field1
    unsigned int encode();
};
class BType : public Instruction
{
  public:
    BType(char * label, char * opcode, char * field0, char * field1);
    unsigned int encode();
};
class CType : public Instruction
{
  public:
    CType(char * label, char * opcode, char * field0 = NULL, char * field1 = NULL);  // CTypes don't use either field
    unsigned int encode();
};
class DType : public Instruction
{
  public:
    DType(char * label, char * opcode, char * field0, char * field1 = NULL);  // DTypes don't use field1
    unsigned int encode();
};


//
// A TYPES
//
// - These all follow the same format: a constructor, and a getOpcode() function
//    that is only really used in the above encode() functions that returns the
//    integer value of the various opcodes.
class Add : public AType
{
  public:
    Add(char * label, char * opcode, char * field0, char * field1 = NULL);
  protected:
    unsigned int getOpcode() {return 1;}
};
class Load : public AType
{
  public:
    Load(char * label, char * opcode, char * field0, char * field1 = NULL);
  protected:
    unsigned int getOpcode() {return 2;}
};
class Store : public AType
{
  public:
    Store(char * label, char * opcode, char * field0, char * field1 = NULL);
  protected:
    unsigned int getOpcode() {return 3;}
};


//
// B TYPES
//
// - See A TYPES for description.
class Beq : public BType
{
  public:
    Beq(char * label, char * opcode, char * field0, char * field1);
  protected:
    unsigned int getOpcode() {return 4;}
};
class Bne : public BType
{
  public:
    Bne(char * label, char * opcode, char * field0, char * field1);
  protected:
    unsigned int getOpcode() {return 5;}
};


//
// C TYPES
//
// - See A TYPES for description.
class Halt : public CType
{
  public:
    Halt(char * label, char * opcode, char * field0 = NULL, char * field1 = NULL);
  protected:
    unsigned int getOpcode() {return 6;}
};


//
// D TYPES
//
// - See A TYPES for description.
class Fill : public DType
{
  public:
    Fill(char * label, char * opcode, char * field0, char * field1 = NULL);
  protected:
    unsigned int getOpcode() {return 0;}
};


#endif
