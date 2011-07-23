
/* Class: FileHandle
   Description: opens the input and output files needed by the Assembler
   Public Methods:  FileHandle(char *);
                    void openInputFile(ifstream & );
                    void openOutputFile(ofstream & );
                    void closeFiles(ifstream &, ofstream &);
*/
                     

#ifndef FILEHANDLE_H
#define FILEHANDLE_H
class FileHandle
{
    private:
        string inputFile;   //name of input file
        string outputFile;  //name of output file based on input file

        bool badFileName();
        /* Name: badFileName
           Description:  Checks the name of the input file in the
                         private inputFile string to determine that
                         it is at least 5 characters and ends with a .asm
                         suffix.  
           Parameters:  none
           Returns: true or false
           Pre-Conditions: called after inputFile set by FileHandle constructor
           Post-Conditions: none
        */

        void buildOutputFileName();
        /* Name: buildOutputFileName
           Description: Builds an output file name based on the value of
                        of the input file.  The name of the output file is
                        the same as the name of the input file with the
                        .asm replaced by a .hex.  
           Parameters:  none
           Returns:  none
           Pre-Conditions: called after inputFile set by FileHandle
                           constructor and badFileName called
           Post-Conditions: sets outputFile
        */
    public:
        FileHandle(char * filename);
        /* Name:  FileHandle
           Description:  class constructor
           Parameters: string used to initialize the private inputFile parameter
           Returns: none
           Pre-Conditions: none
           Post-Conditions: sets inputFile
        */

        void openInputFile(ifstream & );
        /* Name: openInputFile
           Description: Uses the private inputFile as the name of a file;
                        opens the file.  Prints error message and exits
                        program if the file open fails. 
           Parameters: ifstream reference parameter
           Output: none 
           Pre-Conditions: inputFile must have been set by constructor   
           Post-Conditions:  ifstream reference parameter attached to input file
        */

        void openOutputFile(ofstream & );
        /* Name: openOutputFile
           Description: Builds the output file name based upon the value
                        of the private input file name.  Opens output file,
                        modifying the ofstream parameter.  If the open
                        fails then an error message is printed and the
                        program is terminated.
           Parameters: ofstream reference parameter
           Returns: none
           Pre-Conditions: inputFile must have been set by constructor   
           Post-Conditions:  builds outputFile string based on value of 
                             inputFile and attaches ofstream reference 
                             parameter to output file
        */

        void closeFiles(ifstream &, ofstream &);
        /* Name: closeFiles
           Description: Closes the two file stream parameters
           Parameters: ifstream and ofstream reference parameter
           Returns: none
           Pre-Conditions: called after openInputFile and openOutputFile 
           Post-Conditions:  files streams attached to inputFile and outputFile
                             are closed.
        */
}; 
#endif              

