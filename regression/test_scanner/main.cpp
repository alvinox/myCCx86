#include <iostream>
#include <cstring>

#include "common.h"
#include "compiler.h"
#include "error.h"

int main(int argc,char *argv[])
{
    std::vector<char*> srcfiles;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            srcfiles.push_back(argv[i]);
        }
    }

    if (srcfiles.size() > 0 ) {
        Compiler compiler;
        for (char* name : srcfiles) {
            compiler.compile(name);
        }
        int error = Error::errorNum;
        int warn  = Error::warnNum;
        std::cout <<"Finish Compile: Error=" << error << ", Warn=" << warn <<"." << std::endl;
    } else {
        std::cerr <<"Error: No input file!" << std::endl;
    }

    return 0;
}