#include "error.h"

Scanner* Error::scanner = NULL;
int Error::errorNum = 0;
int Error::warnNum  = 0;

std::unordered_map<int, std::string> Error::LexerErrorTable = {
    {STR_NO_R_QUTION,      "no right quotation for string"},
    {CHAR_NO_R_QUTION,     "no right quotation for char"},
    {NUM_BIN_TYPE,         "unable to find numeric literal for binary number"},
    {NUM_HEX_TYPE,         "unable to find numeric literal for hex number"},
    {CHAR_NO_DATA,         "empty character constant"},
    {OR_NO_PAIR,           "get only one | for || operator"},
    {COMMENT_NO_END,       "unterminated comment"},
    {TOKEN_NO_EXIST,       "token not exists"},
    {UNKNOWN_ESCAPE_SEQ,   "unknown escape sequence"},
    {UNQUALIFIED_ID,       "expected unqualified-id"},
};

void Error::lexError(int code, std::string hint) {
    std::string file_name = Error::scanner->getFileName();
    int row               = Error::scanner->getRow();
    int col               = Error::scanner->getCol();
    std::string info      = Error::LexerErrorTable[code];

    if (hint == "") {
        printf("Lexer Error: %s(%d, %d): %s.\n",
            file_name.c_str(), row ,col, info.c_str());
    } else {
        printf("Lexer Error: %s(%d, %d): %s (%s).\n",
            file_name.c_str(), row ,col, info.c_str(), hint.c_str());
    }

    Error::errorNum++;
}

Error::Error(Scanner* scanner) {
    Error::scanner = scanner;
}