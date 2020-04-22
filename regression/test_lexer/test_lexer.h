#ifndef __TEST_LEXER_H_
#define __TEST_LEXER_H_

#include <iostream>
#include <cstring>
#include <algorithm>

#include "common.h"
#include "compiler.h"
#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"

class TestLexer {
  public:
    struct ExpectStruct {
        Token* token;
    };

    static bool Entry();

  public:
    TestLexer(char* file_name, std::vector<ExpectStruct>& expected) 
        : _name(file_name), _expected(expected) { }

  public:
    char* _name;
    std::vector<ExpectStruct> _expected;
};

#endif // __TEST_LEXER_H_