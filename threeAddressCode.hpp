//
// Created by jtog8 on 12/7/2024.
//

#ifndef COMPILERV2_THREEADDRESSCODE_HPP
#define COMPILERV2_THREEADDRESSCODE_HPP
#include "OpCodes.hpp"

struct threeAddressCode {
    int lineNumber;
    OpCodes opC;
    int operand1;
    int operand2;
    int operand3;


};

#endif //COMPILERV2_THREEADDRESSCODE_HPP
