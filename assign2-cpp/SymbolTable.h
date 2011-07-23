/* Class: SymbolTable
   Description: Provides methods for maintaining a symbol table of 
                symbols consisting of a string label and an unsigned
                int address.  Maximum number of symbols that can be
                added is 50.
   Public Methods:
        SymbolTable();
        void addSymbol(string label, unsigned int address);
        unsigned int getAddress(string label);
        void print();
*/


#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__


class SymbolTable
{
    private:
        struct symbol 
        {
            string label;
            unsigned int address;
        };
        typedef struct symbol SymbolType;
        static const int MAXLEN = 50;      //maximum length of table
        SymbolType * symbols[MAXLEN];      //actual symbol table
        unsigned int symbolCount;
    public:
        SymbolTable();
        /* Name:  SymbolTable
           Description:  constructor.  Initializes the number of the
                         symbols in the table to 0.
           Parameters:  none
           Returns: none
           Pre-Conditions: none
           Post-Conditions: sets private symbolCount to 0
        */

        void addSymbol(string label, unsigned int address);
        /* Name:  addSymbol
           Description:  Adds a symbol consisting of the two method 
                         parameters to the symbol table.
           Parameters:  string label and unsigned int address
           Returns: none
           Pre-Conditions: constructor must be called first
           Post-Conditions: increments symbolCount by 1 and modifies
                            private symboltable
        */

        unsigned int getAddress(string label);
        /* Name:  getAddress
           Description:  Looks for the symbol with this label in the
                         symbol table and returns the associated address.
                         If symbols is not found, an error message is 
                         printed and the program is terminated.
           Parameters:  string label 
           Returns: unsigned int address associated with that label
           Pre-Conditions: constructor must be called first
           Post-Conditions: none
        */

        void print();
        /* Name:  print
           Description:  Prints the contents of the symbol table
           Parameters:  none 
           Returns: none
           Pre-Conditions: constructor must be called first
           Post-Conditions: none
        */
};


#endif

