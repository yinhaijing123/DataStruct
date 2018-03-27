#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char LinkDataType;

typedef struct LinkNode{
    LinkDataType data;
    struct LinkList* next;
}LinkNode;

void LinkListInit(LinkNode **head);                                                       //初始化链表

LinkNode* LinkListPushBack(LinkNode **head, LinkDataType value);                          //尾插

void LinkListPopBack(LinkNode **head);                                                    //尾删 

void LinkListPushFront(LinkNode **head, LinkDataType value);                              //头插

void LinkListPopFront(LinkNode **head);                                                   //头删

void LinkListDisplay(LinkNode *head,char *msg);                                           //显示链表
 
LinkNode* LinkListFind(LinkNode *head, LinkDataType to_find);                             //查找某元素是否存在

void LinkListInsert(LinkNode **head, LinkNode *pos, LinkDataType value);                  //在某位置前插入元素

void LinkListInsertAfter(LinkNode **head, LinkNode *pos, LinkDataType value);             //在某位置之后插入元素

void LinkListErase(LinkNode **head, LinkNode *pos);                                       //删除指定位置元素,使用遍历方法

void LinkListErase2(LinkNode **head, LinkNode *pos);                                      //   ……          使用非遍历方法

void LinkListRemove(LinkNode **head, LinkDataType to_delete);                             //删除指定值的元素(首次出现)

void LinkListRemove(LinkNode **head, LinkDataType to_delete);                             //指定值的所有元素都删除

int LinkListEmpty(LinkNode *head);                                                        //判断链表是否为空

size_t LinkListSize(LinkNode *head);                                                      //求链表元素的个数

void LinkListReversePrint(LinkNode *head);                                                //逆序打印链表

void LinkListInsertBefore(LinkNode **head, LinkNode *pos, LinkDataType value);             //在某节点之前插入新元素(不允许遍历链表)

LinkNode* JosephCycle(LinkNode* head, size_t food);                                        //约瑟夫环
