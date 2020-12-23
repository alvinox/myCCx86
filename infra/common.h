#ifndef __COMMON_H_
#define __COMMON_H_

#include <stdio.h>
#include <vector>
#include <list>
#include <string>

#include "utility.h"

#define ui1 unsigned char
#define ui2 unsigned short
#define ui4 unsigned int
#define ui8 unsigned long long int
#define i1  signed char
#define i2  signed short
#define i4  signed int
#define i8  signed long long int

// lexer error
enum LexError
{
    STR_NO_R_QUTION,     // no right quotation for string
    CHAR_NO_R_QUTION,    // no right single quotation for char
    NUM_BIN_TYPE,        // unable to find numeric literal for binary number
    NUM_HEX_TYPE,        // unable to find numeric literal for hex number
    CHAR_NO_DATA,        // empty character constant
    OR_NO_PAIR,          // get only one | for || operator
    COMMENT_NO_END,      // unterminated comment
    TOKEN_NO_EXIST,      // token not exists
    UNKNOWN_ESCAPE_SEQ,  // unknown escape sequence
    UNQUALIFIED_ID,      // expected unqualified-id
};

// semantic error
enum SemError
{
    VAR_RE_DEF,          //redefine variable
    FUN_RE_DEF,          //redefine function
    VAR_UN_DEC,          //undeclared variable
    FUN_UN_DEC,          //undeclared function
    FUN_DEC_ERR,         //function defination and declaration mismatch
    FUN_CALL_ERR,        //function actual and formal parameter mismatch
    DEC_INIT_DENY,       // initialization is not allowed when declare
    EXTERN_FUN_DEF,      // cannot use extern in function declare
    ARRAY_LEN_INVALID,   // invalid array length
    VAR_INIT_ERR,        // variable init error
    GLB_INIT_ERR,        // global variable init error
    VOID_VAR,            //void variable
    EXPR_NOT_LEFT_VAL,   // expression cannot be left-value
    ASSIGN_TYPE_ERR,     // assign error
    EXPR_IS_BASE,        // expression cannot be basic type
    EXPR_NOT_BASE,       //expression is not basic type
    ARR_TYPE_ERR,        // array type error
    EXPR_IS_VOID,        // expression is void
    BREAK_ERR,           //break is not in loop or switch-case
    CONTINUE_ERR,        //continue is not in loop
    RETURN_ERR           //return type error
};

#endif