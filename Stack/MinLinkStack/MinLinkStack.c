#include"MinLinkStack.h" 
void MinStackInit(MinStack *MinStack)
{
    assert(MinStack);
    MinStack->head = NULL;
}

MinStackNode *CreatNode(DataType elem)
{
    MinStackNode *new_node=(MinStackNode *)malloc(sizeof(MinStackNode));
    if(new_node==NULL)
    {
        perror("error");
        return NULL;
    }
    new_node->data=elem;
    new_node->next=NULL;
    return new_node;
}

//实现每次入栈两个元素，保证栈顶为栈中最小值
void MinStackPush(MinStack *MinStack,DataType elem)   
{
    assert(MinStack);
    static DataType min=0;
    if(MinStack->head==NULL)
    {
        min=elem;
        MinStackNode *new_node=CreatNode(elem);
        MinStackNode *min_node=CreatNode(min);
        min_node->next=new_node;
        MinStack-> head=min_node;
        return;
    }
    if(elem<min)
    {
        min=elem;
    }
    MinStackNode *new_node=CreatNode(elem);
    MinStackNode *min_node=CreatNode(min);
    min_node->next=new_node;
    new_node->next=MinStack->head;
    MinStack->head=min_node;
    return;
}

void MinStackPrint(MinStack MinStack,char *msg)
{
    MinStackNode *cur=MinStack.head;
    printf("%s\n",msg);
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void DestroyNode(MinStackNode* MinStack_node)
{
    assert(MinStack_node);
    free(MinStack_node);
    MinStack_node=NULL;
}

//每次出栈两个元素，分别是此时栈中最小元素和有效的元素
void MinStackPop(MinStack *MinStack)
{
    assert(MinStack);
    if(MinStack->head==NULL)
    {
        printf("出栈失败\n");
        return;
    }

    MinStackNode *to_delete=MinStack->head;
    MinStack->head=MinStack->head->next;
    DestroyNode(to_delete);
    to_delete=MinStack->head;
    MinStack->head=MinStack->head->next;
    DestroyNode(to_delete);
}

int MinStackTop(MinStack MinStack,DataType *value)
{
    assert(value);
    if(MinStack.head!=NULL)
    {
        *value=MinStack.head->data;
        return 1;
    }
    return 0;
}

void MinStackDestroy(MinStack *MinStack)
{
    assert(MinStack);
    while(MinStack->head!=NULL)
    {
        MinStackPop(MinStack);
    }
}
///////////以下为测试代码/////////////////

#define TEST_HEADER printf("=======================%s=============================\n",__FUNCTION__)

void TestPush()
{
    TEST_HEADER;
    
    MinStack MinStack;
    MinStackInit(&MinStack);
    
    MinStackPush(&MinStack,1);
    MinStackPush(&MinStack,2);
    MinStackPush(&MinStack,3);
    MinStackPush(&MinStack,4);
    MinStackPrint(MinStack,"入栈四个元素");
}

void TestPop()
{
    TEST_HEADER;
    
    MinStack MinStack;
    MinStackInit(&MinStack);
    MinStackPrint(MinStack,"初始化栈");
    MinStackPop(&MinStack);

    MinStackPush(&MinStack,1);
    MinStackPush(&MinStack,2);
    MinStackPush(&MinStack,3);
    MinStackPush(&MinStack,4);
    MinStackPrint(MinStack,"入栈四个元素");
    
    MinStackPop(&MinStack);
    MinStackPrint(MinStack,"出栈");
    
    MinStackPop(&MinStack);
    MinStackPrint(MinStack,"出栈");
   
    MinStackPop(&MinStack);
    MinStackPrint(MinStack,"出栈");
    
    MinStackPop(&MinStack);
    MinStackPrint(MinStack,"出栈");

    MinStackPop(&MinStack);
    MinStackPrint(MinStack,"出栈");
}

void TestGetMin()
{
    TEST_HEADER;
    
    MinStack MinStack;
    DataType value; 
    MinStackInit(&MinStack);
    
    MinStackPush(&MinStack,1);
    MinStackPush(&MinStack,2);
    MinStackPush(&MinStack,3);
    MinStackPush(&MinStack,4);
    MinStackPrint(MinStack,"入栈四个元素");
   
    MinStackTop(MinStack,&value);
    printf("%d\n",value);
}

void TestDestroy()
{
     TEST_HEADER;
    
    MinStack MinStack;
    DataType value; 
    MinStackInit(&MinStack);
    
    MinStackPush(&MinStack,1);
    MinStackPush(&MinStack,2);
    MinStackPush(&MinStack,3);
    MinStackPush(&MinStack,4);
    MinStackPrint(MinStack,"入栈四个元素");
   
    MinStackDestroy(&MinStack);
    MinStackPrint(MinStack,"销毁栈");
}
int main()
{
    TestPush();
    TestPop();
    TestGetMin();
    TestDestroy();

    return 0;
}
