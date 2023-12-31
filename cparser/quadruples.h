#ifndef QUADRUPLES_H
#define QUADRUPLES_H
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
/* 声明结构体类型 */
struct FourGroup {
    int id;
    char *add1;
    char* add2;
    char* op;
    //jump 既可以运算结果 也可存储控制流跳转地址。
    char* jump;
    struct FourGroup* next;
};

extern struct FourGroup* head;
extern struct FourGroup* tail;
extern int FourGroupId;

void printFourGroup();
struct FourGroup* insert(char*op,char*add1,char*add2,char* jump);

#endif //QUADRUPLES_H
