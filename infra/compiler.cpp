#include "compiler.h"
#include "lexer.h"
#include "parser.h"

/*
	编译参数初始化
*/
bool Args::showChar=false;
bool Args::showToken=false;
bool Args::showSym=false;
bool Args::showIr=false;
bool Args::showOr=false;
bool Args::showBlock=false;
bool Args::showHelp=false;
bool Args::opt=false;

void Compiler::compile(char* file) {
    Scanner scanner(file);
    Lexer   lexer(scanner);
    Parser  parser(lexer);
    parser.program();
}