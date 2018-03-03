#include"HashTable.h"

size_t HashFunc1(KeyType key)
{
    return key % HashMaxSize;
}

void HashInit(HashTable* ht, HashFunc hash_func)
{
    if (ht == NULL)
    {
        return;
    }
    ht->size = 0;
    ht->hash_func = hash_func;
    int i = 0;
    for (i = 0; i < HashMaxSize; i++)
    {
        ht->data->stat = Empty;
        ht->data->key = 0;
        ht->data->value = 0;
    }
}

int HashInsertNoRepeatKey(HashTable *ht, KeyType key, ValType value)

{
    if (ht == NULL)
    {
        return 0;
    }

    //1.当哈希元素个数size等于负载因子*哈希表容量时，则表示哈希表已满

    if (ht->size >= HashMaxSize * 0.8)                  //假设其负载因子为0.8
    {
        return 0;
    }
    size_t offset = key;

    if (offset > HashMaxSize)                           //当offset大于HashMaxSize时，进行哈希转换
    {
        offset = ht->hash_func(key);
    }
    /*2.判断key要插入的位置的stat是有效，
    若为空或无效，则将key插入该位置，并修改其对应的statu和size；
    否则，向后依此寻找未使用的位置，进行插入
    */
    while (1)
    {
        if (ht->data[offset].stat == Valid && ht->data[offset].key == key)
        {
            return 0;
        }
        if (ht->data[offset].stat != Valid)
        {
            ht->data[offset].key = key;
;
            ht->data[offset].stat = Valid;
            ht->data[offset].value = value;
            ht->size++;
            return 1;
        }
        /*offset位置值为有效值*/
        if (ht->data[offset].key == key)
        {
            return 0;
        }
        else
        {
            /*1.判断该位置的值是否等于要插元素；
            若等于，则退出;
            否则,offset++,查找之后的非有效位进行插入
            */
            offset++;
            if (offset >= HashMaxSize)
            {
                offset -= HashMaxSize;
            }
        }
    }
    return 0;
}

int HashInsert(HashTable *ht, KeyType key, ValType value)
{
    if (ht == NULL)
    {
        return 0;
    }

    //1.当哈希元素个数size等于负载因子*哈希表容量时，则表示哈希表已满

    if (ht->size >= HashMaxSize * 0.8)                  //假设其负载因子为0.8
    {
        return 0;
    }
    size_t offset = key;

    if (offset > HashMaxSize)                           //当offset大于HashMaxSize时，进行哈希转换
    {
        offset = ht->hash_func(key);
    }
    /*2.判断key要插入的位置的stat是有效，
           若为空或无效，则将key插入该位置，并修改其对应的statu和size；
           否则，向后依此寻找未使用的位置，进行插入
    */
    while (1)
    {
        if (ht->data[offset].stat != Valid)
        {
            ht->data[offset].key = key;
            ht->data[offset].stat = Valid;
            ht->data[offset].value = value;
            ht->size++;
            return 1;
        }
        /*offset位置值为有效值*/
        if (ht->data[offset].key == key)
        {
            return 0;
        }
        else
        {
            /*1.判断该位置的值是否等于要插元素；
                若等于，则退出;
                否则,offset++,查找之后的非有效位进行插入
            */
            offset++;
            if (offset >= HashMaxSize)
            {
                offset -= HashMaxSize;
            }
        }
    }
    return 0;
}
/*1.先计算key所在的位置
  2.判断该位置的状态和关键值
    a)若该位置状态不为empty，比较key值
        如若该位置key值与所找元素key值相等，则将找到的值对应的value值赋给value
        若不相等，在进行比较，直至遇到状态为空，则表示该元素不存在
    b)否则，表示该元素一定不存在于哈希表中

*/
int HashTableFind(HashTable *ht, KeyType key, ValType* value)
{
    if (ht == NULL)
    {
        return;
    }
    size_t offset = ht->hash_func(key);

    while (ht->data[offset].stat != Empty)
    {
        if (ht->data[offset].key == key)
        {
            *value = ht->data[offset].value;
            return 1;
        }
        else
        {
            offset++;
            if (offset >= HashMaxSize)
            {
                offset -= HashMaxSize;
            }
        }
    }
    return 0;

}
/*  1.根据哈希函数，找到key所对应的位置
    2.判断该位置的状态是否为有效的Valid
        a)若有效，判断key值是否相等
            若相等，删除该元素
            否则，++offset，进行下个元素判断，直至状态为空，则说明删除元素不存在，
        b)若为空，说明元素不存在
*/
void HashTableRemove(HashTable *ht, KeyType key)
{
    if (ht == NULL)
    {
        return;
    }
    if (ht->size == 0)
    {
        return;
    }
    size_t offset = ht->hash_func(key);

    while (ht->data[offset].stat != Empty)
    {
        if (ht->data[offset].stat == Valid && ht->data[offset].key == key)
        {
            ht->data[offset].stat = Invalid;
            ht->size--;
            return;
        }
        else
        {
            offset++;
            if (offset >= HashMaxSize)
            {
                offset -= HashMaxSize;
            }
        }
    }
    return;
}

int HashTableEmpty(HashTable *ht)
{
    if (ht == NULL)
    {
        return 0;
    }
    return ht->size == 0 ? 1 : 0;
}

size_t HashTableSize(HashTable *ht)
{
    if (ht == NULL)
    {
        return 0;
    }
    return ht->size;
}

void HashTableDestroy(HashTable *ht)
{
    if (ht == NULL)
    {
        return;
    }
    int i = 0;
    ht->hash_func = NULL;
    ht->size = 0;
    for (i = 0; i < HashMaxSize; i++)
    {
        ht->data[i].stat = Empty;
    }
}

/*************************************************************************************************
                                     以下为测试代码
*************************************************************************************************/

#define TEST_HEADER printf("==================================%s===============================\n",__FUNCTION__)

void HashPrint(HashTable *ht, const char *msg)
{
    if (ht == NULL)
    {
        printf("非法输入");
        return;
    }
    int i = 0;
    printf("该哈希表元素个数为：%lu\n", ht->size);
    for (i = 0; i < HashMaxSize; i++)
    {
        if (ht->data[i].stat == Valid)
        {
            printf("[%lu]:[key=%lu,value=%lu]\t", i, ht->data[i].key, ht->data[i].value);
            //打印格式：[下标][key=...,value=...]
        }
    }
    printf("\n");
}

void TestHashInit()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);
    printf("size expect is 0,actual is %lu\n", ht.size);
    printf("stat expect is 0,actual is %d\n", ht.data->stat);
}

void TestHashInsert()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);

    
    HashInsertNoRepeatKey(&ht, 1, 100);
    HashInsertNoRepeatKey(&ht, 2, 200);
    HashInsertNoRepeatKey(&ht, 1001, 300);

    HashTableRemove(&ht, 2);
    HashInsertNoRepeatKey(&ht, 1001, 400);
    HashInsertNoRepeatKey(&ht, 1002, 500);
    HashPrint(&ht, "插入6个元素");
}


void TestHashFind()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);

    ValType value = 0;
    int ret = HashTableFind(&ht, 3, &value);
    printf("ret expect 0,actual %d\n", ret);

    HashInsert(&ht, 1, 100);
    HashInsert(&ht, 2, 200);
    HashInsert(&ht, 1001, 300);
    HashInsert(&ht, 1002, 400);
    HashInsert(&ht, 5, 500);
    HashInsert(&ht, 1002, 600);
    HashPrint(&ht, "插入6个元素");

    ret = HashTableFind(&ht, 1, &value);
    printf("ret expect 1,actual %d\n", ret);
    printf("value expect 100,actual %d\n", value);

    ret = HashTableFind(&ht, 1002, &value);
    printf("ret expect 1,actual %d\n", ret);
    printf("value expect 400,actual %d\n", value);

    ret = HashTableFind(&ht, 3, &value);
    printf("ret expect 0,actual %d\n", ret);
}

void TestHashRemove()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);

    HashInsert(&ht, 1, 100);
    HashInsert(&ht, 2, 200);
    HashInsert(&ht, 1001, 300);
    HashInsert(&ht, 1002, 400);
    HashInsert(&ht, 5, 500);
    HashInsert(&ht, 1002, 600);
    HashPrint(&ht, "插入6个元素");

    HashTableRemove(&ht, 1001);
    HashTableRemove(&ht, 5);
    HashPrint(&ht, "删除2个元素");

    HashTableRemove(&ht, 4);
    HashPrint(&ht, "删除不存在的元素");

}

void TestHashSize()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);

    HashInsert(&ht, 1, 100);
    HashInsert(&ht, 2, 200);
    HashInsert(&ht, 1001, 300);
    HashInsert(&ht, 1002, 400);
    HashInsert(&ht, 5, 500);
    HashInsert(&ht, 1002, 600);
    HashPrint(&ht, "插入6个元素");

    int ret = HashTableSize(&ht);
    printf("ret expect 5,actual %lu\n", ret);
}

void TestHashEmpty()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);

    int ret = HashTableEmpty(&ht);
    printf("ret expect 1,actual %lu\n", ret);

    HashInsert(&ht, 1, 100);
    HashInsert(&ht, 2, 200);
    HashInsert(&ht, 1001, 300);
    HashInsert(&ht, 1002, 400);
    HashInsert(&ht, 5, 500);
    HashInsert(&ht, 1002, 600);
    HashPrint(&ht, "插入6个元素");

    ret = HashTableEmpty(&ht);
    printf("ret expect 0,actual %lu\n", ret);
}

void TestHashDestroy()
{
    TEST_HEADER;
    HashTable ht;
    HashInit(&ht, HashFunc1);

    HashInsert(&ht, 1, 100);
    HashInsert(&ht, 2, 200);
    HashInsert(&ht, 1001, 300);
    HashInsert(&ht, 1002, 400);
    HashInsert(&ht, 5, 500);
    HashInsert(&ht, 1002, 600);
    HashPrint(&ht, "插入6个元素");

    HashTableDestroy(&ht);
    printf("size expect 0,actual %lu\n hash_func expect NULL,actual %p\n", ht.size, ht.hash_func);
    /* int i = 0;
    for(i=0;i<HashMaxSize;i++)
    {
        printf("status expect 0,actual %d",ht.data->stat);
    }*/

}
int main()
{
    TestHashInit();
    TestHashInsert();
    TestHashFind();
    TestHashRemove();
    TestHashSize();
    TestHashEmpty();
    TestHashDestroy();

    system("pause");
    return 0;
}