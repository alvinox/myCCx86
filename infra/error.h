#ifndef _ERROR_H_
#define _ERROR_H_

#include "lexer.h"

#define FATAL "<FATAL>: "
#define ERROR "<ERROR>: "
#define WARN  "<WARN>: "
#define INFO  "<INFO>: "

class Error {
  public:
    enum ErrorType {
      e_lexer_error,
      e_syntactical_error,
      e_semantic_error,
    };
    static Scanner* scanner;

    static int errorNum;
    static int warnNum;

    static std::unordered_map<int, std::string> LexerErrorTable;
    static std::unordered_map<int, std::string> SemanticErrorTable;

    static void baseError(int error_type, int code, const std::string& hint = "");
    // static void baseError(int code, const std::string& hint = "");
    static void lexError (int code, const std::string& hint = "");
    static void semError (int code, const std::string& hint = "");
  public:
    Error(Scanner* scanner);
};

#ifdef DEBUG
#define PDEBUG(fmt, args...) printf(fmt, ##args)
#else
#define PDEBUG(fmt, args...)
#endif //DEBUG

#define LEXERROR(code, args...) Error::lexError(code, ##args)
#define SEMERROR(code, args...) Error::semError(code, ##args)

#endif // _ERROR_H_