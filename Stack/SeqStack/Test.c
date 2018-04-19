#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"

void Test()
{
    SeqStack seq_stack;
    SeqStackInit(&seq_stack);
    SeqStackDisplay(&seq_stack, "初始化栈");
    DataType value;
    int ret = SeqStackTop(&seq_stack, &value);
    printf("ret=%d\n", ret);

    SeqStackPush(&seq_stack, 1);
    SeqStackPush(&seq_stack, 2);
    SeqStackPush(&seq_stack, 3);
    SeqStackPush(&seq_stack, 4);
    SeqStackDisplay(&seq_stack, "将四个元素入栈");

    ret = SeqStackTop(&seq_stack, &value);
    if (ret == 1)
    {
        printf("栈顶元素为：%d\n", value);
    }
}

int main()
{
    Test();
    system("pause");
    return 0;
}