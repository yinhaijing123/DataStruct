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
    if (*head == NULL)                                                 //������
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
        printf("������\n");
        printf("\n");
        return;
    }
    LinkNode *cur = head;
    while (cur != NULL)
    {
        printf("[%c��%p]->", cur->data,cur);
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
    if (*head == NULL)                       //������
    {
        return;
    }
    if ((*head)->next == NULL)               //һ���ڵ�
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
    if (*head == pos)                                          //����λ��Ϊͷ�ڵ㴦
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

//�任˼ά������ɾ���ڵ����һ���ڵ���������ɾ���ڵ�Ľ��н�����ֻ��ɾ���¸��ڵ㼴��
void LinkListErase2(LinkNode **head, LinkNode *pos)
{
    assert(head);
    if (*head == NULL)
    {
        return;
    }
    if (*head == pos)                        //ɾ��ͷ�ڵ�
    {
        LinkListPopFront(head);
        return;
    }
    if (pos->next == NULL)                   //ɾ��β�ڵ�
    {
        LinkListPopBack(head);
        return;
    }

    LinkNode *to_delete = pos->next;         //�����ڵ�       
    pos->data = to_delete->data;
    pos->next = to_delete->next;
    DestroyNode(to_delete);
    return;
}

void LinkListRemove(LinkNode **head, LinkDataType to_delete)      //ʱ�临�Ӷ�ΪO(n)
{
    assert(head);
    if (*head == NULL)                       //������
    {
        return;
    }
    LinkNode *pos = LinkListFind(*head, to_delete);
    LinkListErase(head, pos);
}

void LinkNodeRemove2(LinkNode **head, LinkDataType to_delete)       //ʱ�临�Ӷ�ΪO(n),�����淽����˵�������߼����.�����������ѭ�������Ż�
{
    assert(head);
    if (*head == NULL)                        //1.������
    {
        return;
    }
    if ((*head)->data == to_delete)           //2.Ҫɾ����Ԫ��Ϊ����ͷ�ڵ�
    {
        LinkNode* to_delete_node = *head;
        (*head) = to_delete_node->next;
        DestroyNode(to_delete_node);
        return;
    }
    LinkNode *cur = (*head)->next;            //3.ɾ����Ԫ�ز��������ͷ�ڵ�  
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
        LinkListErase(head, pos);                                  //���ܸ���LinkNodeRemove();��Ϊ�޷�ȷ��ѭ����ʱ����
    }
}

void LinkNodeRemoveAll(LinkNode **head, LinkDataType to_delete)
{
    assert(head);
    if (*head == NULL)                                              //1.������
    {
        return;
    }
    while ((*head)->data == to_delete)                              //2.ɾ��Ԫ��Ϊͷ�ڵ�
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
                pre->next = NULL;                                  //3.���һ��Ԫ��Ϊ��ɾ����Ԫ�أ����ʱ�轫pre��nextָ��ա�
            }
            DestroyNode(to_delete_node);
            break;                                                 //4.��ֹcur��ʱ����NULL            
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

    if (head == NULL)                          //�ݹ����
    {
        return;
    }

    LinkListReversePrint(head->next);
    printf("[%c��%p] ", head->data,head);

}

//����˼��(ԭ����:������Ҫ��ϢΪ���ݣ����������ڵ��λ���޹�)
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

LinkNode* JosephCycle(LinkNode* head, size_t food)      //����һ�������ʱ�ʾ������һ���ö��������ʾ
{
    assert(head);               

    LinkNode *cur = head->next;                         //cur��ʼ����ֱֵ���ǵڶ����ˣ���number��2��ʼ
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









