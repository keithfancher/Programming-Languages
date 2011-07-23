//****************************************************************************
// File  : Parse.java
// Author: Keith T. Fancher
// Date  : 03/17/04
// Class : CS3490
//
// Purpose: The implementation for the Parse class, which handles the (gasp!)
//   parsing for our crazy little assembler.
//****************************************************************************


import java.util.*;


class Parse
{
  public Instruction parse(String instring)
  {
    String label = new String();  // have to init these here because Java is nuts
    String opcode = new String();
    String field0 = new String();
    String field1 = new String();
        
    StringTokenizer tokenizer = new StringTokenizer(instring);

    String tmp = new String(tokenizer.nextToken());
    if(!isOpcode(tmp)) // must be a label
    {
      label = tmp;
      tmp = tokenizer.nextToken();
    }

    opcode = tmp; // opcode!

    // A, B, and D types all use field0
    if(isAType(opcode) || isBType(opcode) || isDType(opcode))
      field0 = tokenizer.nextToken();
      
    if(isAType(opcode))
    {
      if(isAdd(opcode))
        return (new Add(label, opcode, field0, field1));
      if(isLoad(opcode))
        return (new Load(label, opcode, field0, field1));
      if(isStore(opcode))
        return (new Store(label, opcode, field0, field1));
    }
    if(isBType(opcode))
    {
      field1 = tokenizer.nextToken(); // only B types need field1
        
      if(isBeq(opcode))
        return (new Beq(label, opcode, field0, field1));
      if(isBne(opcode))
        return (new Bne(label, opcode, field0, field1));
    }
    if(isCType(opcode))
    {
      if(isHalt(opcode))
        return (new Halt(label, opcode, field0, field1));
    }
    if(isDType(opcode))
    {
      if(isFill(opcode))
        return (new Fill(label, opcode, field0, field1));
    }

    // It never ever ever ever ever ever gets here, but Java wants me to return SOMETHING...
    // To me, that is dumb.  Might as well be a Fill, right?  SURE!
    return (new Fill(label, opcode, field0, field1));
  }


  private boolean isOpcode(String field)
  {
    if(isAType(field) || isBType(field) || isCType(field) || isDType(field))
      return true;
    return false;
  }

  private boolean isAType(String opcode)
  {
    if(isAdd(opcode) || isLoad(opcode) || isStore(opcode))
      return true;
    return false;
  }
  private boolean isBType(String opcode)
  {
    if(isBeq(opcode) || isBne(opcode))
      return true;
    return false;
  }
  private boolean isCType(String opcode)
  {
    return isHalt(opcode);
  }
  private boolean isDType(String opcode)
  {
    return isFill(opcode);
  }

  private boolean isAdd(String opcode)
  {
    if(opcode.compareTo("add") == 0)
      return true;
    return false;
  }
  private boolean isLoad(String opcode)
  {
    if(opcode.compareTo("load") == 0)
      return true;
    return false;
  }
  private boolean isStore(String opcode)
  {
    if(opcode.compareTo("store") == 0)
      return true;
    return false;
  }
  private boolean isBeq(String opcode)
  {
    if(opcode.compareTo("beq") == 0)
      return true;
    return false;
  }
  private boolean isBne(String opcode)
  {
    if(opcode.compareTo("bne") == 0)
      return true;
    return false;
  }
  private boolean isHalt(String opcode)
  {
    if(opcode.compareTo("halt") == 0)
      return true;
    return false;
  }
  private boolean isFill(String opcode)
  {
    if(opcode.compareTo(".fill") == 0)
      return true;
    return false;
  }
  
}

