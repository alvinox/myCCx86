#ifndef __UTILITY_H_
#define __UTILITY_H_

class Util {
  public:
    static bool isWhiteSpace(char ch);
    static bool isLetter(char ch);
    static bool isHexDigit(char ch);
    static bool isDecimalDigit(char ch);
    static bool isOctonaryDigit(char ch);
    static bool isBinaryDigit(char ch);

    static int tansHexCharToInt(char ch);
    static int tansDecimalCharToInt(char ch);
    static int tansOctonaryCharToInt(char ch);
    static int tansBinaryCharToInt(char ch);
};

#endif // __UTILITY_H_