//
// Created by jtog8 on 9/25/2024.
//

#ifndef COMPILERV2_TOKEN_HPP
#define COMPILERV2_TOKEN_HPP
#include "TokenType.hpp"
#include <string>
#include "OpCodes.hpp"

using namespace std;
class Token {

    private:
        TokenType tokenType;
        OpCodes opCode;
        string lexeme;


    public:
        Token();
        //void setToken(TokenType type, string lex);
        void setToken(TokenType type, string lex, OpCodes opcode);
        TokenType getTokenType();
        string getLexeme();
        OpCodes getOpCodeType();
        void print();



};


#endif //COMPILERV2_TOKEN_HPP
