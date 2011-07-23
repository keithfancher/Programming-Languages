//****************************************************************************
// File  : Instruction.java
// Author: Keith T. Fancher
// Date  : 03/17/04
// Class : CS3490
//
// Purpose: The Instruction class.  Holds a single instruction, and lets you
//   do stuff with it.  You can print it, or encode it, or all SORTS of neat
//   things.  It's even got derived classes!  It does an ol' heart good...
//****************************************************************************


abstract class Instruction
{
  public Instruction(String l, String o, String f0, String f1)
  {
    label = l;
    opcode = o;
    field0 = f0;
    field1 = f1;

    address = addressCounter++;

    if(label.length() > 0)
      symbolTable.addSymbol(label, address);
  }

  public abstract int encode();

  public void print()
  {
    System.out.println(label + "\t" + opcode + "\t" + field0 + "\t" + field1);
  }

  public static void printSymbols()
  {
    symbolTable.print();
  }

  protected boolean isLabel(String opcode)
  {
    if(Character.isLetter(opcode.charAt(0)))
      return true;
    return false;
  }
  
  protected abstract int getOpcode();

  private static int addressCounter = 0;
  protected int address;
  protected String label;
  protected String opcode;
  protected String field0;
  protected String field1;
  protected static SymbolTable symbolTable = new SymbolTable();

}


//
// INSTRUCTION TYPES
//
//
abstract class AType extends Instruction
{
  public AType(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}
  
  public int encode()
  {
    int ret = 0;
    int f0 = 0;  // field0, either an address or immediate value
    
    ret = getOpcode();
    ret <<= 24;  // shift opcode left

    if(isLabel(field0))  // if label then f0 = the address
      f0 = symbolTable.getAddress(field0);
    else  // otherwise f0 = the immediate value
      f0 = (new Integer(field0)).intValue();

    ret |= f0;  // bitwise or the opcode and field0
    
    return ret;
  }
}
abstract class BType extends Instruction
{
  public BType(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  public int encode()
  {
    int ret = 0;
    int f0 = 0;
    int f1 = 0;

    int f0_mask = 0x000000ff;
    int f1_mask = 0x0000ffff;

    ret = getOpcode();
    ret <<= 24;  // shift opcode left

    f0 = (new Integer(field0)).intValue(); // get the immediate value (field0)
    f0 &= f0_mask;  // make sure to ditch leading f's if f0 is negative
    f0 <<= 16;      // move it to the proper place

    ret |= f0;  // bitwise or the opcode and field0

    if(isLabel(field1))  // if it's a label then get the address
    {
      f1 = symbolTable.getAddress(field1);
      f1 -= (address + 1);
    }
    else
      f1 = (new Integer(field1)).intValue();

    f1 &= f1_mask;  // gets rid of the tons of leading f's if f1 is negative

    ret |= f1;  // bitwise opcode, f0, and f1
    
    return ret;
  }
}
abstract class CType extends Instruction
{
  public CType(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  public int encode()
  {
    int ret = 0;

    ret = getOpcode();
    ret <<= 24;  // shift opcode left

    return ret;
  }
}
abstract class DType extends Instruction
{
  public DType(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  public int encode()
  {
    return (new Integer(field0)).intValue();  // just returns the number for .fill
  }
}


//
// A TYPES
//
//
class Add extends AType
{
  public Add(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  protected int getOpcode()
  {return 1;}
}
class Load extends AType
{
  public Load(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  protected int getOpcode()
  {return 2;}
}
class Store extends AType
{
  public Store(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  protected int getOpcode()
  {return 3;}
}

//
// B TYPES
//
//
class Beq extends BType
{
  public Beq(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  protected int getOpcode()
  {return 4;}
}

class Bne extends BType
{
  public Bne(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  protected int getOpcode()
  {return 5;}
}

//
// C TYPES
//
//
class Halt extends CType
{
  public Halt(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}

  protected int getOpcode()
  {return 6;}
}

//
// D TYPES
//
//
class Fill extends DType
{
  public Fill(String label, String opcode, String field0, String field1)
  {super(label, opcode, field0, field1);}
  
  protected int getOpcode()
  {return 0;}
}

