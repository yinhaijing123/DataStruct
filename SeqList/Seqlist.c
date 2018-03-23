#include"SeqList.h"

void SeqListInit(SeqList *seq)
{
	assert(seq);
	seq->size = 0;
}

void SeqListPushBack(SeqList *seq, SeqDataType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxSize)
	{
		return;
	}

	seq->size++;
	seq->data[seq->size - 1] = value;
}

void SeqListPopBack(SeqList *seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		return;
	}
	seq->size--;
}

void SeqListPushFront(SeqList *seq,SeqDataType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxSize)
	{
		return;
	}
	int i = 0;
	seq->size++;
	for (i = seq->size - 1; i > 0; i--)
	{
		seq->data[i] = seq->data[i - 1];
	}
	seq->data[0] = value;
}

void SeqListPopFront(SeqList *seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		return;
	}
	size_t i = 0;
	for (i = 0; i < seq->size-1; i++)
	{
		seq->data[i] = seq->data[i + 1];
	}
	seq->size--;
}

void SeqListDisplay(SeqList *seq,char *tip)
{
	assert(seq);
	size_t i = 0;
	printf("%s\n", tip);
	for (i = 0; i < (seq->size); i++)
	{
		printf("%c\t", seq->data[i]);
	}
	printf("\n");
}

SeqDataType SeqListGet(SeqList *seq, size_t pos, SeqDataType default_value)
{
	assert(seq);
	if ((seq->size > pos) && (pos >= 0))
	{
		return(seq->data[pos]);
	}
	return (size_t)-1;
}

void SeqListSet(SeqList *seq, size_t i, SeqDataType new_value)
{
    assert(seq);
    if (i > (seq->size - 1))
    {
        return;
    }
    seq->data[i] = new_value;
}

size_t SeqListFind(SeqList *seq, SeqDataType to_find_value)
{
    assert(seq);
    int i = 0;
    for (i = 0; i < seq->size; i++)
    {
        if (seq->data[i] == to_find_value)
        {
            return i;
        }
    }
    return (size_t) -1;
}

void SeqListInsert(SeqList *seq, size_t pos, SeqDataType value)
{
    assert(seq);
    if ((pos > (seq->size))||(seq->size >= SeqListMaxSize))
    {
        return;
    }
    int i = 0;
    ++seq->size;
    for (i = seq->size - 1; i > pos; i--)
    {
        seq->data[i] = seq->data[i - 1];
    }
    seq->data[pos] = value;
}

void SeqListErase(SeqList *seq, size_t pos)
{
    assert(seq);
    if ((pos > seq->size - 1) || seq->size == 0)
    {
        return;
    }
    int i = pos;
    for (i = pos; i < seq->size - 1; i++)
    {
        seq->data[i] = seq->data[i + 1];
    }
    seq->size--;
}

void SeqListRemove(SeqList *seq, SeqDataType to_remove)
{
    assert(seq);
    if (seq->size == 0)
    {
        return;
    }
    size_t i = SeqListFind(seq, to_remove);
    if (i < seq->size - 1)
    {
        SeqListErase(seq, i);
    }
}

void SeqListRemoveAll(SeqList *seq, SeqDataType to_remove)
{
    assert(seq);
    if (seq->size == 0)
    {
        return;
    }
    size_t i = SeqListFind(seq, to_remove);
    while (i != (size_t)-1)
    {
        SeqListErase(seq, i);
        i = SeqListFind(seq, to_remove);
    }
}

int SeqListEmpty(SeqList *seq)
{
    assert(seq);
    if (seq->size == 0)
    {
        return 1;
    }
    return 0;
}

void Swap(SeqDataType *a, SeqDataType *b)
{
    SeqDataType tmp = *a;
    *a = *b;
    *b = tmp;
}

void SeqListBubbleSort(SeqList* seq)
{
    assert(seq);
    if ((seq->size == 0) || (seq->size == 1))
    {
        return;
    }
    int i = 0;
    for (i = 0; i < seq->size - 1; i++)
    {
        int j = 0;
        for (j = 0; j < seq->size - 1 - i; j++)
        {
            if (seq->data[j] > seq->data[j + 1])                 //实现降序
            {
                Swap(&seq->data[j], &seq->data[j + 1]);
            }
        }
    }
}
int Less(SeqDataType a, SeqDataType b)
{
    return a < b;
}

int More(SeqDataType a, SeqDataType b)
{
    return a > b;
}

void SeqListBubbleSortEx(SeqList* seq, int(*cmp)(SeqDataType, SeqDataType))  //通过传参确定求升序，还是降序
{
    assert(seq);
    if ((seq->size == 0) || (seq->size == 1))
    {
        return;
    }
    int i = 0;
    for (i = 0; i < seq->size - 1; i++)
    {
        int j = 0;
        for (j = 0; j < seq->size - 1 - i; j++)
        {
            if (cmp(seq->data[j],seq->data[j + 1]))                 
            {
                Swap(&seq->data[j], &seq->data[j + 1]);
            }
        }
    }
}
/********************************************************************
                      以下为测试代码
********************************************************************/

#define TestPrint() printf("----------------------%s--------------------\n",__FUNCTION__)

void TestPush()
{
	TestPrint();

	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 'a');
	SeqListPushBack(&seq, 'b');
	SeqListDisplay(&seq,"后插两个数据");

	SeqListPushFront(&seq, 'c');
	SeqListPushFront(&seq, 'd');
	SeqListDisplay(&seq,"前插两个数据");
}

void TestPop()
{
	TestPrint();

	SeqList seq;
	SeqListInit(&seq);

	SeqListPushBack(&seq, 'a');
	SeqListPushBack(&seq, 'b');
	SeqListPushBack(&seq, 'c');
	SeqListPushBack(&seq, 'd');
	SeqListPushBack(&seq, 'e');
	SeqListDisplay(&seq, "插入五个数据");

	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListDisplay(&seq, "后删两个数据");

	SeqListPopFront(&seq);
	SeqListPopFront(&seq);
	SeqListDisplay(&seq, "前删两个数据");
}

void TestGet()
{
	TestPrint();

	SeqList seq;
	SeqListInit(&seq);

	SeqListPushBack(&seq, 'a');
	SeqListPushBack(&seq, 'b');
	SeqListPushBack(&seq, 'c');
	SeqListPushBack(&seq, 'd');
	SeqListPushBack(&seq, 'e');
	SeqListDisplay(&seq, "插入五个数据");

	printf("%c\n",SeqListGet(&seq,3,'#'));

}

void TestSet()
{
    TestPrint();

    SeqList seq;
    SeqListInit(&seq);

    SeqListPushBack(&seq, 'a');
    SeqListPushBack(&seq, 'b');
    SeqListPushBack(&seq, 'c');
    SeqListPushBack(&seq, 'd');
    SeqListPushBack(&seq, 'e');
    SeqListDisplay(&seq, "插入五个数据");

    SeqListSet(&seq, 3, 'f');
    SeqListDisplay(&seq, "修改第4个元素为f");
}

void TestFind()
{
    TestPrint();

    SeqList seq;
    SeqListInit(&seq);

    SeqListPushBack(&seq, 'a');
    SeqListPushBack(&seq, 'b');
    SeqListPushBack(&seq, 'c');
    SeqListPushBack(&seq, 'd');
    SeqListPushBack(&seq, 'e');
    SeqListDisplay(&seq, "插入五个数据");

    size_t ret = SeqListFind(&seq, 'c');
    printf("expect ret is 2,actual %u\n", ret);
    ret = SeqListFind(&seq, 'f');
    printf("expect ret is 429…,actual %u\n", ret);
}

void TestInsert()
{
    TestPrint();

    SeqList seq;
    SeqListInit(&seq);

    SeqListPushBack(&seq, 'a');
    SeqListPushBack(&seq, 'b');
    SeqListPushBack(&seq, 'c');
    SeqListPushBack(&seq, 'd');
    SeqListPushBack(&seq, 'e');
    SeqListDisplay(&seq, "插入五个数据");

    SeqListInsert(&seq, 1, 'g');
    SeqListDisplay(&seq, "在下标为1处插入g");
    SeqListInsert(&seq,10, '#');
    SeqListDisplay(&seq, "在下标为10处插入#");
}

void TestErase()
{
    TestPrint();

    SeqList seq;
    SeqListInit(&seq);

    SeqListPushBack(&seq, 'a');
    SeqListPushBack(&seq, 'b');
    SeqListPushBack(&seq, 'c');
    SeqListPushBack(&seq, 'd');
    SeqListPushBack(&seq, 'e');
    SeqListDisplay(&seq, "插入五个数据");

    SeqListErase(&seq, 2);
    SeqListDisplay(&seq, "删除下标为2的数据");

    SeqListErase(&seq, 6);
    SeqListDisplay(&seq, "删除下标为6的数据");

}

void TestRemove()
{
    TestPrint();

    SeqList seq;
    SeqListInit(&seq);

    SeqListPushBack(&seq, 'a');
    SeqListPushBack(&seq, 'b');
    SeqListPushBack(&seq, 'a');
    SeqListPushBack(&seq, 'd');
    SeqListPushBack(&seq, 'd');
    SeqListDisplay(&seq, "插入五个数据");

    SeqListRemove(&seq, 'a');
    SeqListDisplay(&seq, "删除第一次出现的a");
    
    SeqListRemove(&seq, 'f');
    SeqListDisplay(&seq, "删除不存在的f");

    SeqListRemoveAll(&seq, 'd');
    SeqListDisplay(&seq, "删除所有d");

    SeqListRemove(&seq, 'g');
    SeqListDisplay(&seq, "删除不存在的g");

}

void TestSort()
{
    TestPrint();

    SeqList seq;
    SeqListInit(&seq);

    SeqListPushBack(&seq, 'f');
    SeqListPushBack(&seq, 'b');
    SeqListPushBack(&seq, 'g');
    SeqListPushBack(&seq, 'd');
    SeqListPushBack(&seq, 'c');
    SeqListDisplay(&seq, "插入五个数据");

    SeqListBubbleSort(&seq);
    SeqListDisplay(&seq,"排序后的顺序表");

    SeqListBubbleSortEx(&seq, Less);
    SeqListDisplay(&seq, "降序排序后的顺序表");

    SeqListBubbleSortEx(&seq, More);
    SeqListDisplay(&seq, "升序排序后的顺序表");
}

int main()
{
    TestPush();
    TestPop();
    TestGet();
    TestSet();
    TestFind();
    TestInsert();
    TestErase();
    TestRemove();
    TestSort();

    system("pause");
    return 0;
}