using namespace std;
#include <iostream>
#include <fstream>
#include "FileHandle.h"

FileHandle::FileHandle(char * filename)
{
    inputFile = filename;
}
              
void FileHandle::openInputFile(ifstream & inf)
{
    if (badFileName())
    {
        cerr << inputFile << " must be a least 5 characters and end with "
             << "a .asm extension\n";
        cerr << "Usage: assemble <filename>\n";
        exit(1);
    }
    inf.open(inputFile.c_str());
    if (inf.fail())
    {
        cerr << "Can not open: " << inputFile << endl;
        cerr << "Usage: ma <filename>\n";
        exit(1);
    }
}

bool FileHandle::badFileName()
{
    int i;
    i = inputFile.find(".asm", 1);
    //make sure that the .asm is at the end of the string
    if (inputFile.size() < 5 || i != inputFile.size() - 4)
        return true;
    else
        return false;
}

void FileHandle::buildOutputFileName()
{
    int i;
    //find the location of the .asm
    i = inputFile.find(".asm", 1);
    outputFile = inputFile.replace(i, 4, ".hex");
}


void FileHandle::openOutputFile(ofstream & outf)
{
    buildOutputFileName();
    outf.open(outputFile.c_str());
    if (outf.fail())
    {
        cerr << "Can not open output file: " << outputFile << endl;
        cerr << "Usage: ma <filename>\n";
        exit(1);
    }
}

void FileHandle::closeFiles(ifstream & inf, ofstream & outf)
{
   inf.close();
   outf.close();
}
