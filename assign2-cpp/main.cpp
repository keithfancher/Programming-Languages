//****************************************************************************
// File  : main.cpp
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The main() for our friendly neighborhood assembler.
//****************************************************************************


using namespace std;

#include <string>
#include <fstream>
#include <iostream>

#include "FileHandle.h"
#include "SymbolTable.h"
#include "Instruction.h"
#include "Parse.h"
#include "Program.h"

int main(int argc, char ** argv)
{
  Program p;
  ifstream inf;
  ofstream outf;

  if (argc != 2)
  {
    cerr << "Usage: assemble <filename>\n";
    exit(1);
  }

  FileHandle f(argv[1]);
  f.openInputFile(inf);          
  f.openOutputFile(outf);     

  //read in the program
  p.read(inf);

  //print the program and the symbol table
  p.print();

  //generate the hex and output to the output file
  p.generate(outf);

  // show where the code is lizzity-located
  string fname = argv[1];
  int i = fname.find(".asm", 1);
  cout << "Assembled code can be found in: " << fname.replace(i, 4, ".hex") << endl;
  
  f.closeFiles(inf, outf);
}

