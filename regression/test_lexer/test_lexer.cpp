#include "test_lexer.h"

char* case00 = (char*)"cases/case00.c";
std::vector<TestLexer::ExpectStruct> case00_expected = {
    {new Token(KW_INT)},
    {new TokenId("main")},
    {new TokenStr("case0")},
    {new TokenStr("")},
    {new TokenStr("aa\t\naa\'\"\r\\")},
    {new Token(ERR)},
    {new Token(ERR)},
    {new Token(END)},
};

char* case01 = (char*)"cases/case01.c";
std::vector<TestLexer::ExpectStruct> case01_expected = {
    {new TokenNum(1231)},
    {new TokenNum(0)},
    {new TokenNum(0)},
    {new TokenNum(1)},
    {new TokenNum(12124546)},
    {new TokenNum(0x01FD)},
    {new TokenNum(0b01110)},
    {new TokenId("x0")},
    {new TokenId("b0")},
    {new TokenNum(0123)},
    {new Token(ERR)}, // 0P
    {new Token(ERR)}, // 0fd
    {new Token(ERR)}, // 1P
    {new Token(ERR)}, // 1Pxx
    {new Token(ERR)}, // 0x
    {new Token(ERR)}, // 0xm
    {new Token(ERR)}, // 0b
    {new Token(ERR)}, // 0bmm
    {new Token(ERR)}, // 0x12m
    {new Token(ERR)}, // 0xb11m
    {new Token(ERR)}, // 0xb2
    {new Token(ERR)}, // 0xb2m
    {new Token(END)},
};

char* case02 = (char*)"cases/case02.c";
std::vector<TestLexer::ExpectStruct> case02_expected = {
    {new TokenChar('c')},
    {new TokenChar(' ')},
    {new Token(ERR)}, 
    {new TokenChar('p')},
    {new Token(ERR)}, 
    {new TokenChar('p')},
    {new Token(ERR)}, 
    {new Token(ERR)}, 
    {new Token(ERR)}, 
    {new Token(ERR)}, 
    {new Token(END)},
};

char* case03 = (char*)"cases/case03.c";
std::vector<TestLexer::ExpectStruct> case03_expected = {
    {new TokenStr("aaaa")},
    {new Token(ERR)},
    {new Token(INC)},
    {new Token(DEC)},
    {new Token(COMMENT)},
    {new Token(COMMENT)},
    {new Token(COMMENT)},
    {new Token(ERR)},
    {new Token(END)},
};

char* case04 = (char*)"cases/case04.c";
std::vector<TestLexer::ExpectStruct> case04_expected = {
    {new Token(OR)},
    {new Token(ERR)},
    {new Token(LBRACE)},
    {new Token(RBRACK)},
    {new Token(COMMA)},
    {new Token(END)},
};

char* case1 = (char*)"cases/case1.c";
std::vector<TestLexer::ExpectStruct> case1_expected = {
    {new Token(KW_INT)},
    {new TokenId("main")},
    {new Token(LPAREN)},
    {new Token(RPAREN)},
    {new Token(LBRACE)},

    {new Token(KW_INT)},
    {new TokenId("a")},
    {new Token(ASSIGN)},
    {new TokenNum(0)},
    {new Token(SEMICON)},

    {new Token(KW_CHAR)},
    {new Token(MUL)},
    {new TokenId("b")},
    {new Token(ASSIGN)},
    {new TokenStr("ssss")},
    {new Token(SEMICON)},

    {new Token(KW_RETURN)},
    {new Token(SUB)},
    {new TokenNum(1)},
    {new Token(SEMICON)},

    {new Token(RBRACE)},

    {new Token(END)},
};

char* case2 = (char*)"cases/case2.c";
std::vector<TestLexer::ExpectStruct> case2_expected = {
    {new Token(KW_INT)},
    {new TokenId("fun")},
    {new Token(LPAREN)},
    {new Token(RPAREN)},
    {new Token(LBRACE)},
    {new Token(KW_INT)},
    {new TokenId("a")},
    {new Token(ASSIGN)},
    {new TokenNum(1)},
    {new Token(COMMA)},
    {new TokenId("b")},
    {new Token(ASSIGN)},
    {new TokenId("a")},
    {new Token(ADD)},
    {new TokenNum(2)},
    {new Token(COMMA)},
    {new TokenId("c")},
    {new Token(ASSIGN)},
    {new TokenId("a")},
    {new Token(MUL)},
    {new TokenId("b")},
    {new Token(COMMA)},
    {new TokenId("d")},
    {new Token(ASSIGN)},
    {new TokenId("b")},
    {new Token(MUL)},
    {new TokenId("c")},
    {new Token(COMMA)},
    {new TokenId("e")},
    {new Token(ASSIGN)},
    {new TokenNum(10)},
    {new Token(SEMICON)},
    {new Token(KW_INT)},
    {new TokenId("i")},
    {new Token(ASSIGN)},
    {new TokenNum(10)},
    {new Token(SEMICON)},
    {new Token(KW_IF)},
    {new Token(LPAREN)},
    {new TokenId("a")},
    {new Token(GT)},
    {new TokenId("b")},
    {new Token(RPAREN)},
    {new Token(LBRACE)},
    {new TokenId("c")},
    {new Token(ASSIGN)},
    {new TokenId("a")},
    {new Token(MUL)},
    {new TokenId("b")},
    {new Token(SEMICON)},
    {new TokenId("d")},
    {new Token(ASSIGN)},
    {new TokenId("b")},
    {new Token(DIV)},
    {new TokenId("c")},
    {new Token(SEMICON)},
    {new TokenId("e")},
    {new Token(ASSIGN)},
    {new TokenId("c")},
    {new Token(MOD)},
    {new TokenId("d")},
    {new Token(SEMICON)},
    {new Token(RBRACE)},
    {new Token(KW_DO)},
    {new Token(LBRACE)},
    {new TokenId("c")},
    {new Token(ASSIGN)},
    {new TokenId("a")},
    {new Token(MUL)},
    {new TokenId("b")},
    {new Token(SEMICON)},
    {new TokenId("d")},
    {new Token(ASSIGN)},
    {new TokenId("b")},
    {new Token(MUL)},
    {new TokenId("c")},
    {new Token(SEMICON)},
    {new TokenId("e")},
    {new Token(ASSIGN)},
    {new TokenId("c")},
    {new Token(MUL)},
    {new TokenId("d")},
    {new Token(SEMICON)},
    {new Token(RBRACE)},
    {new Token(KW_WHILE)},
    {new Token(LPAREN)},
    {new TokenId("i")},
    {new Token(DEC)},
    {new Token(RPAREN)},
    {new Token(SEMICON)},
    {new Token(KW_RETURN)},
    {new TokenId("a")},
    {new Token(ADD)},
    {new TokenId("e")},
    {new Token(SEMICON)},
    {new Token(RBRACE)},
    {new Token(KW_INT)},
    {new TokenId("main")},
    {new Token(LPAREN)},
    {new Token(RPAREN)},
    {new Token(LBRACE)},
    {new Token(KW_INT)},
    {new TokenId("i")},
    {new Token(ASSIGN)},
    {new TokenNum(500)},
    {new Token(COMMA)},
    {new TokenId("j")},
    {new Token(SEMICON)},
    {new Token(KW_WHILE)},
    {new Token(LPAREN)},
    {new TokenId("i")},
    {new Token(DEC)},
    {new Token(RPAREN)},
    {new Token(LBRACE)},
    {new TokenId("j")},
    {new Token(ASSIGN)},
    {new TokenId("fun")},
    {new Token(LPAREN)},
    {new Token(RPAREN)},
    {new Token(SEMICON)},
    {new Token(RBRACE)},
    {new Token(KW_RETURN)},
    {new TokenId("i")},
    {new Token(ASSIGN)},
    {new TokenId("j")},
    {new Token(SEMICON)},
    {new Token(RBRACE)},
    {new Token(END)},
};

bool TestLexer::Entry() {
    std::vector<TestLexer> tests = {
        {case00, case00_expected},
        {case01, case01_expected},
        {case02, case02_expected},
        {case03, case03_expected},
        {case04, case04_expected},

        {case1,  case1_expected},
        {case2,  case2_expected},
    };

    int error_cnt = 0;
    for (const TestLexer& test : tests) {

        Scanner scanner(test._name);
        Error   error(&scanner);
        Lexer   lexer(scanner);

        size_t ref_cnt = test._expected.size();
        for (size_t i = 0; i < ref_cnt; i++) {
            Token* token     = lexer.tokenize();
            Token* ref_token = test._expected[i].token;
            if (!(*token == *ref_token)) {
                PDEBUG(FATAL "testcase '%s' at %zuth token: \n", test._name, i);
                PDEBUG(INFO "  expect:  %s\n", ref_token->toString().c_str());
                PDEBUG(INFO "  but got: %s\n", token->toString().c_str());
                // Error::errorNum++;
                error_cnt++;
            }
            delete ref_token;
        }
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Finish Test Lexer: Error="<< error_cnt << std::endl;
    return error_cnt == 0;
}