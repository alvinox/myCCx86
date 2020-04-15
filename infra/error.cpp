#include "error.h"

int Error::errorNum = 0;
int Error::warnNum  = 0;

Error::Error(Scanner* scanner) {
    _scanner = scanner;
}