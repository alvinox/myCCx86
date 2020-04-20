#include "lexer.h"
#include "compiler.h"
#include "error.h"

/*******************************************************************************
                                   Scanner
*******************************************************************************/

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

/*******************************************************************************
                                   Lexer
*******************************************************************************/

bool Lexer::isLetter(char ch) {
    return (('a' <= ch) && (ch <= 'z')) ||
           (('A' <= ch) && (ch <= 'Z')) ||
           (ch == '_');
}

bool Lexer::scan(char expected) {
    _ch = _scanner.scan();
    if (expected != 0) {
        if (_ch != expected) {
            return false;
        }

        _ch = _scanner.scan();
        return true;
    }

    return true;
}

Token* Lexer::tokenize() {
    while (_ch != -1) {
        Token* t = NULL;
        skipWhiteSpace();

        if (Lexer::isLetter(_ch)) {
            std::string name = readIdentifier();
            Tag tag = Keywords::getKeywordTag(name);
            if (tag == IDENTIFER) {
                t = new Id(name);
            } else {
                t = new Token(tag);
            }
        }

        if (_token != NULL) {
            delete _token;
        }
        _token = t;
        return _token;
    }

    if (_token != NULL) {
        delete _token;
    }
    _token = new Token(END);
    return _token;
}

void Lexer::skipWhiteSpace() {
    while (_ch == ' ' || _ch == '\n' || _ch == '\t' || _ch == '\r') {
        scan();
    }
}

std::string Lexer::readIdentifier() {
    std::string name;
    do {
        name += _ch;
        scan();
    } while (Lexer::isLetter(_ch));

    return name;
}