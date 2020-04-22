#include "test_scanner.h"

int main(int argc,char *argv[])
{
    // Args::showChar = true;
    bool result = TestScanner::Entry();
    printf("Test Scanner Result: %s.\n", result ? "PASS" : "FAILED");

    return 0;
}

