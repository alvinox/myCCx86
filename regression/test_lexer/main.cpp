#include "test_lexer.h"

int main(int argc,char *argv[])
{
    // Args::showChar = true;
    Args::showToken = true;
    bool result = TestLexer::Entry();
    printf("Test Lexer Result: %s.\n", result ? "PASS" : "FAILED");

    return 0;
}