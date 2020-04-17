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

    static void Entry();

  public:
    TestScanner(char* name, std::vector<ExpectStruct>& expected) 
        : _name(name), _expected(expected) { }

    std::vector<ExpectStruct> run() const {
        Scanner scanner(_name);

        std::vector<ExpectStruct> result;
        while (scanner.getFile() != NULL) {
            scanner.scan();
            
            ui4 row = scanner.getRow();
            ui4 col = scanner.getCol();
            char ch = scanner.getLastChar();

            ExpectStruct e = {row, col, ch};
            result.push_back(e);
        }

        return result;
    }
  public:
    char* _name;
    std::vector<ExpectStruct> _expected;
};

#endif // __TEST_SCANNER_H_