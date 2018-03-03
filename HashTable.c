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

    //1.����ϣԪ�ظ���size���ڸ�������*��ϣ������ʱ�����ʾ��ϣ������

    if (ht->size >= HashMaxSize * 0.8)                  //�����为������Ϊ0.8
    {
        return 0;
    }
    size_t offset = key;

    if (offset > HashMaxSize)                           //��offset����HashMaxSizeʱ�����й�ϣת��
    {
        offset = ht->hash_func(key);
    }
    /*2.�ж�keyҪ�����λ�õ�stat����Ч��
    ��Ϊ�ջ���Ч����key�����λ�ã����޸����Ӧ��statu��size��
    �����������Ѱ��δʹ�õ�λ�ã����в���
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
        /*offsetλ��ֵΪ��Чֵ*/
        if (ht->data[offset].key == key)
        {
            return 0;
        }
        else
        {
            /*1.�жϸ�λ�õ�ֵ�Ƿ����Ҫ��Ԫ�أ�
            �����ڣ����˳�;
            ����,offset++,����֮��ķ���Чλ���в���
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

    //1.����ϣԪ�ظ���size���ڸ�������*��ϣ������ʱ�����ʾ��ϣ������

    if (ht->size >= HashMaxSize * 0.8)                  //�����为������Ϊ0.8
    {
        return 0;
    }
    size_t offset = key;

    if (offset > HashMaxSize)                           //��offset����HashMaxSizeʱ�����й�ϣת��
    {
        offset = ht->hash_func(key);
    }
    /*2.�ж�keyҪ�����λ�õ�stat����Ч��
           ��Ϊ�ջ���Ч����key�����λ�ã����޸����Ӧ��statu��size��
           �����������Ѱ��δʹ�õ�λ�ã����в���
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
        /*offsetλ��ֵΪ��Чֵ*/
        if (ht->data[offset].key == key)
        {
            return 0;
        }
        else
        {
            /*1.�жϸ�λ�õ�ֵ�Ƿ����Ҫ��Ԫ�أ�
                �����ڣ����˳�;
                ����,offset++,����֮��ķ���Чλ���в���
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
/*1.�ȼ���key���ڵ�λ��
  2.�жϸ�λ�õ�״̬�͹ؼ�ֵ
    a)����λ��״̬��Ϊempty���Ƚ�keyֵ
        ������λ��keyֵ������Ԫ��keyֵ��ȣ����ҵ���ֵ��Ӧ��valueֵ����value
        ������ȣ��ڽ��бȽϣ�ֱ������״̬Ϊ�գ����ʾ��Ԫ�ز�����
    b)���򣬱�ʾ��Ԫ��һ���������ڹ�ϣ����

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
/*  1.���ݹ�ϣ�������ҵ�key����Ӧ��λ��
    2.�жϸ�λ�õ�״̬�Ƿ�Ϊ��Ч��Valid
        a)����Ч���ж�keyֵ�Ƿ����
            ����ȣ�ɾ����Ԫ��
            ����++offset�������¸�Ԫ���жϣ�ֱ��״̬Ϊ�գ���˵��ɾ��Ԫ�ز����ڣ�
        b)��Ϊ�գ�˵��Ԫ�ز�����
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
                                     ����Ϊ���Դ���
*************************************************************************************************/

#define TEST_HEADER printf("==================================%s===============================\n",__FUNCTION__)

void HashPrint(HashTable *ht, const char *msg)
{
    if (ht == NULL)
    {
        printf("�Ƿ�����");
        return;
    }
    int i = 0;
    printf("�ù�ϣ��Ԫ�ظ���Ϊ��%lu\n", ht->size);
    for (i = 0; i < HashMaxSize; i++)
    {
        if (ht->data[i].stat == Valid)
        {
            printf("[%lu]:[key=%lu,value=%lu]\t", i, ht->data[i].key, ht->data[i].value);
            //��ӡ��ʽ��[�±�][key=...,value=...]
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
    HashPrint(&ht, "����6��Ԫ��");
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
    HashPrint(&ht, "����6��Ԫ��");

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
    HashPrint(&ht, "����6��Ԫ��");

    HashTableRemove(&ht, 1001);
    HashTableRemove(&ht, 5);
    HashPrint(&ht, "ɾ��2��Ԫ��");

    HashTableRemove(&ht, 4);
    HashPrint(&ht, "ɾ�������ڵ�Ԫ��");

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
    HashPrint(&ht, "����6��Ԫ��");

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
    HashPrint(&ht, "����6��Ԫ��");

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
    HashPrint(&ht, "����6��Ԫ��");

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