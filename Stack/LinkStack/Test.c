#define _CRT_SECURE_NO_WARNINGS
#include"LinkStack.h"
void Test()
{
    LinkStack s;
    LinkStackInit(&s);
    LinkStackDisplay(&s);

    LinkStackPush(&s, 1);
    LinkStackPush(&s, 2);
    LinkStackPush(&s, 3);
    LinkStackPush(&s, 4);
    LinkStackDisplay(&s);

    DataType value;
    int ret = LinkStackTop(&s, &value);
    printf("ret=%d,栈顶元素为:%d\n", ret, value);

    LinkStackPop(&s);
    LinkStackDisplay(&s);
    ret = LinkStackTop(&s, &value);
    printf("ret=%d,栈顶元素为:%d\n", ret, value);

    LinkStackPop(&s);
    LinkStackDisplay(&s);
    ret = LinkStackTop(&s, &value);
    printf("ret=%d,栈顶元素为:%d\n", ret, value);

    LinkStackPop(&s);
    LinkStackDisplay(&s);
    ret = LinkStackTop(&s, &value);
    printf("ret=%d,栈顶元素为:%d\n", ret, value);

    LinkStackPop(&s);
    LinkStackDisplay(&s);
    ret = LinkStackTop(&s, &value);
    printf("ret=%d\n", ret);

    LinkStackPop(&s);
    LinkStackDisplay(&s);
    ret = LinkStackTop(&s, &value);
    printf("ret=%d\n",ret);
}
int main()
{
    Test();

    system("pause");
    return 0;
}