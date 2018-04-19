#define _CRT_SECURE_NO_WARNINGS
#include"LinkStack.h"

void LinkStackInit(LinkStack *s)
{
    assert(s);
    s->count = 0;
    s->top = NULL;
}

void DestroyNode(LinkNode *to_delete)
{
    assert(to_delete);
    free(to_delete);
    to_delete = NULL;
}

void LinkStackDestroy(LinkStack *s)
{
    assert(s);
    while(s->top != NULL)
    {
        //LinkStackPop(s);
        LinkNode *to_delete = s->top;
        s->top = to_delete->next;
        DestroyNode(to_delete);
    }
}

LinkNode *CreatNode(DataType data)                                             //该接口可封装在内部，不需要对外部公开。
{
    LinkNode *Node = (LinkNode *)malloc(sizeof(LinkNode));
    Node->data = data;
    Node->next = NULL;
    return Node;
}

void LinkStackPush(LinkStack *s, DataType data)
{
    assert(s);
    LinkNode *new_node = CreatNode(data);
    
    new_node->next = s->top;
    s->top = new_node;
    ++s->count;
}

void LinkStackPop(LinkStack *s)
{
    assert(s);
    if (s->top == NULL)                                   //空栈
    {
        return;
    }
    LinkNode *to_delete = s->top;
    s->top = to_delete->next;
    DestroyNode(to_delete);
    --s->count;
}

int LinkStackTop(LinkStack *s, DataType *value)
{
    assert(s);
    if (s->top == NULL)
    {
        return 0;
    }
    *value = s->top->data;
    return 1;
}

void LinkStackDisplay(LinkStack *s)
{
    assert(s);
    LinkNode *cur = s->top;
    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}