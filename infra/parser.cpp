#include "parser.h"
#include "compiler.h"

#define OR_TAG(T) || _look->tag() == T
#define IS_TAG(T) _look->tag() == T
#define TYPE_FIRST IS_TAG(KW_INT)OR_TAG(KW_CHAR)OR_TAG(KW_VOID)
#define COMPARATOR IS_TAG(GT)OR_TAG(GE)OR_TAG(LT)OR_TAG(LE)OR_TAG(EQU)OR_TAG(NEQU)
#define STATEMENT_FIRST IS_TAG(KW_RETURN)
/* parser entry */
void Parser::analyze() {
    move();
    program();
}

// <program>			->	<segment><program>|^
void Parser::program() {
    if (IS_TAG(END)) {
        return;
    } else {
        segment();
        program();
    }
}

// <segment>			->	EXTERN <type><def>|<type><def>
void Parser::segment() {
    bool ext = match(KW_EXTERN);
    Tag t = type();
    def(ext, t);
}


/* define or declare */

// <def>					->	MUL IDENTIFER <init><deflist>|IDENTIFER <idtail>
void Parser::def(bool ext, Tag t) {
    std::string name;
    if (match(MUL)) {
        // ptr
    } else {
        // var, array, func
        if (IS_TAG(IDENTIFER)) {
            name = dynamic_cast<const TokenId*>(_look)->name();
            move();
        } else {
            recovery();
        }
        idtail(ext, t, false, name);
    }
}

// <deflist>			->	COMMA <defdata> <deflist>|SEMICON
void Parser::deflist(bool ext,Tag t) {
    if (match(COMMA)) {
        defdata(ext, t);
        deflist(ext, t);
    } else if (match(SEMICON)) {
        return;
    } else {
        recovery();
    }
}

// <defdata>			->	IDENT <varrdef>|MUL IDENT <init>
Var* Parser::defdata(bool ext,Tag t) {
    std::string name;

    if (IS_TAG(IDENTIFER)) {
        name = dynamic_cast<const TokenId*>(_look)->name();
        move();
        Var* v = varrdef(ext, t, false, name);
        return v;
    } else if (match(MUL)) {
        if (IS_TAG(IDENTIFER)) {
            name = dynamic_cast<const TokenId*>(_look)->name();
            move();
        } else {
            recovery();
        }
        return init(ext, t, true, name);
    } else {
        recovery();
    }
}

// <idtail>			->	<varrdef><deflist>|LPAREN <para> RPAREN <funtail>
void Parser::idtail(bool ext, Tag t, bool ptr, const std::string& name) {
    if (match(LPAREN)) {
        // func
        std::vector<Var*> para_list;
        para(para_list);
        if (!(match(RPAREN))) {
            recovery();
        }
        Fun* fun = new Fun(ext, t, name, para_list);
        funtail(fun);
    } else {
        // variable
        Var* v = varrdef(ext, t, false, name);
        deflist(ext, t);
    }
}

Var* Parser::varrdef(bool ext, Tag t, bool ptr, const std::string& name) {
    if (match(LBRACK)) {
        int len = 0;
        if (IS_TAG(NUMBER)) {
            len = dynamic_cast<const TokenNum*>(_look)->value();
            move();
        } else {
            recovery();
        }
        if (!match(RBRACK)) {
            recovery();
        }
        return new Var(ext, t, name, len);
    } else {
        // init
        return init(ext, t, ptr, name);
    }
}

// <init>				->	ASSIGN <expr>|^
Var* Parser::init(bool ext,Tag t,bool ptr,const std::string& name) {
    Var* initVal = NULL;
    if (match(ASSIGN)) {
        initVal = expr();
    } else {
        return new Var(ext, t, ptr, name);
    }
}

/* function */

// <para>				->	<type><paradata><paralist>|^
void Parser::para(std::vector<Var*>& list) {
    if (IS_TAG(RPAREN)) {
        return;
    }

    Tag t  = type();
    Var* v = paradata(t);
    list.push_back(v);
    paralist(list);
}

// <paradata>		->	MUL IDENTIFIER |IDENTIFIER <paradatatail>
Var* Parser::paradata(Tag t) {
    std::string name;
    if (match(MUL)) {
        if (IS_TAG(IDENTIFER)) {
            name = dynamic_cast<const TokenId*>(_look)->name();
            move();
        } else {
            recovery();
        }
        return new Var(false, t, true, name);
    } else if (IS_TAG(IDENTIFER)) {
        name = dynamic_cast<const TokenId*>(_look)->name();
        move();
        Var* v = paradatatail(t, name);
        return v;
    } else {
        recovery();
        return NULL;
    }
}

// <paradatatail>->	LBRACK NUM RBRACK|^
Var* Parser::paradatatail(Tag t, const std::string& name) {
    if (match(LBRACK)) {
        int len = -1;
        if (IS_TAG(NUMBER)) {
            len = dynamic_cast<const TokenNum*>(_look)->value();
            move();
            return new Var(false, t, name, len);
        } else {
            recovery();
            return NULL;
        }
    } else {
        return new Var(false, t, false, name);
    }
}

// <funtail>			->	<block>|SEMICON
void Parser::funtail(Fun* f) {
    if (match(SEMICON)) {
    } else {
        block();
    }
}

// <paralist>		->	COMMA <type><paradata><paralist>|^
void Parser::paralist(std::vector<Var*>& list) {
    if (match(COMMA)) {
        Tag t = type();
        Var* v = paradata(t);
        list.push_back(v);
        paralist(list);
    }
}

// <block>				->	LBRACE <subprogram> RBRACE
void Parser::block() {
    if (!(match(LBRACE))) {
        recovery();
    }
    subprogram();
    if (!(match(RBRACE))) {
        recovery();
    }
}

// <subprogram>	->	<localdef><subprogram>|<statements><subprogram>|^
void Parser::subprogram() {
    if (TYPE_FIRST) {
        // local variable
        localdef();
        subprogram();
    } else if (STATEMENT_FIRST) {
        // statement
        statement();
        subprogram();
    }
}

// <localdef>		->	<type><defdata><deflist>
void Parser::localdef() {
    Tag t = type();
    Var* var = defdata(false, t);
    deflist(false, t);
}

/* statement */
// <statement>		->	<altexpr>semicon
// 									|<whilestat>|<forstat>|<dowhilestat>
// 									|<ifstat>|<switchstat>
// 									|rsv_break semicon
// 									|rsv_continue semicon
// 									|rsv_return<altexpr>semicon
void Parser::statement() {
    switch (_look->tag()) {
        case KW_RETURN: {
            move();
            if (!match(SEMICON)) {
                recovery();
            }
        } break;
        default: ;
    }
}

/* expression */
Var* Parser::expr() {
    return assexpr();
}

Var* Parser::assexpr() {
    Var* lval = orexpr();
    return asstail(lval);
}

Var* Parser::asstail(Var* lval) {
    if (match(ASSIGN)) {
        Var* rval = orexpr();
        Var* v    = asstail(rval);
        return v;
    }

    return lval;
}

Var* Parser::orexpr() {
    Var* lval = andexpr();
    return ortail(lval);
}

Var* Parser::ortail(Var*lval) {
    if (match(OR)) {
        Var* rval = andexpr();
        Var* v    = ortail(rval);
        return v;
    }

    return lval;
}

Var* Parser::andexpr() {
    Var* lval = cmpexpr();
    return andtail(lval);
}

Var* Parser::andtail(Var*lval) {
    if (match(AND)) {
        Var* rval = cmpexpr();
        Var* v    = andtail(rval);
        return v;
    }

    return lval;
}

Var* Parser::cmpexpr() {
    Var* lval = aloexpr();
    return cmptail(lval);
}

Var* Parser::cmptail(Var*lval) {
    if (COMPARATOR) {
        Tag opt   = cmps();
        Var* rval = aloexpr();
        Var* v    = cmptail(rval);
        return v;
    }

    return lval; 
}

Var* Parser::aloexpr() {
    Var* lval = itemexpr();
    return alotail(lval);
}

Var* Parser::alotail(Var*lval) {
    if (IS_TAG(ADD)OR_TAG(SUB)) {
        Tag opt   = adds();
        Var* rval = itemexpr();
        Var* v    = alotail(rval);
        return v;
    }

    return lval; 
}

/* usefull methods */

// <type>				->	INT|CHAR|VOID
Tag Parser::type() {
    Tag t = KW_INT;
    if (TYPE_FIRST) {
        t = _look->tag();
        move();
    } else {
        recovery();
    }

    return t;
}

Tag Parser::cmps() {
    Tag t = GE;
    if (COMPARATOR) {
        t = _look->tag();
    } else {
        recovery();
    }

    return t;
}

Tag Parser::adds() {
    Tag t = GE;
    if (IS_TAG(ADD)OR_TAG(SUB)) {
        t = _look->tag();
    } else {
        recovery();
    }

    return t;
}

bool Parser::match(Tag need) {
    if (IS_TAG(need)) {
        move();
        return true;
    } else {
        return false;
    }
}

void Parser::move() {
    _look = _lexer.tokenize();
    if (Args::showToken) {
        printf("%s\n", _look->toString().c_str());
    }
}

void Parser::recovery() {
    printf("========== need recovery!\n");
}