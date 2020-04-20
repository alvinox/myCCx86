#include "token.h"

std::unordered_map<int, std::string> token1Name = {
    {ERR,         "error"},
    {END,         "end"},
    {KW_INT,      "int"},
    {KW_CHAR,     "char"},
    {KW_VOID,     "void"},
    {IDENTIFER,   "identifier"},
    {NUMBER,      "number"},
    {CHAR,        "char"},
    {STRING,      "string"},
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