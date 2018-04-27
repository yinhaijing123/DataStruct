/****************************************************************************
                              最小栈的实现
****************************************************************************/

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType; 

typedef struct MinStackNode 
{
    DataType data;
    struct MinStackNode *next;                           //用链式存储方式，栈的容量比较灵活
}MinStackNode;

typedef struct MinStack
{
    struct MinStackNode *head;
}MinStack;

void MinStackInit(MinStack *MinStack);

void MinStackPush(MinStack *MinStack,DataType elem);     //入栈

void MinStackPop(MinStack *MinStack);                    //出栈

int MinStackTop(MinStack MinStack,DataType *value);      //取栈顶元素(即：最小元素)

void MinStackDestroy(MinStack *MinStack);
