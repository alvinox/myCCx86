#include "parser.h"
#include "compiler.h"

void Parser::program() {
    while (_look->tag() != END) {
        move();
    }
}
void Parser::move() {
    _look = _lexer.tokenize();
    if (Args::showToken) {
        printf("%s\n", _look->toString().c_str());
    }
}