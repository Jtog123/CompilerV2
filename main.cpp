#include <iostream>
#include <fstream>
#include "Scanner.hpp"
#include "Parser.hpp"


int main(int argc, char* argv[]) {
    cout << endl;
    //Scanner scanner(argv[1]);
    //scanner.readFile();

    Parser parser(argv[1]);
    parser.getTokens();
    parser.parse();

    vector<OpCodes> opCodes = parser.getOpCodes();

    for(auto code : opCodes) {
        cout << "opcode is" << endl;
        cout << code << endl;
    }

    //loop through token vect for Intermediate representation pass it to the class
    // use regex to strip numbers off token names

    // if we have an input file thats not valid how does IR look?
    // if we throw an exception does the IR stop as well are go to all zeros?

    // Do we only get fully formed IR's with valid input files?

    // I used enums my memop maps to 0, for an empty operation could I use a different number say a 00?

    // he takes the numbers on the registers

    // can i add you on linkedin


    return 0;
}

