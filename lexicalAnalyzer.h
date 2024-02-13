#include <string>
#include <iostream>
#include "token.h"

using namespace std;

#ifndef lexicalAnalyzer_H
#define lexicalAnalyzer_H

class lexicalAnalyzer{
    private:
        const string input;
        size_t position;
        int lineCnt = 0;

        Token tokenIdentifierOrKeyword();
        Token tokenNumber();
        Token tokenOpOrPunc();
        Token createErrorToken(const string& message);
        void skipSingleLineComment();
        void skipMultiLineComment();

    public:
        lexicalAnalyzer(const string& input) : input(input), position(0) {}

        Token getNextToken();
};

#endif