//#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

#if 1

#define TEST_HEADER printf("====================================%s================================\n",__FUNCTION__)

void TestInit()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListDisplay(head,"初始化链表");
}

void TestPushBack()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPushBack(&head,'a');
    LinkListDisplay(head,"为空链表添加一个元素");

    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'd');
    LinkListDisplay(head,"尾插三个元素");

}

void TestPopBack()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPopBack(&head);
    LinkListDisplay(head,"尾删删一个空链表");

    LinkListPushBack(&head, 'a');
    LinkListPopBack(&head);
    LinkListDisplay(head, "尾删一个只有一个节点的链表");

    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPopBack(&head);
    LinkListDisplay(head, "尾删具有多个元素的链表");

}

void TestPushFront()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPushFront(&head,'a');
    LinkListDisplay(head, "为空链表添加一个元素");

    LinkListPushFront(&head, 'b');
    LinkListPushFront(&head, 'c');
    LinkListPushFront(&head, 'd');
    LinkListDisplay(head, "头插三个元素");
}

void TestPopFront()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPopFront(&head);
    LinkListDisplay(head, "头删一个空链表");

    LinkListPushBack(&head, 'a');
    LinkListPopFront(&head);
    LinkListDisplay(head, "头删一个只有一个节点的链表");

    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPopFront(&head);
    LinkListDisplay(head, "头删具有多个元素的链表");
}

void TestFind()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkNode * ret= LinkListFind(head, 'a');
    printf("ret expect NULL,actual %p\n", ret);


    LinkListPushBack(&head, 'a');
    LinkNode *pos= LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'd');
    LinkListDisplay(head, "尾插四个元素");

    ret=LinkListFind(head, 'b');
    printf("ret expect %p,actual %p\n", pos, ret);
    ret = LinkListFind(head,'f');
    printf("ret expect NULL,actual %p\n",ret);

}

void TestInsert()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkNode* ret = LinkListPushBack(&head, 'a');
    LinkListDisplay(head, "为空链表添加一个元素a");

    LinkListInsert(&head, ret, 'c');
    LinkListDisplay(head, "在a元素前插入一个元素c");

    LinkListInsertAfter(&head, ret, 'b');
    LinkListDisplay(head, "在a元素后插入一个元素b");
    
    ret = LinkListPushBack(&head, 'f');
    LinkListDisplay(head, "尾插f元素");

    LinkListInsert(&head, ret, 'g');
    LinkListDisplay(head, "在f元素前插入一个元素g");

    LinkListInsertAfter(&head, ret, 'h');
    LinkListDisplay(head, "在f元素后插入一个元素h");

}

void TestErase()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);

    LinkNode* ret = LinkListPushBack(&head, 'a');
    LinkListInsertAfter(&head, ret, 'b');
    LinkListInsertAfter(&head, ret, 'c');
    LinkListInsert(&head, ret, 'd');
    LinkListInsert(&head, ret, 'e');
    LinkListDisplay(head, "插入5个元素");
    
    LinkListErase(&head, ret);
    LinkListDisplay(head, "删除a元素");

    LinkNode *f=LinkListPushBack(&head, 'f');
    LinkNode *g=LinkListPushBack(&head, 'g');
    LinkListDisplay(head, "尾插f，g");

    LinkListErase2(&head,f);
    LinkListDisplay(head, "删除f元素");           //看似删除的是f元素，实际上是把g空间释放了。即:g元素是存储在之前f元素存放的空间上

    LinkListErase2(&head,f);                   
    LinkListDisplay(head, "删除g元素");



}


void TestRemove()
{
    TEST_HEADER;
    LinkNode *head;
    LinkListInit(&head);

    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'a');
    LinkListDisplay(head, "插入六个元素");
    LinkListRemove(&head, 'a');
    LinkListDisplay(head, "删除a元素");
    LinkNodeRemove2(&head, 'a');
    LinkListDisplay(head, "删除a元素");
    
    LinkNodeRemoveAll(&head, 'a');
    LinkListDisplay(head, "删除所有的a元素");

}
void TestSizeEmpty()
{
    TEST_HEADER;
    LinkNode *head;
    LinkListInit(&head);

    int ret = LinkListEmpty(head);
    printf("LinkEmpty=%d\n", ret);
    printf("LinkSize=%d\n", LinkListSize(head));

    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'a');

    ret = LinkListEmpty(head);

    printf("LinkEmpty=%d\n", ret);
    printf("LinkSize=%d\n", LinkListSize(head));
}
void TestReversePrint()
{
    TEST_HEADER;
    LinkNode *head;
    LinkListInit(&head);
   
    LinkListReversePrint(head);
    printf("\n");

    LinkListPushBack(&head, 'a');
    LinkListReversePrint(head);
    printf("\n");

    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'd');
    LinkListPushBack(&head, 'e');
    LinkListPushBack(&head, 'f');
    LinkListDisplay(head, "插入六个元素");

    LinkListReversePrint(head);
    printf("\n");

}

void TestInserBerfore()
{
    TEST_HEADER;
    LinkNode *head;
    LinkListInit(&head);

    LinkNode *pos=LinkListPushBack(&head, 'a');
    LinkListInsertBefore(&head, pos, 'b');
    LinkListInsertBefore(&head, pos, 'c');
    LinkListInsertBefore(&head, pos, 'd');
    LinkListInsertBefore(&head, pos, 'e');
    LinkListDisplay(head, "在a元素前插4个元素");
    
}
#endif

void TestJosephCycle()
{

    //构造约瑟夫环

    TEST_HEADER;
    LinkNode *head = NULL;
    LinkListInit(&head);
    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'd');
    LinkListPushBack(&head, 'e');
    LinkListPushBack(&head, 'f');
    LinkListPushBack(&head, 'g');
    LinkListPushBack(&head, 'h');
    LinkNode *pos = LinkListPushBack(&head, 'i');
    pos->next = head;                               
     
    LinkNode *die = JosephCycle(head,3);
    printf("\n幸存者是%c\n", die->data);
   
}

int main()
{
    TestInit();
    TestPushBack();
    TestPopBack();
    TestPushFront();
    TestPopFront();
    TestFind();
    TestInsert();
    TestErase();
    TestRemove();
    TestSizeEmpty();
    TestReversePrint();
    TestInserBerfore();
    TestJosephCycle();

    system("pause");
    return 0;
}