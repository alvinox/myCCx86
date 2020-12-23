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

std::unordered_map<int, std::string> Error::SemanticErrorTable {
    {VAR_RE_DEF,           "redefine variable"},
    {FUN_RE_DEF,           "redefine function"},
    {VAR_UN_DEC,           "undeclared variable"},
    {FUN_UN_DEC,           "undeclared function"},
    {FUN_DEC_ERR,          "function defination and declaration mismatch"},
    {FUN_CALL_ERR,         "function actual and formal parameter mismatch"},
    {DEC_INIT_DENY,        " initialization is not allowed when declare"},
    {EXTERN_FUN_DEF,       " cannot use extern in function declare"},
    {ARRAY_LEN_INVALID,    " invalid array length"},
    {VAR_INIT_ERR,         " variable init error"},
    {GLB_INIT_ERR,         " global variable init error"},
    {VOID_VAR,             "void variable"},
    {EXPR_NOT_LEFT_VAL,    " expression cannot be left-value"},
    {ASSIGN_TYPE_ERR,      " assign error"},
    {EXPR_IS_BASE,         " expression cannot be basic type"},
    {EXPR_NOT_BASE,        "expression is not basic type"},
    {ARR_TYPE_ERR,         " array type error"},
    {EXPR_IS_VOID,         " expression is void"},
    {BREAK_ERR,            "break is not in loop or switch-case"},
    {CONTINUE_ERR,         "continue is not in loop"},
    {RETURN_ERR,           "return type error"},
};

void Error::baseError(int error_type, int code, const std::string& hint) {
    std::unordered_map<int, std::string> table;
    switch (error_type) {
        case e_lexer_error:
            table = Error::LexerErrorTable; break;
        case e_syntactical_error:
            break;
        case e_semantic_error:
            table = Error::SemanticErrorTable; break;
        default: ;
    };

    std::string file_name = Error::scanner->getFileName();
    int row               = Error::scanner->getRow();
    int col               = Error::scanner->getCol();
    std::string info      = table[code];

    if (hint == "") {
        printf("Lexer Error: %s(%d, %d): %s.\n",
            file_name.c_str(), row ,col, info.c_str());
    } else {
        printf("Lexer Error: %s(%d, %d): %s (%s).\n",
            file_name.c_str(), row ,col, info.c_str(), hint.c_str());
    }

    Error::errorNum++;
}

void Error::lexError(int code, const std::string& hint) {
    Error::baseError(e_lexer_error, code, hint);
}

void Error::semError(int code, const std::string& hint) {
    Error::baseError(e_semantic_error, code, hint);
}

Error::Error(Scanner* scanner) {
    Error::scanner = scanner;
}