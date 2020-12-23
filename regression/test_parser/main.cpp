#include "test_parser.h"

int main(int argc,char *argv[])
{
    // Args::showChar = true;
    Args::showToken = true;
    bool result = TestParser::TestFunc();
    printf("Test Parser Result: %s.\n", result ? "PASS" : "FAILED");

    return 0;
}