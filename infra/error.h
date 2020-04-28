#ifndef _ERROR_H_
#define _ERROR_H_

#include "lexer.h"

#define FATAL "<FATAL>: "
#define ERROR "<ERROR>: "
#define WARN  "<WARN>: "
#define INFO  "<INFO>: "

class Error {
  public:
    static Scanner* scanner;

    static int errorNum;
    static int warnNum;

    static std::unordered_map<int, std::string> LexerErrorTable;

    static void lexError(int code, std::string hint = "");
  public:
    Error(Scanner* scanner);
};

#ifdef DEBUG
#define PDEBUG(fmt, args...) printf(fmt, ##args)
#else
#define PDEBUG(fmt, args...)
#endif //DEBUG

#define LEXERROR(code, args...) Error::lexError(code, ##args)

#endif // _ERROR_H_