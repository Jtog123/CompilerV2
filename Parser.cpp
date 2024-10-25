//
// Created by jtog8 on 9/21/2024.
//

#include "Parser.hpp"
#include <iostream>
#include "TokenType.hpp"

using namespace std;

/*
 * Arithop reg coma reg into reg
 * Loadi constant into reg
 * output constant
 * nop
 */


void Parser::getTokens() {

    Token token;

    do {
        token = myScanner.getToken();
        tokenVect.push_back(token);
        //token.print();

    } while(token.getLexeme() != "eof");

    //for(auto& t : tokenVect) {
    //    cout << t.getLexeme() << endl;
    //}
    //cout << "it ended" << endl;

}

void Parser::parse() {
    // fix later dont assume there are tokens
    Token token;

    do {
        token = advance();
        cout << token.getLexeme();

        switch (token.getTokenType()) {
            case TokenType::LOADI :
                validateLoadI();
                break;
            default:
                cout << "Ending" << endl;
                break;
        }

    } while (!isAtEnd()); //token.getTokenType() != TokenType::_EOF

}

//Advances position pointer forward and returns the previous Token
Token Parser::advance() {
    //increment index return the token
    if(!isAtEnd()) {
        ++current;
        return previous();
    }

}

bool Parser::validateLoadI() {
    //Loadi constant into reg
    // check structure
    cout << "Validating LoadI" << endl;
    return true;
}

Token Parser::previous() {
    return tokenVect.at(current - 1);
}

//Peeks at token in vect
Token Parser::peek() {
    return tokenVect.at(current);
}

bool Parser::isAtEnd() {
    return peek().getTokenType() == TokenType::_EOF;
}


