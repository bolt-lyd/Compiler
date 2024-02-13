#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "lexicalAnalyzer.h"
using namespace std;


int main() {
    string input = "if (x == 5) { y = 10; } else { y = 20; }";

    lexicalAnalyzer lexer(input);

    Token token;
    do {
        token = lexer.getNextToken();
        cout << "Token type: ";
        switch (token.type) {
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
        cout << ", Value: " << token.value << endl;
    } while (token.type != tokenType::ERROR && token.type != tokenType::ERROR);
    
    return 0;
}


// main(){
//     //file and take in
//     inFile File;
//     string s = "sillyFile.txt";
//     File.attachFile(s);


//     cout << "Start scanning"
//     tok = scan();
    
//     File.closeFile();
//     return 0;
// }