#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node, *List;
int len;//记录链表的长度
//初始化链表：
void InitList(List l)
{
    l->data = 0;
    l->next = NULL;
}
//建立链表：
void CreateList(List l)
{
    Node *p1 = (Node *)malloc(sizeof(Node));
    Node *p2 = (Node *)malloc(sizeof(Node));
    int n;
    len = 0;
    printf("Please input the length of the list:");
    scanf("%d", &n);
    printf("Input the data:");
    while(scanf("%d", &p1->data) != EOF)
    {
        p1->next = NULL;
        if(l->next == NULL)
        {
            l->next = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (Node *)malloc(sizeof(Node));
        if(++len == n)
        {
            break;
        }
    }
    p1 = NULL;
    printf("CreateList succeed!\n");
}
//在第pos的位置插入节点：
void InsertNode(List l)
{
    int pos;
    printf("Please input the position you want to insert:");
    scanf("%d", &pos);
    if(pos <= 0 || pos > len+1)
    {
        printf("The position is illegal\n");
        return;
    }
    printf("Then input the data:");
    for(int i = 1; i < pos; i++)
    {
        l = l->next;
    }
    Node *p = (Node *)malloc(sizeof(Node));
    scanf("%d", &p->data);
    p->next = l->next;
    l->next = p;
    len++;
}
//在第pos的位置删除节点：
void DeleteNode(List l)
{
    int pos;
    printf("Please input the position you want to delete:");
    scanf("%d", &pos);
    if(pos <= 0 || pos > len)
    {
        printf("The position is illegal\n");
        return;
    }
    for(int i = 1; i < pos; i++)
    {
        l = l->next;
    }
    Node *p = l->next;
    l->next = p->next;
    free(p);
}
//给节点定位：
void LocateNode(List l)
{
    int find;
    printf("Please input the data you want to find:");
    scanf("%d", &find);
    l = l->next;
    int i = 0, flag = 0;//flag用来标记所要定位的数据是否在链表中
    while(l != NULL)
    {
        if(l->data == find)
        {
            ++i;
            flag = 1;
            break;
        }
        else
        {
            l = l->next;
            i++;
        }
    }
    if(!flag)
    {
        printf("there is no %d in the list\n", find);
    }
    else
    {
        printf("The data %d is in the %d position.\n", find, i);
    }
}
//打印链表：
void PrintList(List l)
{
    l = l->next;
    if(l == NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    printf("Now the list data:\n");
    while(l != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}
int main()
{
    List l;
    InitList(l);
    CreateList(l);
    PrintList(l);
    InsertNode(l);
    PrintList(l);
    DeleteNode(l);
    PrintList(l);
    LocateNode(l);
    return 0;
}
