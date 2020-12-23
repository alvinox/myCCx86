#include "utility.h"

bool Util::isWhiteSpace(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r');
}

bool Util::isLetter(char ch) {
    return ('a' <= ch && ch <= 'z') ||
           ('A' <= ch && ch <= 'Z') ||
           (ch == '_');
}

bool Util::isHexDigit(char ch) {
    return ('0' <= ch && ch <= '9') ||
           ('a' <= ch && ch <= 'f') ||
           ('A' <= ch && ch <= 'F');
}

bool Util::isDecimalDigit(char ch) {
    return ('0' <= ch) && (ch <= '9');
}

bool Util::isOctonaryDigit(char ch) {
    return ('0' <= ch) && (ch <= '7');
}

bool Util::isBinaryDigit(char ch) {
    return ('0' <= ch) && (ch <= '1');
}

int Util::tansHexCharToInt(char ch) {
    if ('0' <= ch && ch <= '9') return ch - '0';
    if ('a' <= ch && ch <= 'f') return ch - 'a';
    if ('A' <= ch && ch <= 'F') return ch - 'A' + 10;
    return 0;
}

int Util::tansDecimalCharToInt(char ch) {
    return ch - '0';
}

int Util::tansOctonaryCharToInt(char ch) {
    return ch - '0';
}

int Util::tansBinaryCharToInt(char ch) {
    return ch - '0';
}
