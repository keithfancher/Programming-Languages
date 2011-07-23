//****************************************************************************
// File  : Program.cpp
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The implementation for the Program class, which is used to read
//   in the program, generate the binary, and other such useful thingies.
//****************************************************************************


using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Instruction.h"
#include "Parse.h"
#include "Program.h"


Program::Program()
{
  instructionCount = 0;
}

void Program::read(ifstream & in)
{
  // infinite loops make things like this smoother, so there!
  while(42)
  {
    ins[instructionCount] = p.parse(in);
    if(!ins[instructionCount])  // if parse returns NULL we're done
      break;
    instructionCount++;
  }
}

void Program::generate(ofstream & of)
{
  for(int i = 0; i < instructionCount; i++)
  {
    // output the 32-bit hex values to the output file
    of << setfill('0') << setw(8) << hex << ins[i]->encode() << endl;
  }
}

void Program::print()
{
  cout << endl;  // negative space!
  for(int i = 0; i < instructionCount; i++)
    ins[i]->print();
  cout << endl;  // a space between program and table for pretty-tude
  ins[0]->printSymbols();
}

