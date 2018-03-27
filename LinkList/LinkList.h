#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char LinkDataType;

typedef struct LinkNode{
    LinkDataType data;
    struct LinkList* next;
}LinkNode;

void LinkListInit(LinkNode **head);                                                       //��ʼ������

LinkNode* LinkListPushBack(LinkNode **head, LinkDataType value);                          //β��

void LinkListPopBack(LinkNode **head);                                                    //βɾ 

void LinkListPushFront(LinkNode **head, LinkDataType value);                              //ͷ��

void LinkListPopFront(LinkNode **head);                                                   //ͷɾ

void LinkListDisplay(LinkNode *head,char *msg);                                           //��ʾ����
 
LinkNode* LinkListFind(LinkNode *head, LinkDataType to_find);                             //����ĳԪ���Ƿ����

void LinkListInsert(LinkNode **head, LinkNode *pos, LinkDataType value);                  //��ĳλ��ǰ����Ԫ��

void LinkListInsertAfter(LinkNode **head, LinkNode *pos, LinkDataType value);             //��ĳλ��֮�����Ԫ��

void LinkListErase(LinkNode **head, LinkNode *pos);                                       //ɾ��ָ��λ��Ԫ��,ʹ�ñ�������

void LinkListErase2(LinkNode **head, LinkNode *pos);                                      //   ����          ʹ�÷Ǳ�������

void LinkListRemove(LinkNode **head, LinkDataType to_delete);                             //ɾ��ָ��ֵ��Ԫ��(�״γ���)

void LinkListRemove(LinkNode **head, LinkDataType to_delete);                             //ָ��ֵ������Ԫ�ض�ɾ��

int LinkListEmpty(LinkNode *head);                                                        //�ж������Ƿ�Ϊ��

size_t LinkListSize(LinkNode *head);                                                      //������Ԫ�صĸ���

void LinkListReversePrint(LinkNode *head);                                                //�����ӡ����

void LinkListInsertBefore(LinkNode **head, LinkNode *pos, LinkDataType value);             //��ĳ�ڵ�֮ǰ������Ԫ��(�������������)

LinkNode* JosephCycle(LinkNode* head, size_t food);                                        //Լɪ��
