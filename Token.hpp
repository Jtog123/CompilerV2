//
// Created by jtog8 on 9/25/2024.
//

#ifndef COMPILERV2_TOKEN_HPP
#define COMPILERV2_TOKEN_HPP
#include "TokenType.hpp"
#include <string>

using namespace std;
class Token {

    private:
        TokenType tokenType;
        string lexeme;

    public:
        Token();
        void setToken(TokenType type, string lex);
        TokenType getTokenType();
        string getLexeme();
        void print();



};


#endif //COMPILERV2_TOKEN_HPP
