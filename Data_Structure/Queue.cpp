#include <stdio.h>
#include <stdlib.h>
//定义队列节点：
typedef struct Node
{
    int data;
    struct Node *next;
}Node, *pNode;
//定义队列：
typedef struct QNode
{
    pNode front;
    pNode last;
}*Queue;
//初始化队列：
void InitQueue(Queue q)
{
    q->front = q->last = (pNode)malloc(sizeof(Node));
    q->front->next = q->last;
    printf("InitQueue succeed!\n");
}
//入队：
void PushQueue(Queue q)
{
    pNode p = (pNode)malloc(sizeof(Node));
    scanf("%d", &p->data);
    p->next = NULL;
    q->last->next = p;
    q->last = p;
}
//返回队头元素：
int FrontQueue(Queue q)
{
    return q->front->next->data;
}
//出队列：
void PopQueue(Queue q)
{
    pNode p = (pNode)malloc(sizeof(Node));
    p = q->front->next;
    q->front->next = p->next;
    free(p);
}
//判断队列是否空：
bool Empty(Queue q)
{
    if(q->front->next == q->last->next)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    Queue q;
    InitQueue(q);
    printf("The number of elements:");
    scanf("%d", &n);
    printf("Input all data:");
    for(int i = 1; i <= n; i++)
    {
        PushQueue(q);
    }
    printf("Now the queue is:");
    while(!Empty(q))
    {
        printf("%d ", FrontQueue(q));
        PopQueue(q);
    }
    printf("\n");
    return 0;
}
