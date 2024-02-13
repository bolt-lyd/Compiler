#include "inFile.h"

bool inFile::attachFile(string s){
    std::ifstream input(s);
    if (!input){
        std::cerr << "Error opening file \n";
        return false;
    }
    return true;
}

char inFile::getChar(){
    char c = fileContent[filePlace];
    filePlace++;
    return c;
}

void inFile::ungetChar(char c){
    filePlace--;
}

void inFile::incLineCnt(){
    lineCnt++;
}

int inFile::getLineCnt(){
    return lineCnt;
}

// void inFile::closeFile(){
//     input.close();
// }