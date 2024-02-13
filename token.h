#include <string>
using namespace std;

enum tokenType {PLUS, MINUS, IF_RW, LOOP_RW, END_RW, L_PAREN, R_PAREN,
                L_BRACKET, R_BRACKET, NUMBER, IDENTIFIER, ERROR, eof,
                SEMICOLON, ASSIGN, DIVIDE, MULT };

struct Token {
    tokenType type;
    string value;
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