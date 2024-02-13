#include <string>
#include "token.h"
#include <unordered_map>

using namespace std;

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

// class symbolTable{
//     private:
//         //hashTable <token> symTab;
//         hashTable symTab;
//     public:
//         token hashLook(string); // lookup the string in the hash table and call create function if not found
//         void setToken(string); // change the token values for this symbol
// };