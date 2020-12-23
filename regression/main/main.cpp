#include <iostream>
#include <cstring>

#include "common.h"
#include "compiler.h"
#include "error.h"
/*
    命令格式：compile 源文件[源文件] [选项]
    选项：
        -o                    #执行优化
        -char                 #显示文件字符
        -token                #显示词法记号
        -symbol               #显示符号表信息
        -ir                   #显示中间代码
        -or                   #显示优化后的中间代码
        -block                #显示基本块和流图关系
        -h                    #显示帮助信息
*/

int main(int argc,char *argv[])
{
    std::vector<char*> srcfiles;

    if (argc > 1) {
        for (int i = 1; i < argc - 1; i++) {
            srcfiles.push_back(argv[i]);
        }

        char* opt = argv[argc - 1];
        if (strcmp(opt, "-char") == 0)         Args::showChar   = true;
        if (strcmp(opt, "-token") == 0)        Args::showToken  = true;
        else if (strcmp(opt, "-h") == 0)       Args::showHelp   = true;
        else                                   srcfiles.push_back(opt);
    }

    if (Args::showHelp) {
        std::cout<<
                "命令格式：cit 源文件[源文件][选项]\n"
                "选项：\n"
                "\t-o\t\t#执行优化\n"
                "\t-char\t\t#显示文件字符\n"
                "\t-token\t\t#显示词法记号\n"
                "\t-symbol\t\t#显示符号表信息\n"
                "\t-ir\t\t#显示中间代码\n"
                "\t-or\t\t#显示优化后的中间代码\n"
                "\t-block\t\t#显示基本块和流图关系\n"
                "\t-h\t\t#显示帮助信息\n"
                << std::endl;
    } else if (srcfiles.size() > 0 ) {
        Compiler compiler;
        for (char* name : srcfiles) {
            compiler.compile(name);
        }
        int error = Error::errorNum;
        int warn  = Error::warnNum;
        std::cout<<"Finish Compile: Error="<<error<<", Warn="<<warn<<"."<<std::endl;
    } else {
        std::cout << "命令格式错误！(使用-h选项查看帮助)"<< std::endl;
    }

    return 0;
}