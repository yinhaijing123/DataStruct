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

void SeqListInit(SeqList *seq);                              //初始化

void SeqListPushBack(SeqList *seq, SeqDataType value);       //尾插

void SeqListPopBack(SeqList *seq);                           //尾删

void SeqListPushFront(SeqList *seq, SeqDataType value);      //头插

void SeqListPopFront(SeqList *seq);                          //头删

//获得某下标的值，若存在，返回该下标对应数据，若不存在，则：返回一错误值
SeqDataType SeqListGet(SeqList *seq, size_t pos, SeqDataType default_value);   

void SeqListSet(SeqList *seq,size_t i,SeqDataType new_value);//重新设置某位置的值

void SeqListDisplay(SeqList *seq,char *tip);                 //显示顺序表

size_t SeqListFind(SeqList *seq, SeqDataType to_find_value); //查找某指定值并返回其下标，若没找到，则返回一个特大数(size_t)-1

void SeqListInsert(SeqList *seq, size_t pos, SeqDataType value);  //指定位置插入

void SeqListErase(SeqList *seq, size_t pos);                      //删除指定位置元素

void SeqListRemove(SeqList *seq, SeqDataType to_remove_value);    //删除指定值，如果该值时重复元素，则只需删除第一个出现的某值

void SeqListRemove(SeqList *seq, SeqDataType to_remove_value);    //删除数组中所有的指定的值

int SeqListEmpty(SeqList *seq);                                   //判断顺序表是否为空，若是，返回1；否则，返回0

void SeqListBubbleSort(SeqList *seq);                             //冒泡排序顺序表

void SeqListBubbleSortEx(SeqList* seq, int(*cmp)(SeqListype, SeqListType));  //通过传参确定求升序(more)，还是降序(less)
