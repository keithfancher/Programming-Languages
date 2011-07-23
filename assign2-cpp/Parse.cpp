//****************************************************************************
// File  : Parse.cpp
// Author: Keith T. Fancher
// Date  : 02/09/04
// Class : CS3490
//
// Purpose: The implementation for the Parse class, which handles the (gasp!)
//   parsing for our crazy little assembler.
//****************************************************************************


using namespace std;

#include <string.h>
#include <fstream>

#include "Instruction.h"
#include "Parse.h"


Instruction * Parse::parse(ifstream & f)
{
  const int MAXLEN = Instruction::INSTR_LEN;  // the max length of a field
  
  Instruction * return_instr = NULL;  // the return value
  char instring[MAXLEN] = {0};        // necessary temp string
  bool hasLabel = false;              // makes things easier down below

  char label[MAXLEN]    = {0};
  char opcode[MAXLEN]   = {0};
  char field0[MAXLEN]   = {0};
  char field1[MAXLEN]   = {0};

  f >> instring;

  if(!isOpcode(instring))  // must be a label
  {
    strncpy(label, instring, MAXLEN);
    f >> instring;  // done w/ label, read next field (opcode)
    hasLabel = true;
  }

  strncpy(opcode, instring, MAXLEN);  // put opcode into the string

  // A, B, and D types all use field0
  if(isAType(opcode) || isBType(opcode) || isDType(opcode))
    f >> field0;
  
  if(isAType(opcode))
  {
    if(isAdd(opcode))
      return_instr = new Add( (hasLabel ? label : NULL), opcode, field0);
    if(isLoad(opcode))
      return_instr = new Load( (hasLabel ? label : NULL), opcode, field0);
    if(isStore(opcode))
      return_instr = new Store( (hasLabel ? label : NULL), opcode, field0);
  }
  if(isBType(opcode))
  {
    f >> field1;  // only B types need field1

    if(isBeq(opcode))
      return_instr = new Beq( (hasLabel ? label : NULL), opcode, field0, field1);
    if(isBne(opcode))
      return_instr = new Bne( (hasLabel ? label : NULL), opcode, field0, field1);
  }
  if(isCType(opcode))
  {
    if(isHalt(opcode))
      return_instr = new Halt( (hasLabel ? label: NULL), opcode);
  }
  if(isDType(opcode))
  {
    if(isFill(opcode))
      return_instr = new Fill( (hasLabel ? label: NULL), opcode, field0);
  }

  return return_instr;
}

bool Parse::isOpcode(char * field)
{
  if(isAType(field) || isBType(field) || isCType(field) || isDType(field))
    return true;
  return false;
}

bool Parse::isAType(char * opcode)
{
  if(isAdd(opcode) || isLoad(opcode) || isStore(opcode))
    return true;
  return false;
}
bool Parse::isBType(char * opcode)
{
  if(isBeq(opcode) || isBne(opcode))
    return true;
  return false;
}
bool Parse::isCType(char * opcode)
{
  return isHalt(opcode);  // halt is the only CType
}
bool Parse::isDType(char * opcode)
{
  return isFill(opcode);  // fill is the only DType
}


bool Parse::isAdd(char * opcode)
{
  if(!strcmp(opcode, "add"))
    return true;
  return false;
}
bool Parse::isLoad(char * opcode)
{
  if(!strcmp(opcode, "load"))
    return true;
  return false;
}
bool Parse::isStore(char * opcode)
{
  if(!strcmp(opcode, "store"))
    return true;
  return false;
}
bool Parse::isBeq(char * opcode)
{
  if(!strcmp(opcode, "beq"))
    return true;
  return false;
}
bool Parse::isBne(char * opcode)
{
  if(!strcmp(opcode, "bne"))
    return true;
  return false;
}
bool Parse::isHalt(char * opcode)
{
  if(!strcmp(opcode, "halt"))
    return true;
  return false;
}
bool Parse::isFill(char * opcode)
{
  if(!strcmp(opcode, ".fill"))
    return true;
  return false;
}

