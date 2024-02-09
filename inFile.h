#include <string>
#include <iostream>
#include <fstream>
using namespace std;


// look into how this is done better?
class inFile{
    private:
        file filePtr = NULL; // the input file
        string fileName;
        string fileContent;
        int filePlace = 0;
        int lineCnt = 0; // the line count; initialized to zero
    public:
        bool attachFile(string); // open the named file
        char getChar(); // get the next character
        void ungetChar(char); // push character back to the input file string
        void incLineCnt();
        int getLineCnt();
        void closeFile();
};