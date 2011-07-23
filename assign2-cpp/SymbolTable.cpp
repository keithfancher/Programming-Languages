
using namespace std;
#include <iostream>
#include <string>
#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
    symbolCount = 0;
}

void SymbolTable::addSymbol(string l, unsigned int a)
{
    SymbolType * s = new SymbolType();
    s->label = l;
    s->address = a;
    if (symbolCount == MAXLEN)
    {
        cerr << "Symbol Table Full\n";
        exit(1);
    }
    symbols[symbolCount] = s;
    symbolCount++;
}

unsigned int SymbolTable::getAddress(string label)
{
    int i;
    for (i = 0; i < symbolCount; i++)
        if (label == symbols[i]->label) return symbols[i]->address;
    cerr << "Can not find " << label << " in symbol table \n";
    exit(1);
}

void SymbolTable::print()
{
    int i;
    cout << "Label\tAddress\n";
    cout << "-----\t-------\n";
    for (i = 0; i < symbolCount; i++)
        cout << symbols[i]->label << "\t" << symbols[i]->address << endl;
    cout << endl;
}

