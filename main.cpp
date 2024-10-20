#include <iostream>
#include <fstream>
#include "Scanner.hpp"
#include "Parser.hpp"
#include "BinaryExpr.hpp"

int main(int argc, char* argv[]) {
    cout << endl;
    //Scanner scanner(argv[1]);
    //scanner.readFile();

    Parser parser(argv[1]);
    parser.printTokens();

    BinaryExpr bExpr {}; // automatically destroyed when out of scope
    Expr& expr {bExpr};

    expr.testing();

    return 0;
}

