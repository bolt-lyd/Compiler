#include "token.h"

void token::setTokenType(tokenType tk){
    tt = tk;
}

tokenType token::getTokenType(){
    return tt;
}

void token::setTokenString(string s){
    tokStr = &s;
}

string token::getTokenString(){
    return *tokStr;
}