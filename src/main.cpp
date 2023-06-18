#include <iostream>
#include <fstream>
#include "Parser.hpp"
#include "Lexer.hpp"
#include "TypeTab.hpp"
#include "Driver.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Faltan argumentos" << endl;
        return EXIT_FAILURE;
    }

    Driver driver = Driver(string(argv[1]));

    driver.parse();
    cout << driver.getICode() << endl;

    return 0;
}