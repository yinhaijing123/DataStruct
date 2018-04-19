#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct LinkNode
{
    DataType data;
    struct LinkNode *next;                            //不能出现这样的定义方法：LinkNode *next(因为此时LinkNode还未定义出)
}LinkNode;

typedef struct LinkStack 
{
    LinkNode *top;
    size_t count;
}LinkStack;

void LinkStackInit(LinkStack *s);
void LinkStackDestroy(LinkStack *s);
void LinkStackPush(LinkStack *s,DataType data);
void LinkStackPop(LinkStack *s);
int LinkStackTop(LinkStack *s, DataType *value);
void LinkStackDisplay(LinkStack *s);