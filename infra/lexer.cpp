#include "lexer.h"
#include "compiler.h"
#include "error.h"

std::string Scanner::showChar(char ch, ui4 row, ui4 col) {
    std::string str;
    char buf[64];
    sprintf(buf, "(%u, %u) ", row, col);
    str += buf;

    switch (ch) {
        case -1:     str += "EOF";     break;
        case '\n':   str += "\\n";     break;
        case '\t':   str += "\\t";     break;
        case ' ':    str += "<blank>"; break;
        default:     str += ch; break;
    }
    return str;

    // if(ch==-1)        printf("EOF");
    // else if(ch=='\n') printf("\\n");
    // else if(ch=='\t') printf("\\t");
    // else if(ch==' ')  printf("<blank>");
    // else              printf("%c",ch);
    // printf("\t\t<%d>\n", ch);
}

Scanner::Scanner(char* name) {
    _file = fopen(name, "r");
    if (_file == NULL) {
        PDEBUG(FATAL "file '%s' can't open or access!\n", name);
        Error::errorNum++;
    }

    _fileName = name;

    _lineLen         = 0;
    _readPositon     = 0;
    _lastChar        = 0;

    _rowNum          = 1;
    _colNum          = 0;
}

Scanner::~Scanner() {
    if (_file != NULL) {
        PDEBUG(WARN "文件未全部扫描！\n");
        Error::warnNum++;
        fclose(_file);
    }
}

char Scanner::scan() {
    if (_file == NULL) {
        return -1;
    }

    if (_readPositon == _lineLen) {
        _lineLen = fread(_line, 1, BUFLEN, _file);
        _readPositon = 0;

        if (_lineLen < BUFLEN) {
            _line[_lineLen] = -1;
        }
    }

    char ch = _line[_readPositon];
    if (ch == -1) {
        fclose(_file);
        _file = NULL;
    } else {
        _colNum++;
    }

    if (_lastChar == '\n') {
        _rowNum++;
        _colNum = 1;
    }

    _lastChar = _line[_readPositon];
    _readPositon++;

    if (Args::showChar)
        printf("%s\n", showChar(ch, _rowNum, _colNum).c_str());
    return ch;
}