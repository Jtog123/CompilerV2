//
// Created by jtog8 on 9/21/2024.
//

#include "Parser.hpp"
#include <iostream>
#include "TokenType.hpp"
#include "ParsingException.hpp"

//With syntax error token if we get a syntax error token bob out with error

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


        // Only push back the OPcode if it is NOT OP_TOSS
        if(token.getOpCodeType() == 10) {
            continue;
        } else {
            opCodeVect.push_back(token.getOpCodeType());
        }

        //token.print();

    } while(token.getTokenType() != TokenType::_EOF);

    //for(auto& t : tokenVect) {
    //    cout << t.getTokenType() << endl;
    //}
    //cout << "it ended" << endl;

}

void Parser::parse() {
    // fix later dont assume there are tokens
    Token token;

    // loadI 20 => r1

    do {
        token = peek();
        cout << "Token is now " << token.getLexeme() << endl;

        switch (token.getTokenType()) {
            case TokenType::MEMOP :
                validateMemop();
                break;
            case TokenType::lOADI :
                validateLoadI();
                break;
            case TokenType::ARITHOP :
                validateArithop();
                break;
            case TokenType::OUTPUT :
                validateOutput();
                break;
            case TokenType::NOP :
                validateNop();
                break;
            case TokenType::EOL :
                advance();
                incrementLineNumber();
                break;
            case TokenType::LEXICAL_ERROR:
                throw ParsingException("Syntax Error", getLineNumber());
            default:
                cout << "Ending" << endl;
                advance();
                //throw ParsingException("Parsing Error, Invalid Starting Token");
                break;
        }

    } while (!isAtEnd());

    cout << "Parsing Complete" << endl;

}

vector<OpCodes> Parser::getOpCodes() {
    return opCodeVect;
    //return full arr or one at a time?
}

void Parser::validateArithop() {
    cout << "Validating arithop" << endl;
    advance();
    //artihop reg comma reg into reg

    Token nextToken = peek();
    if(nextToken.getTokenType() == TokenType::REGISTER) {
        cout << "Got register continue validating" << endl;

        advance();
        nextToken = peek();

        if(nextToken.getTokenType() == TokenType::COMMA) {
            cout << "Got comma continue validating" << endl;

            advance();
            nextToken = peek();

            if(nextToken.getTokenType() == TokenType::REGISTER) {
                cout << "Got register continue validating" << endl;

                advance();
                nextToken = peek();

                if(nextToken.getTokenType() == TokenType::INTO) {
                    cout << "Got into continue validating" << endl;

                    advance();
                    nextToken = peek();

                    if(nextToken.getTokenType() == TokenType::REGISTER) {
                        cout << "Got Register continue validating" << endl;

                        advance();
                        nextToken = peek();

                    }
                    else {
                        throw ParsingException("Improper grammar next token should be REGISTER", getLineNumber());
                    }

                }
                else {
                    throw ParsingException("Improper grammar next token should be INTO", getLineNumber());
                }

            }
            else {
                throw ParsingException("Improper grammar next token should be REGISTER", getLineNumber());
            }

        }
        else {
            throw ParsingException("Improper grammar next token should be COMMA", getLineNumber());
        }
    }
    else {
        throw ParsingException("Improper grammar next token should be REGISTER", getLineNumber());
    }
}



void Parser::validateMemop() {

    //MEMOP REG INTO REG

    cout << "Validating Load" << endl;
    advance();
    Token nextToken = peek();

    //cout << "Current tok is " << nextToken.getLexeme() << endl;

    if(nextToken.getTokenType() == TokenType::REGISTER) {
        cout << "Got Register continue Validating" << endl;
        advance();
        nextToken = peek();

        if(nextToken.getTokenType() == TokenType::INTO) {
            cout << "Got INTO continue validating" << endl;
            advance();
            nextToken = peek();

            if(nextToken.getTokenType() == TokenType::REGISTER) {
                cout << "Got register continue validating" << endl;
                advance();
                cout << "Valid MEMOP Grammar returning" << endl;
                return;

            }
            else {
                throw ParsingException("Improper grammar next token should be REGISTER", getLineNumber());
            }
        }
        else {
            throw ParsingException("Improper grammar, next token should be INTO", getLineNumber());
        }
    }
    else {
        throw ParsingException("Improper grammar, next token should be Register", getLineNumber());
    }



}

void Parser::validateLoadI() {
    //Loadi constant into reg
    // check structure  Loadi constant into reg

    // loadI 20 => r1 \n

    cout << "Validating LoadI" << endl;


    advance();
    Token nextToken = peek();

    if(nextToken.getTokenType() == TokenType::CONSTANT) {
        cout << "Got a Constant continue validating" << endl;
        advance();
        nextToken = peek();

        if(nextToken.getTokenType() == TokenType::INTO) {
            cout << "Got an Into continue validating" << endl;
            advance();
            nextToken = peek();

            if(nextToken.getTokenType() == TokenType::REGISTER) {
                cout << "Got a register continue validating" << endl;
                advance();
                //nextToken = peek();

                cout << "Valid LOADI grammar returning" << endl;
                return;

                /*
                if(nextToken.getTokenType() == TokenType::EOL || nextToken.getTokenType() == TokenType::_EOF) {
                    cout << "Got a new line VALID LOADI GRAMMAR return" << endl;
                    //advance();
                    cout << "Current token is " << peek().getLexeme() << endl;
                    return;
                }
                else {
                    throw ParsingException("Improper grammar, next token should be EOL");
                }
                */
            }
            else {
                throw ParsingException("Improper grammar, next token should be REGISTER", getLineNumber());
            }
        }
        else {
            throw ParsingException("Improper grammar, next token should be INTO", getLineNumber());
        }

    }
    else {
        throw ParsingException("Improper grammar, next token should be Constant", getLineNumber());
    }



}


void Parser::validateOutput() {
//* output constant
    cout << "Validating output" << endl;
    advance();

    Token nextToken = peek();

    if(nextToken.getTokenType() == TokenType::CONSTANT) {
        cout << "valid output Grammar" << endl;
        advance();
        return;
    }
    else {
        throw ParsingException("Improper grammar, next token should be Constant", getLineNumber());
    }
}

void Parser::validateNop() {
    advance();


    Token nextToken = peek();
    //cout << nextToken.getLexeme();

    if(nextToken.getTokenType() != TokenType::EOL && nextToken.getTokenType() != TokenType::_EOF) {
        throw ParsingException("Improper grammar, Token should not follow NOP", getLineNumber());
    }
    return;

}

//Advances position pointer forward and returns the previous Token
Token Parser::advance() {
    //increment index return the token
    if(!isAtEnd()) {
        ++current;
        return previous();
    }
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

void Parser::incrementLineNumber() {
    _lineNumber++;
}

int Parser::getLineNumber() {
    return _lineNumber;
}


