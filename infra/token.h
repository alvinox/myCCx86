#ifndef __TOKEN_H_
#define __TOKEN_H_

#include <unordered_map>
#include <sstream>
#include <typeinfo>

#include "common.h"

enum Tag {
    ERR,
    COMMENT,
    END,
    KW_INT, KW_CHAR, KW_VOID, KW_EXTERN,
    KW_IF, KW_ELSE,
    KW_SWITCH, KW_CASE, KW_DEFAULT,
    KW_WHILE, KW_DO, KW_FOR,
    KW_BREAK, KW_CONTINUE, KW_RETURN,
    IDENTIFER, NUMBER, CHAR, STRING,
    ADD, SUB, MUL, DIV, MOD,
    INC, DEC,
    GT, GE, LT, LE, EQU, NEQU,
    AND, OR, BANG, LEA, ASSIGN,
    LPAREN, RPAREN,
    LBRACK, RBRACK,
    LBRACE, RBRACE,
    COMMA, COLON, SEMICON,
};

extern std::unordered_map<int, std::string> tokenName;

class Keywords {
  public:
    static std::unordered_map<std::string, Tag> KEYWORDS;
    static Tag getKeywordTag(const std::string& key);
};

class Token {
  public:
    friend bool operator==(const Token& lhs, const Token& rhs);
  public:
    Token(Tag t) : _tag(t) { }
    virtual ~Token() { }
  public:
    virtual bool equal(const Token& rhs) const { return _tag == rhs._tag; }
    virtual std::string toString() const { return tokenName[_tag]; }
    std::string bracketString() const { return std::string("[") + Token::toString() + "]:"; }
    Tag tag() const { return _tag; }

  private:
    Tag _tag;
};

class TokenId final : public Token {
  public:
    TokenId(const std::string& name) : Token(IDENTIFER), _name(name) { }
  public:
    virtual bool equal(const Token& rhs) const override;
    virtual std::string toString() const override { return Token::bracketString() + _name; }
    std::string name() const { return _name; }

  private:
    std::string _name;
};

class TokenStr final : public Token {
  public:
    TokenStr(const std::string& str) : Token(STRING), _str(str) { }
  public:
    virtual bool equal(const Token& rhs) const override;
    virtual std::string toString() const override { return Token::bracketString() + _str; }
    std::string str() const { return _str; }

  private:
    std::string _str;
};

class TokenNum final : public Token {
  public:
    TokenNum(int v) : Token(NUMBER), _v(v) { }
  public:
    virtual bool equal(const Token& rhs) const override;
    virtual std::string toString() const override {
      std::stringstream ss;
      ss << _v;
      return Token::bracketString() + ss.str();
    }
    int value() const { return _v; }
  private:
    int _v;
};

class TokenChar final : public Token {
  public:
    TokenChar(char c) : Token(CHAR), _ch(c) { }
  public:
    virtual bool equal(const Token& rhs) const override;
    virtual std::string toString() const override { return Token::bracketString() + _ch; }
    char ch() const { return _ch; }
  private:
    char _ch;
};

#endif // __TOKEN_H_