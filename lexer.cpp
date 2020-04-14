#include "lexer.h"
#include "error.h"

Scanner::Scanner(char* name) {
    _file = fopen(name, "r");
    if (_file == NULL) {
        printf(FATAL "file '%s' can't open or access!\n", name);
        Error::errorNum++;
    }
}

Scanner::~Scanner() {
    if (_file != NULL) {
        PDEBUG(WARN "文件未全部扫描！\n");
        Error::warnNum++;//警告数累加
        fclose(_file);
    }
}