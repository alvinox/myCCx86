#include "test_parser.h"


char* case_func0 = (char*)"cases/case_func0.c";
std::vector<TestParser::ExpectStruct> case_func0_expected = {
};
char* case_func1 = (char*)"cases/case_func1.c";
std::vector<TestParser::ExpectStruct> case_func1_expected = {
};
char* case_func2 = (char*)"cases/case_func2.c";
std::vector<TestParser::ExpectStruct> case_func2_expected = {
};
char* case_func3 = (char*)"cases/case_func3.c";
std::vector<TestParser::ExpectStruct> case_func3_expected = {
};
char* case_func4 = (char*)"cases/case_func4.c";
std::vector<TestParser::ExpectStruct> case_func4_expected = {
};
bool TestParser::TestFunc() {
    std::vector<TestParser> tests = {
        {case_func0, case_func0_expected},
        // {case_func1, case_func1_expected},
        // {case_func2, case_func2_expected},
        // {case_func3, case_func3_expected},
        // {case_func4, case_func4_expected},
    };

    int error_cnt = 0;
    for (const TestParser& test : tests) {

        Scanner scanner(test._name);
        Error   error(&scanner);
        Lexer   lexer(scanner);
        Parser  parser(lexer);

        parser.analyze();
        // size_t ref_cnt = test._expected.size();
        // for (size_t i = 0; i < ref_cnt; i++) {
            // Token* token     = lexer.tokenize();
            // Token* ref_token = test._expected[i].token;
            // if (!(*token == *ref_token)) {
            //     PDEBUG(FATAL "testcase '%s' at %zuth token: \n", test._name, i);
            //     PDEBUG(INFO "  expect:  %s\n", ref_token->toString().c_str());
            //     PDEBUG(INFO "  but got: %s\n", token->toString().c_str());
            //     // Error::errorNum++;
            //     error_cnt++;
            // }
            // delete ref_token;
        // }
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Finish Test Lexer: Error="<< error_cnt << std::endl;
    return error_cnt == 0;
}