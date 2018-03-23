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
    KeyType key;                        //关键码
    ValType value;
    Stat stat;                          //标记哈希元素是否能有效
}HashElement;



typedef struct HashTable {
    HashElement data[HashMaxSize];

    size_t size;
    HashFunc hash_func;
}HashTable;

void HashTableInit(HashTable* ht,HashFunc hash_func);                //初始化

int HashTableInsert(HashTable *ht, KeyType key, ValType value);      //插入元素

int HashTableFind(HashTable *ht,KeyType key, ValType* value);        //查找key是否已存在，若存在，将其value值赋给参数value

void HashTableRemove(HashTable *ht, KeyType key);                   //删除某元素

int HashTableEmpty(HashTable *ht);                                  //判断哈希表是否为空

size_t HashTableSize(HashTable *ht);                                //得出哈希表元素个数

void HashTableDestroy(HashTable *ht);                               //销毁哈希表

