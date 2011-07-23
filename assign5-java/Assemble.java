//****************************************************************************
// File  : Assemble.java
// Author: Keith T. Fancher
// Date  : 03/17/04
// Class : CS3490
//
// Purpose: The class behind it all... assembles like it was a prime-time
//   assembling machine, with nothing on its mind but assembling its friggin'
//   brains out.
//****************************************************************************


import java.io.*;


class Assemble
{
  public static void main(String [] argv) throws IOException
  {
    Program p = new Program();
    FileReader inf;
    FileWriter outf;
    
    if(argv.length != 1)
    {
      System.err.println("Usage: Assemble <filename>");
      System.exit(1);
    }

    FileHandle f = new FileHandle(argv[0]);
    inf  = f.openInputFile();
    outf = f.openOutputFile();

    // read in the program
    p.read(inf);

    // print the program and the symbol table
    p.print();

    // generate the hex and output to the output file
    p.generate(outf);

    f.closeFiles(inf, outf);

    System.out.println("Assembled code can be found in: " + f.getOutputFileName());
  }
}
