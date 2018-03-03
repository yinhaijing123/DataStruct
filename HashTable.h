#pragma once

#include<stdio.h>
#include<stdlib.h>

#define HashMaxSize 1000

typedef int KeyType;

typedef int ValType;

typedef size_t (*HashFunc)(KeyType key);

typedef enum Stat {
    Empty,
    Valid,
    Invalid
}Stat;

typedef struct HashElement {
    KeyType key;                        //�ؼ���
    ValType value;
    Stat stat;                          //��ǹ�ϣԪ���Ƿ�����Ч
}HashElement;



typedef struct HashTable {
    HashElement data[HashMaxSize];

    size_t size;
    HashFunc hash_func;
}HashTable;

void HashTableInit(HashTable* ht,HashFunc hash_func);                //��ʼ��

int HashTableInsert(HashTable *ht, KeyType key, ValType value);      //����Ԫ��

int HashTableFind(HashTable *ht,KeyType key, ValType* value);        //����key�Ƿ��Ѵ��ڣ������ڣ�����valueֵ��������value

void HashTableRemove(HashTable *ht, KeyType key);                   //ɾ��ĳԪ��

int HashTableEmpty(HashTable *ht);                                  //�жϹ�ϣ���Ƿ�Ϊ��

size_t HashTableSize(HashTable *ht);                                //�ó���ϣ��Ԫ�ظ���

void HashTableDestroy(HashTable *ht);                               //���ٹ�ϣ��

