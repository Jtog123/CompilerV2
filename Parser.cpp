//
// Created by jtog8 on 9/21/2024.
//

#include "Parser.hpp"
#include <iostream>

using namespace std;

void Parser::printTokens() {

    Token token;

    do {
        token = myScanner.getToken();
        token.print();

    } while(token.getLexeme() != "eof");

    cout << "it ended" << endl;

}
