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

        switch (_ch) {
            case '"': { // String
                bool is_ok = true;
                std::string str = readString(is_ok);
                if (is_ok) {
                    t = new TokenStr(str);
                } else {
                    t = new Token(ERR);
                }
            } break;
            case '\'': { // Char
                bool is_ok = true;
                char ch = readChar(is_ok);
                if (is_ok) {
                    t = new TokenChar(ch);
                } else {
                    t = new Token(ERR);
                }
            } break;
            case '#': {
                skipLine();
                t = new Token(ERR);
            } break;
            case '+':
                t = new Token(scan('+') ? INC : ADD); break;
            case '-':
                t = new Token(scan('-') ? DEC : SUB); break;
            case '*':
                t = new Token(MUL); scan(); break;
            case '/': {
                scan();
                if (_ch == '/') { // single line comment
                    skipLine();
                    t = new Token(COMMENT);
                } else if (_ch == '*') { // multiple line comment
                    while (!scan(-1)) {
                        if (_ch == '*') {
                            if (scan('/')) {
                                break;
                            }
                        }
                    }
                    if (_ch == -1) {
                        LEXERROR(COMMENT_NO_END);
                        t = new Token(ERR);
                    } else {
                        t = new Token(COMMENT);
                    }
                } else {
                    t = new Token(DIV);
                }
            } break;
            case '%':
                t = new Token(MOD); scan(); break;
            case '>':
                t = new Token(scan('=') ? GE : GT); break;
            case '<':
                t = new Token(scan('=') ? LE : LT); break;
            case '=':
                t = new Token(scan('=') ? EQU : ASSIGN); break;
            case '&':
                t = new Token(scan('&') ? AND : LEA); break;
            case '|': {
                t = new Token(scan('|') ? OR : ERR);
                if (t->tag() == ERR) {
                    LEXERROR(OR_NO_PAIR);
                }
            } break;
            case '!':
                t = new Token(scan('=') ? NEQU : BANG); break;
            case ',':
                t = new Token(COMMA); scan(); break;
            case ':':
                t = new Token(COLON); scan(); break;
            case ';':
                t = new Token(SEMICON); scan(); break;
            case '(':
                t = new Token(LPAREN); scan(); break;
            case ')':
                t = new Token(RPAREN); scan(); break;
            case '[':
                t = new Token(LBRACK); scan(); break;
            case ']':
                t = new Token(RBRACK); scan(); break;
            case '{':
                t = new Token(LBRACE); scan(); break;
            case '}':
                t = new Token(RBRACE); scan(); break;
            case -1:
                scan(); break;
            default: {
                if (Util::isLetter(_ch)) {
                    std::string name = readIdentifier();
                    Tag tag = Keywords::getKeywordTag(name);
                    if (tag == IDENTIFER) {
                        t = new TokenId(name);
                    } else {
                        t = new Token(tag);
                    }
                } else if (Util::isDecimalDigit(_ch)) {
                    bool is_ok = true;
                    int num = readNumber(is_ok);
                    if (is_ok) {
                        t = new TokenNum(num);
                    } else {
                        t = new Token(ERR);
                    }
                }
            } break;
        }


        if (_token != NULL) {
            delete _token;
        }
        _token = t;

        if (_token != NULL)
            return _token;
        else
            continue;
    }

    if (_token != NULL) {
        delete _token;
    }
    _token = new Token(END);

    return _token;
}

void Lexer::skipWhiteSpace() {
    while (Util::isWhiteSpace(_ch)) {
        scan();
    }
}

void Lexer::skipLine() {
    while ((_ch != '\n') && (_ch != -1)) {
        scan();
    }
}

std::string Lexer::readIdentifier() {
    std::string name;
    do {
        name += _ch;
        scan();
    } while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch));

    return name;
}

std::string Lexer::readString(bool& is_ok) {
    std::string str;
    while (!scan('"')) {
        if (_ch == '\\') {
            scan();
            switch (_ch) {
                case 'n':  str.push_back('\n'); break;
                case 't':  str.push_back('\t'); break;
                case 'r':  str.push_back('\r'); break;
                case '\\': str.push_back('\\'); break;
                case '"':  str.push_back('"');  break;
                case '\'': str.push_back('\''); break;
                default:
                    char buf[16];
                    sprintf(buf, "\'\\%c\'", _ch);
                    LEXERROR(UNKNOWN_ESCAPE_SEQ, buf);
                    is_ok = false;
                    break; 
            }
        } else if (_ch == '\n' || _ch == -1) {
            LEXERROR(STR_NO_R_QUTION);
            is_ok = false;
            break;
        } else {
            str.push_back(_ch);
        }
    }

    return str;
}

char Lexer::readChar(bool& is_ok) {
    char ch;

    auto readCharskipError = [&]() {
        do {
            scan();
        } while (!Util::isWhiteSpace(_ch) && _ch != '\'');
        if (_ch == '\'') {
            scan();
        }
    };

    scan();
    if (_ch == '\\') {
        scan();
        switch (_ch) {
            case 'n':  ch = '\n'; break;
            case 't':  ch = '\t'; break;
            case 'r':  ch = '\r'; break;
            case '\\': ch = '\\'; break;
            case '"':  ch = '"';  break;
            case '\'': ch = '\''; break;
            default:
                char buf[16];
                sprintf(buf, "\'\\%c\'", _ch);
                LEXERROR(UNKNOWN_ESCAPE_SEQ, buf);
                is_ok = false;
                ch = 0;
                readCharskipError();
                break; 
        }
    } else if (_ch == '\n' || _ch == -1) {
        LEXERROR(CHAR_NO_R_QUTION);
        is_ok = false;
        ch = 0;
    } else if (_ch == '\'') {
        LEXERROR(CHAR_NO_DATA);
        is_ok = false;
        ch = 0;
        scan();
    } else {
        ch = _ch;
        if (!scan('\'')) {
            LEXERROR(CHAR_NO_R_QUTION);
            is_ok = false;
            readCharskipError();
        }
    }

    return ch;
}

int Lexer::readNumber(bool& is_ok) {
    int val = 0;

    if (_ch != '0') {
        // decimal
        do {
            val = val * 10 + Util::tansDecimalCharToInt(_ch);
            scan();
        } while (Util::isDecimalDigit(_ch));
        if (Util::isLetter(_ch)) {
            LEXERROR(UNQUALIFIED_ID);
            is_ok = false;
            do {
                scan();
            } while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch));
        }
    } else {
        scan();
        if (_ch == 'x') {
            // hex
            scan();
            if (Util::isHexDigit(_ch)) {
                do {
                    val = val * 16 + Util::tansHexCharToInt(_ch);
                    scan();
                } while (Util::isHexDigit(_ch));
                if (Util::isLetter(_ch) || Util::isDecimalDigit(_ch)) {
                    LEXERROR(UNQUALIFIED_ID);
                    is_ok = false;
                    do {
                        scan();
                    } while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch));
                }
            } else {
                LEXERROR(NUM_HEX_TYPE);
                is_ok = false;
                while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch)) {
                    scan();
                }
            }
        } else if (_ch == 'b') {
            // binary
            scan();
            if (Util::isBinaryDigit(_ch)) {
                do {
                    val = val * 2 + Util::tansBinaryCharToInt(_ch);
                    scan();
                } while (Util::isBinaryDigit(_ch));
                if (Util::isLetter(_ch) || Util::isDecimalDigit(_ch)) {
                    LEXERROR(UNQUALIFIED_ID);
                    is_ok = false;
                    do {
                        scan();
                    } while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch));
                }
            } else {
                LEXERROR(NUM_BIN_TYPE);
                is_ok = false;
                while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch)) {
                    scan();
                }
            }

        } else if (Util::isOctonaryDigit(_ch)) {
            // octonary
            do {
                val = val * 8 + Util::tansOctonaryCharToInt(_ch);
                scan();
            } while (Util::isOctonaryDigit(_ch));
        } else {
            if (Util::isLetter(_ch) || Util::isDecimalDigit(_ch)) {
                LEXERROR(UNQUALIFIED_ID);
                is_ok = false;
                do {
                    scan();
                } while (Util::isLetter(_ch) || Util::isDecimalDigit(_ch));
            }
        }
    }

    return val;
}