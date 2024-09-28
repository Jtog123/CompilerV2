//
// Created by jtog8 on 9/5/2024.
//

#ifndef COMPILERV2_SCANNER_HPP
#define COMPILERV2_SCANNER_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
//#include "TokenType.hpp"
#include "Token.hpp"

using namespace std;

class Scanner {
private:
    ifstream inputFile;
    int _lineNumber = 1;
    bool validateSpacing();


public:
    Scanner(const string& filePath);
    Token getToken();
    bool matchNextChar(char);
    void eatTillDelimiter();
    //vector<pair <TokenType, string> > tokenStream;  // TokenType, lexeme
};





#endif //COMPILERV2_SCANNER_HPP
