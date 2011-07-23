//****************************************************************************
// File  : Program.h
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The header for the Program class, which is used to read in the
//   program, generate the binary, and other such useful thingies.
//****************************************************************************


#ifndef __PROGRAM_H__
#define __PROGRAM_H__


class Program
{
  public:
    Program();  // default constructor

    void read(ifstream &);     // reads the program in, stores the instruction
    void generate(ofstream &); // generates the binary for all the instructions
    void print();              // prints the program out!!! (!!!) 

  private:
    static const int MAXLEN = 50; // max number of instructions for the program

    Parse p;                       // parsey parsey parse parse
    Instruction * ins[MAXLEN];     // the array of instructions
    unsigned int instructionCount; // number of instructions in the program

};


#endif
