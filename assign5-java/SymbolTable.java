//****************************************************************************
// File  : SymbolTable.java
// Author: Keith T. Fancher
// Date  : 03/17/04
// Class : CS3490
//
// Purpose: The SymbolTable class is a class I wrote that is a symbol table.
//   It is an entire table, full of symbols, and I love her.
//****************************************************************************


import java.util.*;


class SymbolTable
{
  // the symbol class
  private class SymbolType
  {
    public SymbolType(String l, int a)
    {
      label = l;
      address = a;
    }

    public String label;
    public int address;
  }
  
  static final int MAXLEN = 50;  // max length of table
  private LinkedList symbols;    // actual symbol table


  public SymbolTable()
  {
    symbols = new LinkedList();
  }

  public void addSymbol(String label, int address)
  {
    if(symbols.size() == MAXLEN)
    {
      System.err.println("Symbol table full!!!");
      System.exit(1);
    }
    else
      symbols.add(new SymbolType(label, address));
  }

  public int getAddress(String label)
  {
    for(int i = 0; i < symbols.size(); i++)
    {
      if((((SymbolType)(symbols.get(i))).label).compareTo(label) == 0)  // gotta love all this typecasting
        return ((SymbolType)symbols.get(i)).address;
    }

    System.err.println("Cannot find " + label + " in symbol table!");
    System.exit(1);

    return 0; // 'cause Java makes me
  }

  public void print()
  {
    System.out.println("Label\tAddress");
    System.out.println("-----\t-------");
    for(int i = 0; i < symbols.size(); i++)
      System.out.println( ((SymbolType)symbols.get(i)).label + "\t" + ((SymbolType)symbols.get(i)).address);
    System.out.println();
  }
}

