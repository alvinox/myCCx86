#include "token.h"

std::unordered_map<int, std::string> tokenName = {
    {ERR,         "ERROR"},
    {END,         "END"},
    {KW_INT,      "INT"},
    {KW_CHAR,     "CHAR"},
    {KW_VOID,     "VOID"},
    {IDENTIFER,   "IDENTIFIER"},
    {NUMBER,      "NUMBER"},
    {CHAR,        "CHAR"},
    {STRING,      "STRING"},
};

std::unordered_map<std::string, Tag> Keywords::KEYWORDS = {
    {"int",      KW_INT},
    {"char",     KW_CHAR},
    {"void",     KW_VOID},
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