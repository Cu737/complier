#include "quadruples.h"
//
// Created by lenovo on 2023/12/10.
//
/* 声明与结构体相关的函数 */
int id = 1;
struct FourGroup * head = NULL;
struct FourGroup * tail = NULL;
//这边返回值是为了让大家很方便的获得这个值，这样大家以后就可以对其属性进行修改了
//比如 $$ = insert($$1->op,"a","b","temp"); $$->add1 = $$1->name
struct FourGroup* insert(char*op,char*add1,char*add2,char *jump) {
    struct FourGroup* es= malloc(sizeof(struct FourGroup));
    es->id = id;
    id ++;
    es->op = op;
    es->add1 = add1;
    es->add2 = add2;
    es->jump = jump;
    if(head == NULL)
    {
        head = es;
        tail = es;
    }
    else
    {
        tail->next = es;
        tail = es;
        tail->next = NULL;
    }
    return es;
}

void printFourGroup()
{
    struct FourGroup* temp = head;
    while (temp != NULL)
    {
        printf("(%d,%s,%s,%s,%s)\n",temp->id,temp->op,temp->add1,temp->add2,temp->jump);
        temp = temp->next;
    }
}
