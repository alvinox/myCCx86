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

#endif