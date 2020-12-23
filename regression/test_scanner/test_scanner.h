#ifndef __TEST_SCANNER_H_
#define __TEST_SCANNER_H_

#include <iostream>
#include <cstring>
#include <algorithm>

#include "common.h"
#include "compiler.h"
#include "lexer.h"
#include "error.h"

class TestScanner {
  public:
    struct ExpectStruct {
        ui4  row;
        ui4  col;
        char ch;
    };

    static bool Entry();

  public:
    TestScanner(char* file_name, std::vector<ExpectStruct>& expected) 
        : _name(file_name), _expected(expected) { }

  private:
    char* _name;
    std::vector<ExpectStruct> _expected;
};

#endif // __TEST_SCANNER_H_