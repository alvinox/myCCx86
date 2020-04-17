#ifndef __LEXER_H_
#define __LEXER_H_

#include "common.h"

class Scanner {
  public:
    static const int BUFLEN = 80;

    static std::string showChar(char ch, ui4 row, ui4 col);
  public:
    Scanner(char* name);
    ~Scanner();

    char scan();

    char* getFileName() { return _fileName; }
    FILE* getFile() { return _file; }
    ui4 getRow() { return _rowNum; }
    ui4 getCol()  { return _colNum; }
    char getLastChar() { return _lastChar; }

  private:
    char* _fileName;
    FILE* _file;

    char _line[BUFLEN];
    int  _lineLen;

    int  _readPositon;
    char _lastChar;

    ui4 _rowNum;
    ui4 _colNum;
};

#endif // __LEXER_H_