#include "test_lexer.h"

char* case1 = (char*)"cases/case0.c";
std::vector<TestLexer::ExpectStruct> case1_expected = {
    {new Token(KW_INT)},
    {new TokenId("main")},
    {new Token(END)},
};

bool TestLexer::Entry() {
    std::vector<TestLexer> tests = {
        {case1, case1_expected},
        // {case2, case2_expected},
    };

    for (const TestLexer& test : tests) {

        Scanner scanner(test._name);
        Lexer lexer(scanner);

        size_t ref_cnt = test._expected.size();
        for (size_t i = 0; i < ref_cnt; i++) {
            Token* token     = lexer.tokenize();
            Token* ref_token = test._expected[i].token;
            if (!(*token == *ref_token)) {
                PDEBUG(FATAL "testcase '%s' at %zuth token: \n", test._name, i);
                PDEBUG(INFO "  expect:  %s\n", token->toString().c_str());
                PDEBUG(INFO "  but got: %s\n", ref_token->toString().c_str());
                Error::errorNum++;
            }
            delete ref_token;
        }
    }
    int error = Error::errorNum;
    int warn  = Error::warnNum;
    std::cout<<"Finish Test Lexer: Error="<<error<<", Warn="<<warn<<"."<<std::endl;
    return error == 0 && warn == 0;
}