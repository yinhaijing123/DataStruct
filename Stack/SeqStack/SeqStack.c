#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"

void SeqStackInit(SeqStack *seq_stack)
{
    assert(seq_stack);
    seq_stack->top = -1;                       
}
void SeqStackDestroy(SeqStack *seq_stack)
{
    assert(seq_stack);
    seq_stack->top = -1;
}
void SeqStackPush(SeqStack *seq_stack, DataType data)
{
    assert(seq_stack);
    if (seq_stack->top == MAX_SIZE - 1)         //栈满了
    {
        return;
    }
    seq_stack->data[++seq_stack->top] = data;
}

void SeqStackPop(SeqStack *seq_stack)
{
    assert(seq_stack);
    if (seq_stack->top == -1)                  //空栈
    {
        return;
    }
    --seq_stack->top;
}
int SeqStackTop(SeqStack *seq_stack, DataType *value)
{
    assert(seq_stack);
    if (seq_stack->top == -1)
    {
        return 0;
    }
    *value = seq_stack->data[seq_stack->top];
    return 1;
}
void SeqStackDisplay(SeqStack *seq_stack,const char *msg)
{
    printf("%s\n", msg);
    int i = 0;
    for (i = 0; i <= seq_stack->top; i++)
    {
        printf("%d\t", seq_stack->data[i]);
    }
    printf("\n");
}