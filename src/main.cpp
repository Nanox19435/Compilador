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
    string filename = argv[1];
    Driver driver = Driver(filename);

    int i = driver.parse();
    cout << i << endl;

    return 0;
}