//
// Created by jtog8 on 9/25/2024.
//

#include "Token.hpp"
#include <iostream>

using namespace std;

Token::Token(): tokenType(TBD), lexeme("") {
    // init empty token
}

void Token::setToken(TokenType type, string lex, OpCodes opCo) {
    tokenType = type;
    lexeme = lex;
    opCode = opCo;
}

OpCodes Token::getOpCodeType() {
    return opCode;
}

string Token::getLexeme() {
    return lexeme;
}

TokenType Token::getTokenType() {
    return tokenType;
}

void Token::print() {
    cout << "Token is: " << lexeme << endl;
}
