#include <string>
#include <iostream>
#include "token.h"
#include "symbolTable.h"

using namespace std;

class lexicalAnalyzer{
    private:
        const string input;
        size_t position;
        int lineCnt = 0;

        Token tokenIdentifierOrKeyword();
        Token tokenNumber();
        Token tokenOpOrPunc();
        Token createErrorToken(const string& message);

    public:
        lexicalAnalyzer(const string& input) : input(input), position(0) {}

        Token getNextToken();
};