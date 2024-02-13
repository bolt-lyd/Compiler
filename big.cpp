#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

enum tokenType {PLUS, MINUS, IF_RW, LOOP_RW, END_RW, L_PAREN, R_PAREN,
                L_BRACKET, R_BRACKET, NUMBER, IDENTIFIER, ERROR, eof,
                SEMICOLON, ASSIGN, DIVIDE, MULT };

struct Token {
    tokenType type;
    string value;
};

unordered_map<string, tokenType> hashTable = {
    {"if", tokenType::IF_RW},
    {"else", tokenType::IF_RW},
    {"while", tokenType::LOOP_RW},
    {"for", tokenType::LOOP_RW},
    {"+", tokenType::PLUS},
    {"-", tokenType::MINUS},
    {"end", tokenType::END_RW},
    {"(", tokenType::L_PAREN},
    {")", tokenType::R_PAREN},
};

class lexicalAnalyzer{
    private:
        const string input;
        size_t position;
        int lineCnt = 0;


        Token tokenIdentifierOrKeyword(){
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

        Token tokenNumber(){
            string number;
            while (position < input.length() && isdigit(input[position])) {
                number += input[position++];
            }
            return {tokenType::NUMBER, number};
        }

        Token createErrorToken(const string& message){
            return {tokenType::ERROR, message};
        }

        Token tokenOpOrPunc(){
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

        void skipSingleLineComment() {
            position += 2;
            while (position < input.length() && input[position] != '\n') {
                position++;
            }
            lineCnt++;
        }

        void skipMultiLineComment() {
            position += 2; // Skip the '/*'
            while (position + 1 < input.length() && !(input[position] == '*' && input[position + 1] == '/')) {
                position++; // Skip until '*/' is found
                if(input[position] == '\n'){
                        lineCnt++;
                    }
            }
            position += 2; // Skip the '*/'
        }


    public:
        lexicalAnalyzer(const string& input) : input(input), position(0) {}

        Token getNextToken(){
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
};

int main() {
    string input = "if (x == 5) { y = 10; } else { y = 20; }";

    lexicalAnalyzer lexer(input);

    Token token;
    do {
        token = lexer.getNextToken();
    } while (token.type != tokenType::ERROR && token.type != tokenType::ERROR);
    cout << "\nUpdated Keyword Table:" << endl;
    for (const auto& entry : hashTable) {
        cout << entry.first << ": ";
        switch (entry.second) {
            case tokenType::PLUS:
                cout << "PLUS";
                break;
            case tokenType::MINUS:
                cout << "MINUS";
                break;
            case tokenType::IF_RW:
                cout << "IF_RW";
                break;
            case tokenType::LOOP_RW:
                cout << "LOOP_RW";
                break;
            case tokenType::L_PAREN:
                cout << "L_PAREN";
                break;
            case tokenType::R_PAREN:
                cout << "R_PAREN";
                break;
            case tokenType::L_BRACKET:
                cout << "L_BRACKET";
                break;
            case tokenType::R_BRACKET:
                cout << "R_BRACKET";
                break;
            case tokenType::NUMBER:
                cout << "NUMBER";
                break;
            case tokenType::SEMICOLON:
                cout << "SEMICOLON";
                break;
            case tokenType::ASSIGN:
                cout << "ASSIGN";
                break;
            case tokenType::DIVIDE:
                cout << "DIVIDE";
                break;
            case tokenType::MULT:
                cout << "MULT";
                break;
            
            case tokenType::IDENTIFIER:
                cout << "Identifier";
                break;
        }
        cout << endl;
    }

    return 0;
}