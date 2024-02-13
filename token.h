#include <string>
#include <unordered_map>
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

// class tokenmark{
//     mark tmUnionType; // some union type that will evolve as the solution progresses.
//     // many possibilities here, this could instead be a base type
//     // for a bunch of derived instances.
// };

// class token{
//     private:
//         tokenType tt;

//         // ASCII string rep of token
//         string *tokStr;

//     public:
//         void setTokenType(tokenType);
//         tokenType getTokenType();
        
//         void setTokenString(string);
//         string getTokenString();

//         //"complex data type that records secondary info about token"
//         tokenmark *tm = nullptr; 
// };  



/* can be used instead of above for more capabilites
class token : token_id // derived from token class
string: *tokStr
end class

class token : token_function
string: *tokStr
token<>: argList // looking ahead: we will be adding type info to our tokens
token: returnType // do not put these in yet, just be forwarned
end class
*/