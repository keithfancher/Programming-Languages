//****************************************************************************
// File  : FileHandle.java
// Author: Keith T. Fancher
// Date  : 03/17/04
// Class : CS3490
//
// Purpose: The FileHandle class used by the assembler.  It handles files.
//****************************************************************************


import java.io.*;


class FileHandle
{
  private String inputFile;
  private String outputFile;

  private boolean badFileName()
  {
    // make sure it ends with .asm 'n such
    if(!inputFile.endsWith(".asm") || inputFile.length() < 5)
      return true;
    return false;
  }

  private void buildOutputFileName()
  {
    // this is a nifty statement
    outputFile = new String((inputFile.substring(0, inputFile.lastIndexOf('.') + 1)).concat("hex"));
  }


  public FileHandle(String filename)
  {
    inputFile = new String(filename);
  }

  public FileReader openInputFile() throws IOException
  {
    if(badFileName())
    {
      System.err.println("Filename must be at least 5 characters long and end with .asm");
      System.err.println("Usage: Assemble <filename>");
      System.exit(1);
    }

    // If you put this in a try block and catch the exception you won't have anything to
    // return and Java gets mad, even though it NEVER GETS TO THAT PART OF THE CODE...
    // It's especially annoying because there doesn't seem to be any way to specify an empty
    // FileReader, which means manual error checking is pretty much out of the question.
    // Why oh why can't it just trust me to handle my own friggin' exceptions???
    return (new FileReader(inputFile));
  }

  public FileWriter openOutputFile() throws IOException
  {
    buildOutputFileName();
    return (new FileWriter(outputFile));
  }

  public void closeFiles(FileReader infile, FileWriter outfile) throws IOException
  {
    infile.close();
    outfile.close();
  }

  public String getOutputFileName()
  {
    return outputFile;
  }
}

