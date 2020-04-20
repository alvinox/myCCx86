#ifndef __TOKEN_H_
#define __TOKEN_H_

#include <unordered_map>
#include <sstream>

#include "common.h"

enum Tag {
    ERR,
    END,
    KW_INT, KW_CHAR, KW_VOID,
    IDENTIFER, NUMBER, CHAR, STRING,
};

extern std::unordered_map<int, std::string> token1Name;

class Keywords {
  public:
    static std::unordered_map<std::string, Tag> KEYWORDS;
    static Tag getKeywordTag(const std::string& key);
};

class Token {
  public:
    Token(Tag t) : _tag(t) { }
    virtual ~Token() { }
  public:
    virtual std::string toString() const { return token1Name[_tag]; }
    std::string bracketString() const { return std::string("[") + toString() + "]:"; }
    Tag tag() const { return _tag; }

  private:
    Tag _tag;
};

class Id final : public Token {
  public:
    Id(const std::string& name) : Token(IDENTIFER), _name(name) { }
  public:
    virtual std::string toString() const { return Token::bracketString() + _name; }
    std::string name() const { return _name; }

  private:
    std::string _name;
};

class Str final : public Token {
  public:
    Str(const std::string& str) : Token(STRING), _str(str) { }
  public:
    virtual std::string toString() const { return Token::bracketString() + _str; }
    std::string str() const { return _str; }

  private:
    std::string _str;
};

class Num final : public Token {
  public:
    Num(int v) : Token(NUMBER), _v(v) { }
  public:
    virtual std::string toString() const {
      std::stringstream ss;
      ss << _v;
      return Token::bracketString() + ss.str();
    }
    int value() const { return _v; }
  private:
    int _v;
};

class Char final : public Token {
  public:
    Char(char c) : Token(CHAR), _ch(c) { }
  public:
    virtual std::string toString() const { return Token::bracketString() + _ch; }
    char ch() const { return _ch; }
  private:
    char _ch;
};

#endif // __TOKEN_H_