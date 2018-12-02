#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
typedef char ElemType;
//定义二叉树节点：
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode * lchild;
    struct BiTNode * rchild;
    struct BiTNode * parent;
}BiTNode, *BiTree;
//初始化二叉树：
void InitBiTree(BiTree *t)
{
    *t = NULL;
}
//建立二叉树：
void CreateBiTree(BiTree *t)
{
    char n;
    scanf("%c%*c", &n);
    if(n == '0')//输入0表示置该节点为空，不再向下继续建立子树
    {
        *t = NULL;
    }
    else
    {
        *t = (BiTNode *)malloc(sizeof(BiTNode));
        (*t)->data = n;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        CreateBiTree(&(*t)->lchild);
        CreateBiTree(&(*t)->rchild);
    }
}
//插入数据作为叶：
void InsertBiTNode(BiTree *t, ElemType data)
{
    BiTNode * p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    p->parent = NULL;
    if((*t) == NULL)
    {
        (*t) = p;
    }
    else if((*t)->lchild == NULL)
    {
        (*t)->lchild = p;
        (*t)->lchild->parent = (*t);
    }
    else if((*t)->rchild == NULL)
    {
        (*t)->rchild = p;
        (*t)->rchild->parent = (*t);
    }
    else
    {
        InsertBiTNode((&(*t)->lchild), data);
    }
}
//计算树高：
int Height(BiTree t)
{
    int lh = 0, rh = 0;
    if(t->lchild == NULL && t->rchild == NULL)
    {
        lh = rh = 1;
    }
    else
    {
        if(t->lchild != NULL && t->rchild != NULL)
        {
            lh = Height(t->lchild) + 1;
            rh = Height(t->rchild) + 1;
        }
        else if(t->lchild != NULL)
        {
            lh = Height(t->lchild) + 1;
        }
        else
        {
            rh = Height(t->rchild) + 1;
        }
    }
    return lh > rh?lh:rh;
}
//前序遍历：
void PreprintBiTree(BiTree t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        printf("%c ", t->data);
        PreprintBiTree(t->lchild);
        PreprintBiTree(t->rchild);
    }
}
//中序遍历：
void InprintBiTree(BiTree t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        InprintBiTree(t->lchild);
        printf("%c ", t->data);
        InprintBiTree(t->rchild);
    }
}
//后序遍历：
void PostprintBiTree(BiTree t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        PostprintBiTree(t->lchild);
        PostprintBiTree(t->rchild);
        printf("%c ", t->data);
    }
}
//销毁树：
void Destroy(BiTree t)
{
    if(t->lchild == NULL && t->rchild == NULL)
    {
        free(t);
    }
    else
    {
        if(t->lchild != NULL && t->rchild != NULL)
        {
            Destroy(t->lchild);
            Destroy(t->rchild);
            free(t);
        }
        else if(t->lchild != NULL)
        {
            Destroy(t->lchild);
            free(t);
        }
        else
        {
            Destroy(t->rchild);
            free(t);
        }
    }
}
//非递归前序遍历:
void PreprintBiTree_NonRecursive(BiTree t)
{
    BiTNode * p = t;
    stack<BiTree>s;
    while(p || !s.empty())
    {
        if(p)
        {
            printf("%c ", p->data);
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}
//非递归中序遍历(利用栈)：
void InprintBiTree_NonRecursive(BiTree t)
{
    BiTNode * p = t;
    stack<BiTree>s;
    while(p || !s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            printf("%c ", p->data);
            s.pop();
            p = p->rchild;
        }
    }
}
//非递归后序遍历：
void PostprintBiTree_NonRecursive(BiTree t)
{
    BiTNode * cur, * pre = NULL;
    stack<BiTree>s;
    s.push(t);
    while(!s.empty())
    {
        cur = s.top();
        if((cur->lchild == NULL && cur->rchild == NULL)||(pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
        {
            printf("%c ", cur->data);
            s.pop();
            pre = cur;
        }
        else
        {
            if(cur->rchild != NULL)
            {
                s.push(cur->rchild);
            }
            if(cur->lchild != NULL)
            {
                s.push(cur->lchild);
            }
        }
    }
}
int main()
{
    BiTree t;
    InitBiTree(&t);
    CreateBiTree(&t);
    printf("递归前序遍历：");
    PreprintBiTree(t);//前序遍历
    printf("\n");
    printf("递归中序遍历：");
    InprintBiTree(t);//中序遍历
    printf("\n");
    printf("递归后序遍历：");
    PostprintBiTree(t);//后序遍历
    printf("\n");
    printf("非递归前序遍历：");
    PreprintBiTree_NonRecursive(t);//非递归前序遍历
    printf("\n");
    printf("非递归中序遍历：");
    InprintBiTree_NonRecursive(t);//非递归中序遍历
    printf("\n");
    printf("非递归后序遍历：");
    PostprintBiTree_NonRecursive(t);//非递归后序遍历
    printf("\n");
    printf("Height: %d\n", Height(t));
    ElemType data;
    printf("Input the new leaf data:");
    scanf(" %c", &data);
    InsertBiTNode(&t, data);
    InprintBiTree_NonRecursive(t);//非递归中序遍历
    printf("\n");
    Destroy(t);//销毁树
    return 0;
}
