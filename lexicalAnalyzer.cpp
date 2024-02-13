#include "lexicalAnalyzer.h"

//#include "inFile.h"

Token lexicalAnalyzer::tokenIdentifierOrKeyword(){
    string identifier;
    while (position < input.length() && (isalnum(input[position]) || input[position] == '_')) {
        identifier += input[position++];
    }

    if (hashTable.find(identifier) != hashTable.end()) {
        return {hashTable[identifier], identifier};
    } else {
        // If identifier not found in the hash table, add it
        hashTable[identifier] = tokenType::IDENTIFIER;
        return {tokenType::IDENTIFIER, identifier};
    }
}

Token lexicalAnalyzer::tokenNumber(){
    string number;
    while (position < input.length() && isdigit(input[position])) {
        number += input[position++];
    }
    return {tokenType::NUMBER, number};
}

Token lexicalAnalyzer::tokenOpOrPunc(){
    string punc;
    while(position < input.length() && ispunct(input[position])){
        punc += input[position++];
    }
    if (hashTable.find(punc) != hashTable.end()) {
        return {hashTable[punc], punc};
    }
    else{
        return createErrorToken("Unrecognized Operator or Punctuation");
    }
}

Token lexicalAnalyzer::createErrorToken(const string& message) {
    return {tokenType::ERROR, message};
}

void lexicalAnalyzer::skipSingleLineComment() {
    position += 2;
    while (position < input.length() && input[position] != '\n') {
        position++;
    }
    lineCnt++;
}

void lexicalAnalyzer::skipMultiLineComment() {
    position += 2; // Skip the '/*'
    while (position + 1 < input.length() && !(input[position] == '*' && input[position + 1] == '/')) {
        position++; // Skip until '*/' is found
        if(input[position] == '\n'){
                lineCnt++;
            }
    }
    position += 2; // Skip the '*/'
}


Token lexicalAnalyzer::getNextToken(){
    while(position < input.length()){
        char currentChar = input[position];

        if(isspace(currentChar)){
            position++;
            if(currentChar == '\n'){
                lineCnt++;
            }
            continue;
        }else if (currentChar == '/') {
                    // Check for comments
                    if (position + 1 < input.length() && input[position + 1] == '/') {
                        skipSingleLineComment();
                        continue;
                    } else if (position + 1 < input.length() && input[position + 1] == '*') {
                        skipMultiLineComment();
                        continue;
                    }
                }

        if (isalpha(currentChar)) {
            return tokenIdentifierOrKeyword();
        }

        if(isdigit(currentChar)){
            return tokenNumber();
        }

        if(ispunct(currentChar)){
            return tokenOpOrPunc();
        }

        return createErrorToken("Unrecognized character");
    }

    return Token{tokenType::eof};
}