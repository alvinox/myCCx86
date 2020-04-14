#ifndef _ERROR_H_
#define _ERROR_H_

#include "lexer.h"

#define FATAL "<FATAL>: "
#define ERROR "<ERROR>: "
#define WARN  "<WARN>: "
#define INFO  "<INFO>: "

class Error {
  public:
    static int errorNum;
    static int warnNum;

    // static void lexError(int code);
  public:
    Error(Scanner* scanner);

  private:
    Scanner* _scanner;
};

#ifdef DEBUG
#define PDEBUG(fmt, args...) printf(fmt, ##args)
#else
#define PDEBUG(fmt, args...)
#endif	//DEBUG

#endif // _ERROR_H_