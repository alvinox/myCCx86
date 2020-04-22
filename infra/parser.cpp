#include "parser.h"
#include "compiler.h"

void Parser::program() {
    do {
        move();
    } while (_look->tag() != END);
}
void Parser::move() {
    _look = _lexer.tokenize();
    if (Args::showToken) {
        printf("%s\n", _look->toString().c_str());
    }
}