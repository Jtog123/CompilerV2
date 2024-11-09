//
// Created by jtog8 on 9/21/2024.
//

#ifndef COMPILERV2_PARSER_HPP
#define COMPILERV2_PARSER_HPP

#include "scanner.hpp"
#include <string>
#include <vector>

using namespace std;

/*
 * Arithop reg coma reg into reg
 * Loadi constant into reg
 * output constant
 * nop
 */

class Parser {

public:
    Parser(const string& filePath) : myScanner(filePath) {
        // Initialize the Parser
    }

    void getTokens();
    void parse();


private:
    Scanner myScanner;
    vector <Token> tokenVect;
    int current = 0;
    int _lineNumber = 1;

    void incrementLineNumber();
    int getLineNumber();

    Token advance();
    Token previous();
    Token peek();
    bool isAtEnd();


    void validateLoadI();
    void validateMemop();
    void validateNop();
    void validateArithop();
    void validateOutput();

};


#endif //COMPILERV2_PARSER_HPP
