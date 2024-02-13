#include "lexicalAnalyzer.h"
#include "symbolTable.h"
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

Token lexicalAnalyzer::getNextToken(){
    while(position < input.length()){
        char currentChar = input[position];

        if(isspace(currentChar)){
            position++;
            if(currentChar == '\n'){
                lineCnt++;
            }
            continue;
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