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

    } while( token.getLexeme() != "eof");

    //while (token.getLexeme() != "eof") {
    //    token = myScanner.getToken();
    //    cout << "Tokens is: " << endl;
    //    token.print();
    //}


    cout << "it ended" << endl;
    /*
    for(auto token : myScanner.tokenStream) {
        cout << "Token is: " << token.second << endl;

        if(token.first == TokenType::ARITHOP) {
            cout << "CHECKING WE got Airthop" << endl;
        }
    }
     */
}
