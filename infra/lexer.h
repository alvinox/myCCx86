#ifndef __LEXER_H_
#define __LEXER_H_

#include "common.h"

class Scanner {
  public:
    static const int BUFLEN = 80;
  public:
    Scanner(char* name);
    ~Scanner();

    int scan();

    char* getFile() { return _fileName; }
    int getLine() { return _lineNum; }
    int getCol()  { return _colNum; }

  private:
    char* _fileName;
    FILE* _file;

    int _lineNum;
    int _colNum;
};

#endif // __LEXER_H_