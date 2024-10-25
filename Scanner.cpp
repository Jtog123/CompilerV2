//
// Created by jtog8 on 9/5/2024.
//

#include "Scanner.hpp"
#include <fstream>
#include <iostream>


using namespace std;

/*
 * Recognize all keywords seems good
 * handle all errors in each input file
 * form tokens and push them into container
 *
 * Parse?
 */

/////////////////////////////////////

Scanner::Scanner(const string& filePath)  {
    // open the file
    inputFile.open(filePath);
    if(!inputFile) {
        cerr << "No input file or error opening input file: " << filePath << endl;
        exit(65);
    }
}

void Scanner::eatTillDelimiter() {
    while(!matchNextChar(' ') && !matchNextChar(',') && !inputFile.eof()) {
        if(matchNextChar('\n'))
            _lineNumber++;
        else
            inputFile.get();
    }
}

bool Scanner::matchNextChar(char expectedChar) {
    char currentChar = inputFile.peek();
    if(currentChar == expectedChar) {
        inputFile.get();
    }
    return currentChar == expectedChar;
}



Token Scanner::getToken() {
    // while we are not at the end of the file
    // gather each char and look for each word

    Token token;

    while(! inputFile.eof()) {
        char currentChar = inputFile.peek();

        // check for new lines
        if (currentChar == '\n') {
            //cout << "END OF LINE" << endl;
            inputFile.get();
            _lineNumber++;
            token.setToken(EOL, "\\n");
            return token;


        }
        else if(currentChar == ' ') {
            //cout << "Whitespace" << endl;
            inputFile.get();
            continue;
        }
        else if(currentChar == ',') {
            //cout << "Comma" << endl;
            inputFile.get();
            token.setToken(COMMA, ",");
            return token;
        }
        else if(currentChar == '/') {
            inputFile.get();
            if(matchNextChar('/')) {
                token.setToken(COMMENT, "//");

                //Encounter a comment get the whole line till we reach a new line
                while(inputFile.peek() != '\n') {
                    inputFile.get();
                }

                return token;
            }
            else {
                //unget initial slash ??
            }
        }
        else if(currentChar == '=') {
            inputFile.get();
            if(matchNextChar('>')) {

                token.setToken(INTO, "=>");
                return token;


            }
        }
            // if we get a number
        else if (isdigit(currentChar)) {

            string number;
            bool validInt = true;
            while(isdigit(inputFile.peek())) {
                number += inputFile.peek();
                inputFile.get();
            }

            //potential non digit character
            char nextChar = inputFile.peek();

            if(nextChar != ' ' && nextChar != '=' && nextChar != ',' && nextChar != '\n' && nextChar != '\t' && nextChar != EOF) {
                cout << "Syntax error on line " << _lineNumber << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                eatTillDelimiter();
                return token;

                //validInt = false;

                //eat characters until a space or newline or end of file
                //while(!isspace(inputFile.peek()) && inputFile.peek() != '\n' && !inputFile.eof()) {
                //    inputFile.get();
                //}
            }

            token.setToken(CONSTANT, number);
            return token;

            /*
            if(validInt) {
                cout << "got number: " << number << endl;
                //before we push the number back check the operations before it
                if(tokenStream.size() >= 2) {
                    int previousOperation = tokenStream.size() - 2;
                    if(tokenStream[previousOperation].first == TokenType::INTO ||
                       tokenStream[previousOperation].first == TokenType::REGISTER) {
                        cout << "Syntax Error on line: " << _lineNumber << " invalid register operation" << endl;
                        //get it?

                    }
                    else {
                        tokenStream.push_back({CONSTANT, number});
                    }
                }

            }
             */

        }
            //Words that start with s
        else if(currentChar == 's') {
            inputFile.get();
            // Looking for STORE
            if(matchNextChar('t') && matchNextChar('o') && matchNextChar('r')
               && matchNextChar('e') && matchNextChar(' ')) {

                //After each word if next char is not a space report an error sith the line number
                // Error should probably be thrown here

                //cout << "Got STORE" << endl;
                    token.setToken(MEMOP, "store");
                    return token;
                }


                // Looking for SUB
            else if(matchNextChar('u') && matchNextChar('b') && matchNextChar(' ')) {
                //cout << "Got SUB" << endl;
                token.setToken(ARITHOP, "sub");
                return token;

            }
            else {
                cout << "Syntax Error on line: " << _lineNumber << " did you mean store or sub?" << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                eatTillDelimiter();
                return token;
            }

        }

            // Words what start with L {LOAD, LOADI, lSHIFT}
        else if (currentChar == 'l'){
            inputFile.get();
            if(matchNextChar('o') && matchNextChar('a') && matchNextChar('d')){

                //Check for accetped state LOADL
                if(matchNextChar('I') && matchNextChar(' ')) {
                    //cout << "Got LOADI" << endl;
                    token.setToken(LOADI, "loadi");
                    return token;
                } else if(matchNextChar(' ')) {
                    //cout << "Got LOAD" << endl;
                    token.setToken(MEMOP, "load");
                    return token;
                }
                else {
                    cout << "Syntax Error did you mean load or loadI? " << endl;
                    token.setToken(LEXICAL_ERROR, "syn_err");
                    return token;
                }



            }
            else if (matchNextChar('s') && matchNextChar('h') && matchNextChar('i') && matchNextChar('f') &&
                     matchNextChar('t') && matchNextChar(' ')) {
                //cout << "Got lshift" << endl;
                //tokenStream.push_back({ARITHOP, "lshift"});
                token.setToken(ARITHOP, "lshift");
                return token;
            }
            else {

                cout << "Syntax Error on line " << _lineNumber << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                return token;
            }
        }
            // Words what start with R {RSHIFT}
        else if( currentChar == 'r') {
            inputFile.get();
            if(matchNextChar('s') && matchNextChar('h') && matchNextChar('i')
               && matchNextChar('f') && matchNextChar('t') && matchNextChar(' ')) {

                token.setToken(ARITHOP, "rshift");
                return token;

            }
            else {

                //its a register
                string registerName = "r";

                // is char after r a number or not
                if(inputFile.eof() || ! isdigit(inputFile.peek())) {
                    cout << "Syntax error on line : "<< _lineNumber << " not a valid register "<< endl;
                    token.setToken(LEXICAL_ERROR, "syn_err");
                    eatTillDelimiter();
                    return token;

                }
                //we have a valid register
                else if (isdigit(inputFile.peek())) {
                    while(isdigit(inputFile.peek())) {

                        registerName += inputFile.peek();
                        inputFile.get();
                    }

                    token.setToken(REGISTER, registerName);
                    return token;
                }


                //We encounter a register check which operation is being preformed on the register
                /*
                int registerOperation = tokenStream.size() - 2;

                if(tokenStream[registerOperation].first != TokenType::ARITHOP &&
                   tokenStream[registerOperation].first != TokenType::MEMOP &&
                   tokenStream[registerOperation].first != TokenType::INTO &&
                   tokenStream[registerOperation].first != TokenType::REGISTER &&
                   tokenStream[registerOperation].first != TokenType::COMMA) {
                    cout << "Error Invalid register Operation at line: " << _lineNumber << endl;


                }
                 */


            }





            //convert char to string check if its a number


        }
            // Words what start with M {MULT}
        else if (currentChar == 'm') {
            inputFile.get();
            if(matchNextChar('u') && matchNextChar('l') && matchNextChar('t') && matchNextChar(' ')) {
                //cout << "got mult" << endl;
                //tokenStream.push_back({ARITHOP, "mult"});
                token.setToken(ARITHOP, "mult");
                return token;
            }
            else {
                cout << "Syntax Error on line " << _lineNumber << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                return token;
            }
        }
            // Words what start with A {ADD}
        else if(currentChar == 'a') {
            inputFile.get();
            if(matchNextChar('d') && matchNextChar('d') && matchNextChar(' ')) {
                //cout << "Got Add" << endl;
                //tokenStream.push_back({ARITHOP, "add"});
                token.setToken(ARITHOP, "add");
                return token;
            }
            else{
                cout << "Syntax error on line: " << _lineNumber  << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                return token;
            }
        }
            // Words what start with N {NOP}
        else if(currentChar == 'n') {
            inputFile.get();
            if(matchNextChar('o') && matchNextChar('p') && matchNextChar(' ')) {
                //cout << "Got nop" << endl;
                //tokenStream.push_back({NOP, "nop"});
                token.setToken(NOP, "nop");
                return token;
            } else {
                cout << "Syntax Error on line " << _lineNumber << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                return token;
            }
        }
            // Words what start with O {OUTPUT}
        else if (currentChar == 'o') {
            inputFile.get();
            if(matchNextChar('u') && matchNextChar('t') && matchNextChar('p')
               && matchNextChar('u') && matchNextChar('t') && matchNextChar(' ')) {
                //cout << "Got output" << endl;
               // tokenStream.push_back({OUTPUT, "output"});
               token.setToken(OUTPUT, "output");
               return token;

            }
            else {
                cout << "Syntax Error on line " << _lineNumber << endl;
                token.setToken(LEXICAL_ERROR, "syn_err");
                return token;
            }
        }
        else {
            inputFile.get();
            //cout << "invalid token or character" << endl;


        }

    }

    //tokenStream.push_back({_EOF, "eof"});
    token.setToken(_EOF, "eof");
    return token;

    //if(inputFile.eof()) {
    //    cout << "End of file." << endl;
     //   token.setToken(_EOF, "eof");
    //    return token;
    //}



    //enum read as an int
    cout << endl;
    cout << "Reading out Tokens : " << endl;


    /*
    for(auto i : tokenStream) {
        cout << "Token is: " << i.second << endl;

        if(i.first == TokenType::ARITHOP) {
            cout << "WE got Airthop" << endl;
        }
    }
     */

}



