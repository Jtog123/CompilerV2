//
// Created by jtog8 on 12/6/2024.
//

#ifndef COMPILERV2_OPCODES_HPP
#define COMPILERV2_OPCODES_HPP

enum  OpCodes {

    OP_LOAD, //0
    OP_STORE, // 1
    OP_LOADI, // 2
    OP_ADD, // 3
    OP_SUB, // 4
    OP_MULT, // 5
    OP_LSHIFT, // 6
    OP_RSHIFT, // 7
    OP_OUTPUT, // 8
    OP_NOP, // 9
    OP_TOSS // 10 used for tokens that are not operations like comments and newlines etc...

};

#endif //COMPILERV2_OPCODES_HPP
