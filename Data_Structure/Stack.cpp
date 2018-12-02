#include <stdio.h>
#include <stdlib.h>
//定义栈节点：
typedef struct Node
{
    int data;
    struct Node *next;
}Node, *pNode;
//定义栈：
typedef struct SNode
{
    pNode front;
    pNode rear;
}*Stack;
//初始化栈：
void InitStack(Stack s)
{
    s->rear = s->front = (pNode)malloc(sizeof(Node));
    s->rear->next = NULL;
    s->front->next = s->rear;
    printf("InitStack succeed!\n");
}
//插入元素(等同于入栈):
void InsertStack(Stack s)
{
    Node *p = (Node *)malloc(sizeof(Node));
    scanf("%d", &p->data);
    p->next = s->front->next;
    s->front->next = p;
}
//入栈：
void Push(Stack s, int n)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = n;
    p->next = s->front->next;
    s->front->next = p;
}
//返回栈顶元素：
int Front(Stack s)
{
    return s->front->next->data;
}
//出栈：
void Pop(Stack s)
{
    Node *p = s->front->next;
    s->front->next = p->next;
    free(p);
}
//判断栈空：
bool Empty(Stack s)
{
    if(s->front->next == s->rear)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    Stack s;
    InitStack(s);
    printf("The number of elements:");
    scanf("%d", &n);
    printf("Input all data:");
    for(int i = 1; i <= n; i++)
    {
        InsertStack(s);
        //Push(s, i);
    }
    printf("Insertint over!\n");
    while(!Empty(s))
    {
        printf("%d ", Front(s));
        Pop(s);
    }
    printf("\n");
    return 0;
}
