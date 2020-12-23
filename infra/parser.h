#ifndef __PARSER_H_
#define __PARSER_H_

#include "lexer.h"
#include "symbol.h"

class Parser {
  public:
    Parser(Lexer& lexer) : _lexer(lexer), _look(NULL) { }

  public:
    /* parser entry */
    void analyze();
    void program();
    void segment();

    /* define or declare */
    void def(bool ext, Tag t);
    void deflist(bool ext,Tag t);
    Var* defdata(bool ext,Tag t);
    void idtail(bool ext, Tag t, bool ptr, const std::string& name);
    Var* varrdef(bool ext, Tag t, bool ptr, const std::string& name);
    Var* init(bool ext,Tag t,bool ptr,const std::string& name);

    /* function */
    void para(std::vector<Var*>& list);
    Var* paradata(Tag t);
    Var* paradatatail(Tag t, const std::string& name);
    void paralist(std::vector<Var*>& list);
    void funtail(Fun* f);
    void block();
    void subprogram();
    void localdef();

    /* statement */
    void statement();

    /* expression */
    Var* expr();
    Var* assexpr();
    Var* asstail(Var* lval);
    Var* orexpr();
    Var* ortail(Var*lval);
    Var* andexpr();
    Var* andtail(Var*lval);
    Var* cmpexpr();
    Var* cmptail(Var*lval);
    Var* aloexpr();
    Var* alotail(Var*lval);

    /* usefull methods */
    Tag  type();
    Tag  cmps();
    Tag  adds();

    void move();
    bool match(Tag need);
    void recovery();
    Token* getLook() const { return _look; }

  private:
    Lexer&   _lexer;
    Token*   _look;
};


#endif // __PARSER_H_