#ifndef __TEST_PARSER_H_
#define __TEST_PARSER_H_

#include <iostream>
#include <cstring>
#include <algorithm>

#include "common.h"
#include "compiler.h"
#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"

class TestParser {
  public:
    struct ExpectStruct {
    };

    static bool TestFunc();

  public:
    TestParser(char* file_name, std::vector<ExpectStruct>& expected) 
        : _name(file_name), _expected(expected) { }

  public:
    char* _name;
    std::vector<ExpectStruct> _expected;
};

#endif // __TEST_PARSER_H_