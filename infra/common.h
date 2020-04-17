#ifndef __COMMON_H_
#define __COMMON_H_

#include <stdio.h>
#include <vector>
#include <list>
#include <string>

#define ui1 unsigned char
#define ui2 unsigned short
#define ui4 unsigned int

/*
    词法记号标签
*/
enum Tag
{
    ERR,                            //错误，异常
    END,                            //文件结束标记
    ID,                             //标识符
    KW_INT,KW_CHAR,KW_VOID,         //数据类型
    KW_EXTERN,                      //extern
    NUM,CH,STR,                     //字面量
    NOT,LEA,                        //单目运算 ! - & *
    INC,DEC,                        //++, --
    ADD,SUB,MUL,DIV,MOD,            //双目运算
    GT,GE,LT,LE,EQU,NEQU,           //比较运算符
    AND,OR,                         //逻辑运算
    LPAREN,RPAREN,                  //()
    LBRACK,RBRACK,                  //[]
    LBRACE,RBRACE,                  //{}
    COMMA,COLON,SEMICON,            //逗号,冒号,分号
    ASSIGN,                         //赋值
    KW_IF,KW_ELSE,                  //if-else
    KW_SWITCH,KW_CASE,KW_DEFAULT,   //swicth-case-deault
    KW_WHILE,KW_DO,KW_FOR,          //循环
    KW_BREAK,KW_CONTINUE,KW_RETURN  //break,continue,return
};

#endif