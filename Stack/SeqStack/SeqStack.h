#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
#define MAX_SIZE 1000

typedef struct SeqStack
{
    DataType data[MAX_SIZE];
    int top;                              //top表示栈顶元素的下标
}SeqStack;

void SeqStackInit(SeqStack *seq_stack);
void SeqStackDestroy(SeqStack *seq_stack);
void SeqStackPush(SeqStack *seq_stack,DataType data);
void SeqStackPop(SeqStack *seq_stack);
int SeqStackTop(SeqStack *seq_stack, DataType *value);
void SeqStackDisplay(SeqStack *seq_stack,const char *msg);