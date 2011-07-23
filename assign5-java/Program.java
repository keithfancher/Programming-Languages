//****************************************************************************
// File  : Program.java
// Author: Keith T. Fancher
// Date  : 03/17/04
// Class : CS3490
//
// Purpose: The Program class, which does neat things like reads in the file,
//   calls the parser, and generates the output hex.  Although in actuality
//   it's just calling other classes that do all the work because it is a
//   slacker.  In this respect we are very similar, this class and I...
//****************************************************************************


import java.io.*;
import java.util.*;


class Program
{
  public Program()
  {
    instructionCount = 0;
    p = new Parse();
    ins = new LinkedList();
  }

  public void read(FileReader f) throws IOException
  {
    BufferedReader reader = new BufferedReader(f);
    while(reader.ready())
    {
      ins.add(p.parse(reader.readLine()));
      instructionCount++;
    }
  }

  public void generate(FileWriter f)
  {
    PrintWriter outfile = new PrintWriter(f);

    // output the hex values
    for(int i = 0; i < instructionCount; i++)
    {
      StringBuffer buf = new StringBuffer(Integer.toHexString(((Instruction)ins.get(i)).encode()));
      int tmp = 8 - buf.length();  // putting this in the for breaks it somehow
      for(int j = 0; j < tmp; j++)  // pad w/ zeros
        buf.insert(0, "0");
      outfile.println(buf.toString());
    }
  }

  public void print()
  {
    for(int i = 0; i < instructionCount; i++)
      ((Instruction)ins.get(i)).print();
    System.out.println();
    Instruction.printSymbols();
  }
  

  private LinkedList ins;  // I made it a LinkedList because I think they ROCK
  private Parse p;  // haha... private parse
  private int instructionCount;
}

