#ifndef __PARSER_H_
#define __PARSER_H_

#include "lexer.h"

class Parser {
  public:
    Parser(Lexer& lexer) : _lexer(lexer) { }

  public:
    void program();
    void move();

  private:
    Lexer&   _lexer;
    Token*   _look;
};

#endif // __PARSER_H_