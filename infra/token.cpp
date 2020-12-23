#include "token.h"

std::unordered_map<int, std::string> tokenName = {
    {ERR,         "ERROR"},
    {COMMENT,     "COMMENT"},
    {END,         "END"},

    {KW_INT,      "INT"},
    {KW_CHAR,     "CHAR"},
    {KW_VOID,     "VOID"},
    {KW_EXTERN,   "EXTERN"},
    {KW_IF,       "KW_IF"},
    {KW_ELSE,     "KW_ELSE"},
    {KW_SWITCH,   "KW_SWITCH"},
    {KW_CASE,     "KW_CASE"},
    {KW_DEFAULT,  "KW_DEFAULT"},
    {KW_WHILE,    "KW_WHILE"},
    {KW_DO,       "KW_DO"},
    {KW_FOR,      "KW_FOR"},
    {KW_BREAK,    "KW_BREAK"},
    {KW_CONTINUE, "KW_CONTINUE"},
    {KW_RETURN,   "KW_RETURN"},

    {IDENTIFER,   "IDENTIFIER"},
    {NUMBER,      "NUMBER"},
    {CHAR,        "CHAR"},
    {STRING,      "STRING"},
    
    {ADD,         "+"},
    {SUB,         "-"},
    {MUL,         "*"},
    {DIV,         "/"},
    {MOD,         "%"},

    {INC,         "++"},
    {DEC,         "--"},

    {GT,          ">"},
    {GE,          ">="},
    {LT,          "<"},
    {LE,          "<="},
    {EQU,         "=="},
    {NEQU,        "!="},

    {AND,         "&&"},
    {OR,          "||"},
    {BANG,        "!"},
    {LEA,         "&"},
    {ASSIGN,      "="},

    {LPAREN,      "("},
    {RPAREN,      ")"},

    {LBRACK,     "["},
    {RBRACK,     "]"},

    {LBRACE,      "{"},
    {RBRACE,      "}"},

    {COMMA,       ","},
    {COLON,       ":"},
    {SEMICON,     ";"},
};

std::unordered_map<std::string, Tag> Keywords::KEYWORDS = {
    {"int",      KW_INT},
    {"char",     KW_CHAR},
    {"void",     KW_VOID},
    {"extern",   KW_EXTERN},
    {"if",       KW_IF},
    {"else",     KW_ELSE},
    {"switch",   KW_SWITCH},
    {"case",     KW_CASE},
    {"default",  KW_DEFAULT},
    {"while",    KW_WHILE},
    {"do",       KW_DO},
    {"for",      KW_FOR},
    {"break",    KW_BREAK},
    {"continue", KW_CONTINUE},
    {"return",   KW_RETURN},
};

Tag Keywords::getKeywordTag(const std::string& key) {
    if (Keywords::KEYWORDS.find(key) != Keywords::KEYWORDS.end()) {
        return Keywords::KEYWORDS[key];
    }
    return IDENTIFER;
}

bool TokenId::equal(const Token& rhs) const { 
    if (!(this->Token::equal(rhs)))
        return false;

    const TokenId& r = dynamic_cast<const TokenId&>(rhs);
    return _name == r._name;
}

bool TokenStr::equal(const Token& rhs) const { 
    if (!(this->Token::equal(rhs)))
        return false;

    const TokenStr& r = dynamic_cast<const TokenStr&>(rhs);
    return _str == r._str;
}

bool TokenNum::equal(const Token& rhs) const { 
    if (!(this->Token::equal(rhs)))
        return false;

    const TokenNum& r = dynamic_cast<const TokenNum&>(rhs);
    return _v == r._v;
}

bool TokenChar::equal(const Token& rhs) const { 
    if (!(this->Token::equal(rhs)))
        return false;

    const TokenChar& r = dynamic_cast<const TokenChar&>(rhs);
    return _ch == r._ch;
}

bool operator==(const Token& lhs, const Token& rhs) {
  return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}
