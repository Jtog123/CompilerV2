//
// Created by jtog8 on 10/24/2024.
//

#ifndef COMPILERV2_PARSINGEXCEPTION_HPP
#define COMPILERV2_PARSINGEXCEPTION_HPP

#include <iostream>
#include <string>
using namespace std;

class ParsingException : public exception {
    private:
        string _message;

    public:
        //Constructor to set exception
        ParsingException(const char* msg);
        ParsingException(const char* msg, int lineNumber);

        //overridding what method from exception
        const char* what() const throw();

};


#endif //COMPILERV2_PARSINGEXCEPTION_HPP
