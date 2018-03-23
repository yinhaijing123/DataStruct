#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#define SeqListMaxSize 1000
typedef char SeqDataType;

typedef struct SeqList {
	SeqDataType data[SeqListMaxSize];
	size_t size;
}SeqList;

void SeqListInit(SeqList *seq);                              //��ʼ��

void SeqListPushBack(SeqList *seq, SeqDataType value);       //β��

void SeqListPopBack(SeqList *seq);                           //βɾ

void SeqListPushFront(SeqList *seq, SeqDataType value);      //ͷ��

void SeqListPopFront(SeqList *seq);                          //ͷɾ

//���ĳ�±��ֵ�������ڣ����ظ��±��Ӧ���ݣ��������ڣ��򣺷���һ����ֵ
SeqDataType SeqListGet(SeqList *seq, size_t pos, SeqDataType default_value);   

void SeqListSet(SeqList *seq,size_t i,SeqDataType new_value);//��������ĳλ�õ�ֵ

void SeqListDisplay(SeqList *seq,char *tip);                 //��ʾ˳���

size_t SeqListFind(SeqList *seq, SeqDataType to_find_value); //����ĳָ��ֵ���������±꣬��û�ҵ����򷵻�һ���ش���(size_t)-1

void SeqListInsert(SeqList *seq, size_t pos, SeqDataType value);  //ָ��λ�ò���

void SeqListErase(SeqList *seq, size_t pos);                      //ɾ��ָ��λ��Ԫ��

void SeqListRemove(SeqList *seq, SeqDataType to_remove_value);    //ɾ��ָ��ֵ�������ֵʱ�ظ�Ԫ�أ���ֻ��ɾ����һ�����ֵ�ĳֵ

void SeqListRemove(SeqList *seq, SeqDataType to_remove_value);    //ɾ�����������е�ָ����ֵ

int SeqListEmpty(SeqList *seq);                                   //�ж�˳����Ƿ�Ϊ�գ����ǣ�����1�����򣬷���0

void SeqListBubbleSort(SeqList *seq);                             //ð������˳���

void SeqListBubbleSortEx(SeqList* seq, int(*cmp)(SeqListype, SeqListType));  //ͨ������ȷ��������(more)�����ǽ���(less)
