#include <iostream>
#include <fstream>
#include "Scanner.hpp"
#include "Parser.hpp"



int main(int argc, char* argv[]) {
    cout << endl;
    //Scanner scanner(argv[1]);
    //scanner.readFile();

    Parser parser(argv[1]);

    //get all tokens first store in vector then parse through the vector
    parser.getTokens();
    parser.parse();

    const auto& instructions = parser.getParsedInstructions();

    //writes to current working directory
    ofstream outputFile("irOutput.txt");
    if(outputFile.is_open()) {
        for(auto& instr : instructions) {
            //Write to file
            outputFile << instr.lineNumber << " " << instr.opC << " " << instr.operand1 << " "
                       << instr.operand2 << " " << instr.operand3 << "\n";
        }
        outputFile.close();
    }
    else {
        cerr << "faied to load output.txt" << endl;
    }




    return 0;
}

