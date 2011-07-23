//****************************************************************************
// File  : Parse.h
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The header for the Parse class, which handles the (gasp!) parsing
//   for our crazy little assembler.  Does it not wow you?
//****************************************************************************


#ifndef __PARSE_H__
#define __PARSE_H__


class Parse
{
  public:
    // Function : Crazy crazy parse() function.  Basically does EVERYTHING.  
    // Parameter: An ifstream reference to the file to parse (one Instruction at
    //     a time, though).
    // Returns  : A pointer to an Instruction object of the correct type, chock 
    //     full of labels, opcodes, et cetera.  Returns NULL if EOF is reached.
    Instruction * parse(ifstream &);

  private:
    // All these functions just make the parsing cleaner, and
    // are pretty dern self-explanatory.
    bool isOpcode(char * field);

    bool isAType(char * opcode);
    bool isBType(char * opcode);
    bool isCType(char * opcode);
    bool isDType(char * opcode);
    
    bool isAdd(char * opcode);
    bool isLoad(char * opcode);
    bool isStore(char * opcode);
    bool isBeq(char * opcode);
    bool isBne(char * opcode);
    bool isHalt(char * opcode);
    bool isFill(char * opcode);
};


#endif

