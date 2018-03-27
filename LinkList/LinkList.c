#include"LinkList.h"

LinkNode *CreatNode(LinkDataType value)
{
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void LinkListInit(LinkNode **head)
{
    assert(head);
    *head = NULL;
}

LinkNode* LinkListPushBack(LinkNode **head, LinkDataType value)
{
    assert(head);
    if (*head == NULL)                                                 //空链表
    {
        *head = CreatNode(value);
        return *head;
    }
    LinkNode *new_node = CreatNode(value);
    LinkNode *cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_node;
    return new_node;
}

void LinkListDisplay(LinkNode *head,char *msg)
{
    printf("[%s]\n", msg);
    if (head == NULL)
    {
        printf("空链表\n");
        printf("\n");
        return;
    }
    LinkNode *cur = head;
    while (cur != NULL)
    {
        printf("[%c：%p]->", cur->data,cur);
        cur = cur->next;
    }
    printf("[NULL]\n");
}
void DestroyNode(LinkNode *to_delete)
{
    free(to_delete);
}

void LinkListPopBack(LinkNode **head)
{
    assert(head);
    if (*head == NULL)                       //空链表
    {
        return;
    }
    if ((*head)->next == NULL)               //一个节点
    {
        DestroyNode(*head);
        *head = NULL;
        return;
    }
    LinkNode *cur = *head;
    LinkNode *pre = NULL;
    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = NULL;
    DestroyNode(cur);
    return;
}

void LinkListPushFront(LinkNode **head, LinkDataType value)
{
    assert(head);
    if (*head == NULL)
    {
        *head = CreatNode(value);
        return;
    }
    LinkNode *new_node = CreatNode(value);
    new_node->next = *head;
    *head = new_node;
    return;
}

void LinkListPopFront(LinkNode **head)
{
    assert(head);
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        DestroyNode(*head);
        *head = NULL;
        return;
    }
    LinkNode *to_delete = *head;
    *head = (*head)->next;
    DestroyNode(to_delete);
    return;
}

LinkNode* LinkListFind(LinkNode *head, LinkDataType to_find)
{
    if (head == NULL)
    {
        return NULL;
    }
    LinkNode *cur = head;
    while (cur!= NULL)
    {
        if (cur->data == to_find)
        {
            return cur;
        }
        cur = cur->next;
    }
  
    return NULL;
}

void LinkListInsert(LinkNode **head, LinkNode *pos, LinkDataType value)
{
    assert(head);
    if (*head == NULL)
    {
        return;
    }
    if (*head == pos)                                          //插入位置为头节点处
    {
        LinkListPushFront(head, value);
        return;
    }
    LinkNode *cur = *head;
    LinkNode *pre = *head;
    while (cur != NULL)
    {
        if (cur == pos)
        {
            LinkNode* new_node = CreatNode(value);
            pre->next = new_node;
            new_node->next = cur;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}

void LinkListInsertAfter(LinkNode **head, LinkNode *pos, LinkDataType value)
{
    assert(head);
    if (*head == NULL)                
    {
        return;
    }
    LinkNode *cur = *head;
    while (cur != NULL)
    {
        if (cur == pos)
        {
            LinkNode *new_node = CreatNode(value);
            new_node->next = pos->next;
            pos->next = new_node;
        }
        cur = cur->next;
    }
    
}

void LinkListErase(LinkNode **head, LinkNode *pos)             
{
    assert(head);
    if (*head == NULL)
    {
        return;
    }
    if (*head == pos)
    {
        LinkListPopFront(head);
        return;
    }
    LinkNode *pre = *head;
    LinkNode *cur = (*head)->next;
    while (cur!= NULL)
    {
        if(cur == pos)
        {
            pre->next = cur->next;
            DestroyNode(cur);
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}

//变换思维，将待删除节点的下一个节点的内容与待删除节点的进行交换，只需删除下个节点即可
void LinkListErase2(LinkNode **head, LinkNode *pos)
{
    assert(head);
    if (*head == NULL)
    {
        return;
    }
    if (*head == pos)                        //删除头节点
    {
        LinkListPopFront(head);
        return;
    }
    if (pos->next == NULL)                   //删除尾节点
    {
        LinkListPopBack(head);
        return;
    }

    LinkNode *to_delete = pos->next;         //其他节点       
    pos->data = to_delete->data;
    pos->next = to_delete->next;
    DestroyNode(to_delete);
    return;
}

void LinkListRemove(LinkNode **head, LinkDataType to_delete)      //时间复杂度为O(n)
{
    assert(head);
    if (*head == NULL)                       //空链表
    {
        return;
    }
    LinkNode *pos = LinkListFind(*head, to_delete);
    LinkListErase(head, pos);
}

void LinkNodeRemove2(LinkNode **head, LinkDataType to_delete)       //时间复杂度为O(n),较上面方法来说，代码逻辑差不多.但编译器会对循环进行优化
{
    assert(head);
    if (*head == NULL)                        //1.空链表
    {
        return;
    }
    if ((*head)->data == to_delete)           //2.要删除的元素为链表头节点
    {
        LinkNode* to_delete_node = *head;
        (*head) = to_delete_node->next;
        DestroyNode(to_delete_node);
        return;
    }
    LinkNode *cur = (*head)->next;            //3.删除的元素不是链表的头节点  
    LinkNode *pre = (*head);
    while (cur != NULL)                   
    {
        if (cur->data == to_delete)
        {
            LinkNode *to_delete_node = cur;
            pre->next = cur->next;
            DestroyNode(to_delete_node);
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    

}

void LinkNodeRemoveAll2(LinkNode **head, LinkDataType to_delete)  
{
    assert(head);
    while (1)
    {
        LinkNode *pos = LinkListFind(*head, to_delete);
        if (pos == NULL)
        {
            return;
        }
        LinkListErase(head, pos);                                  //不能复用LinkNodeRemove();因为无法确定循环何时结束
    }
}

void LinkNodeRemoveAll(LinkNode **head, LinkDataType to_delete)
{
    assert(head);
    if (*head == NULL)                                              //1.空链表
    {
        return;
    }
    while ((*head)->data == to_delete)                              //2.删除元素为头节点
    {
        LinkNode *to_delete_node = *head;
        *head = (*head)->next;
        DestroyNode(to_delete_node);
    }
    LinkNode *pre = *head;
    LinkNode *cur = (*head)->next;
    while (cur != NULL)
    {
        if (cur->data == to_delete)
        {
            LinkNode *to_delete_node = cur;
            cur = cur->next;
            if (cur == NULL)
            {
                pre->next = NULL;                                  //3.最后一个元素为待删除的元素，则此时需将pre的next指向空。
            }
            DestroyNode(to_delete_node);
            break;                                                 //4.防止cur此时已是NULL            
        }
        pre = cur;
        cur = cur->next;
    }

}
int LinkListEmpty(LinkNode *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

size_t LinkListSize(LinkNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    size_t size = 0;
    LinkNode *cur = head;
    while (cur != NULL)
    {
        ++size;
        cur = cur->next;
    }
    return size;
}
void LinkListReversePrint(LinkNode *head)
{

    if (head == NULL)                          //递归出口
    {
        return;
    }

    LinkListReversePrint(head->next);
    printf("[%c：%p] ", head->data,head);

}

//交换思想(原因是:结点的主要信息为数据，而与其分配节点的位置无关)
void LinkListInsertBefore(LinkNode **head, LinkNode *pos, LinkDataType value)
{
    assert(head);
    if (*head == NULL)
    {
        return;
    }
    LinkNode *new_node = CreatNode(pos->data);
    new_node->next = pos->next;
    pos->next = new_node;
    pos->data = value;
}

LinkNode* JosephCycle(LinkNode* head, size_t food)      //变量一般用名词表示，函数一般用动宾短语表示
{
    assert(head);               

    LinkNode *cur = head->next;                         //cur开始赋初值直接是第二个人，故number从2开始
    LinkNode *pre = head;
    size_t number = 2;              

    while (cur->next != cur)
    {
        pre = cur;
        cur = cur->next;
        ++number;
        if (number == food)
        {
            LinkNode *to_delete = cur;
            printf("Food:[%c]  ", cur->data);
            pre->next = cur->next;
            cur = cur->next;
            DestroyNode(to_delete);
            number = 1;
        }
    }
    return cur;
}









