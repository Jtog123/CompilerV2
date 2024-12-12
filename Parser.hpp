//
// Created by jtog8 on 9/21/2024.
//

#ifndef COMPILERV2_PARSER_HPP
#define COMPILERV2_PARSER_HPP

#include "scanner.hpp"
#include <string>
#include <vector>
#include "threeAddressCode.hpp"


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
    vector<OpCodes> getOpCodes();
    int getLineNumber();
    void parse();
    const vector<threeAddressCode>& getParsedInstructions() const;
    //vect


private:
    Scanner myScanner;
    vector <Token> tokenVect;
    int current = 0;
    int _lineNumber = 1;
    vector<OpCodes> opCodeVect;
    vector<threeAddressCode> parsedInstructions;

    void incrementLineNumber();
    //int getLineNumber();

    Token advance();
    Token previous();
    Token peek();
    bool isAtEnd();


    void validateLoadI(threeAddressCode* irLine);
    void validateMemop(threeAddressCode* irLine);
    void validateNop(threeAddressCode* irLine);
    void validateArithop(threeAddressCode* irLine);
    void validateOutput(threeAddressCode* irLine);

};


#endif //COMPILERV2_PARSER_HPP
