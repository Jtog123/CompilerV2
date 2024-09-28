//
// Created by jtog8 on 9/21/2024.
//

#ifndef COMPILERV2_PARSER_HPP
#define COMPILERV2_PARSER_HPP

#include "scanner.hpp"
#include <string>

using namespace std;

class Parser {

public:
    Parser(const string& filePath) : myScanner(filePath) {
        // Initialize the Parser
    }

    void printTokens();

private:
    Scanner myScanner;

};


#endif //COMPILERV2_PARSER_HPP
