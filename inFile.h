#include <string>
using namespace std;

class inFile{
    private:
        file filePtr = NULL; // the input file
        string fileName;
        int lineCnt = 0; // the line count; initialized to zero
    public:
        bool attachFile(string); // open the named file
        char getChar(); // get the next character
        void ungetChar(char); // push character back to the input file string
        void incLineCnt();
        void getLineCnt();
};