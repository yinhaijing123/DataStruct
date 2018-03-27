//#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

#if 1

#define TEST_HEADER printf("====================================%s================================\n",__FUNCTION__)

void TestInit()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListDisplay(head,"��ʼ������");
}

void TestPushBack()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPushBack(&head,'a');
    LinkListDisplay(head,"Ϊ���������һ��Ԫ��");

    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'd');
    LinkListDisplay(head,"β������Ԫ��");

}

void TestPopBack()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPopBack(&head);
    LinkListDisplay(head,"βɾɾһ��������");

    LinkListPushBack(&head, 'a');
    LinkListPopBack(&head);
    LinkListDisplay(head, "βɾһ��ֻ��һ���ڵ������");

    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPopBack(&head);
    LinkListDisplay(head, "βɾ���ж��Ԫ�ص�����");

}

void TestPushFront()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPushFront(&head,'a');
    LinkListDisplay(head, "Ϊ���������һ��Ԫ��");

    LinkListPushFront(&head, 'b');
    LinkListPushFront(&head, 'c');
    LinkListPushFront(&head, 'd');
    LinkListDisplay(head, "ͷ������Ԫ��");
}

void TestPopFront()
{
    TEST_HEADER;

    LinkNode *head;
    LinkListInit(&head);
    LinkListPopFront(&head);
    LinkListDisplay(head, "ͷɾһ��������");

    LinkListPushBack(&head, 'a');
    LinkListPopFront(&head);
    LinkListDisplay(head, "ͷɾһ��ֻ��һ���ڵ������");

    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPopFront(&head);
    LinkListDisplay(head, "ͷɾ���ж��Ԫ�ص�����");
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
    LinkListDisplay(head, "β���ĸ�Ԫ��");

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
    LinkListDisplay(head, "Ϊ���������һ��Ԫ��a");

    LinkListInsert(&head, ret, 'c');
    LinkListDisplay(head, "��aԪ��ǰ����һ��Ԫ��c");

    LinkListInsertAfter(&head, ret, 'b');
    LinkListDisplay(head, "��aԪ�غ����һ��Ԫ��b");
    
    ret = LinkListPushBack(&head, 'f');
    LinkListDisplay(head, "β��fԪ��");

    LinkListInsert(&head, ret, 'g');
    LinkListDisplay(head, "��fԪ��ǰ����һ��Ԫ��g");

    LinkListInsertAfter(&head, ret, 'h');
    LinkListDisplay(head, "��fԪ�غ����һ��Ԫ��h");

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
    LinkListDisplay(head, "����5��Ԫ��");
    
    LinkListErase(&head, ret);
    LinkListDisplay(head, "ɾ��aԪ��");

    LinkNode *f=LinkListPushBack(&head, 'f');
    LinkNode *g=LinkListPushBack(&head, 'g');
    LinkListDisplay(head, "β��f��g");

    LinkListErase2(&head,f);
    LinkListDisplay(head, "ɾ��fԪ��");           //����ɾ������fԪ�أ�ʵ�����ǰ�g�ռ��ͷ��ˡ���:gԪ���Ǵ洢��֮ǰfԪ�ش�ŵĿռ���

    LinkListErase2(&head,f);                   
    LinkListDisplay(head, "ɾ��gԪ��");



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
    LinkListDisplay(head, "��������Ԫ��");
    LinkListRemove(&head, 'a');
    LinkListDisplay(head, "ɾ��aԪ��");
    LinkNodeRemove2(&head, 'a');
    LinkListDisplay(head, "ɾ��aԪ��");
    
    LinkNodeRemoveAll(&head, 'a');
    LinkListDisplay(head, "ɾ�����е�aԪ��");

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
    LinkListDisplay(head, "��������Ԫ��");

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
    LinkListDisplay(head, "��aԪ��ǰ��4��Ԫ��");
    
}
#endif

void TestJosephCycle()
{

    //����Լɪ��

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
    printf("\n�Ҵ�����%c\n", die->data);
   
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