cd src/parser
bison parser.yy
mv Parser.hpp ../../include
cd lexer
flex++ lexer.ll
cd ../../..
make
