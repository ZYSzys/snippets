#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ElemType;
typedef enum{Link, Thread} childTag;
typedef struct bitNode
{
    ElemType data;
    struct bitNode *lchild, *rchild;
    int ltag, rtag;
}bitNode, *bitTree;
void create_tree(bitTree *T, char **arr);//建立树
void pre_order_traverse(bitTree T, int level);//前序遍历
void in_order_threading(bitTree T);
void in_thread(bitTree *P, bitTree T);//中序遍历线索化
void in_order_traverse(bitTree T);//中序遍历
void visit(bitTree T);
bitTree pre;
int main()
{
    bitTree P, T;
    int level = 1;
    char *arr = "ab d  ce   ";
    create_tree(&T, &arr);
    printf("pre-order-traverse\n");
    pre_order_traverse(T, level);
    printf("in-order-traverse\n");
    in_thread(&P, T);
    in_order_traverse(P);
    return 0;
}
void create_tree(bitTree *T, char **arr)
{
    char c;
    sscanf(*arr, "%c", &c);
    (*arr)++;
    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (bitTree)malloc(sizeof(bitNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        create_tree(&(*T)->lchild, arr);
        create_tree(&(*T)->rchild, arr);
    }
}
void pre_order_traverse(bitTree T, int level)
{
    if(T)
    {
        visit(T);
        pre_order_traverse(T->lchild, level+1);
        pre_order_traverse(T->rchild, level+1);
    }
}
void in_order_threading(bitTree T)
{
    if(T)
    {
        in_order_threading(T->lchild);
        if(!T->lchild)
        {
            T->lchild = pre;
            T->ltag = Thread;
        }
        if(!pre->rchild)
        {
            pre->rchild = T;
            pre->rtag = Thread;
        }
        pre = T;
        in_order_threading(T->rchild);
    }
}
void in_thread(bitTree *P, bitTree T)
{
    (*P) = (bitTree)malloc(sizeof(bitNode));
    (*P)->ltag = Link;
    (*P)->rtag = Thread;
    (*P)->rchild = *P;
    if(!T)
    {
        (*P)->lchild = *P;
    }
    else
    {
        (*P)->lchild = T;
        pre = *P;
        in_order_threading(T);
        (*P)->rchild = pre;
        pre->rtag = Thread;
        pre->rchild = *P;
    }
}
void in_order_traverse(bitTree P)
{
    bitTree T;
    T = P->lchild;
    while(T != P)
    {
        while(T->ltag == Link)
        {
            T = T->lchild;
        }
        visit(T);
        while(T->rtag == Thread && T->rchild != P)
        {
            T = T->rchild;
            visit(T);
        }
        T = T->rchild;
    }
}
void visit(bitTree T)
{
    printf("%d-%c-%d\n", T->ltag, T->data, T->rtag);
}
