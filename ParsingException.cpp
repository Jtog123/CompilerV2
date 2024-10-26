//
// Created by jtog8 on 10/24/2024.
//

#include "ParsingException.hpp"
#include <sstream>

ParsingException::ParsingException(const char *msg): _message(msg) {
}

ParsingException::ParsingException(const char *msg, int lineNumber) {
    ostringstream oss;
    oss << msg << " on line: " << lineNumber << endl;
    _message = oss.str();
}

const char *ParsingException::what() const throw() {
    return _message.c_str();
}
