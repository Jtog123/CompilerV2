//
// Created by jtog8 on 9/7/2024.
//




#ifndef COMPILERV2_TOKENTYPE_HPP
#define COMPILERV2_TOKENTYPE_HPP

//C++ wont let me use EOF
// Already defined?

enum TokenType{
    MEMOP, // 0
    LOADI, // 1
    ARITHOP, // 2
    OUTPUT, // 3
    NOP, // 4
    CONSTANT, // 5
    REGISTER, // 6
    COMMA, // 7
    INTO, // 8
    _EOF, // 9
    EOL, // 10
    COMMENT, // 11
    TBD, // 12,
    LEXICAL_ERROR,
    PARSING_ERROR

};

#endif //COMPILERV2_TOKENTYPE_HPP
