#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#define MAX 20
#define INF 99999
using namespace std;
typedef char VertexType;//顶点类型
typedef int EdgeType;//边权值类型
typedef struct EdgeNode//边表节点
{
    int adjvex;//邻接点域，该顶点在顶点表中的下标
    EdgeType weight;//边权值
    struct EdgeNode *next;//链域，指向下一个邻接点
}EdgeNode;
typedef struct VertexNode//顶点表节点
{
    VertexType data;//顶点域，存储顶点信息
    EdgeNode *firstedge;//边表头指针
}VertexNode, AdjList[MAX];
typedef struct
{
    AdjList adjList;
    int vexNum, arcNum;//顶点数和边数
}GraphList;
bool visited[MAX];//标记数组
//定位顶点v在顶表的下标位置，不存在返回-1
int LocateVex(GraphList *g, VertexType v)
{
    int i;
    for(i = 0; i < g->vexNum; i++)
    {
        if(v == g->adjList[i].data)
        {
            break;
        }
    }
    if(i > g->vexNum)
    {
        return -1;
    }
    return i;
}
//邻接表构造图
void CreateGraph(GraphList *g)
{
    int i;
    EdgeType w;
    EdgeNode *e, *f;
    printf("Input the vernum and arcnum:\n");
    //输入顶点：
    scanf("%d%d", &(g->vexNum), &(g->arcNum));
    for(i = 0; i < g->vexNum; i++)
    {
        printf("Vertex %d:", i+1);
        g->adjList[i].data = getchar();
        g->adjList[i].firstedge = NULL;
        while(g->adjList[i].data == '\n')
        {
            g->adjList[i].data = getchar();
        }
    }
    getchar();
    printf("Input vi, vj and w:\n");
    //输入边表：
    for(i = 0; i < g->arcNum; i++)
    {
        char v1, v2;
        scanf("%c %c %d%*c", &v1, &v2, &w);
        int m = LocateVex(g, v1);
        int n = LocateVex(g, v2);
        if(m == -1 || n == -1)
        {
            return;
        }
        //生成边表节点：
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = n;
        e->weight = w;
        e->next = g->adjList[m].firstedge;
        g->adjList[m].firstedge = e;
        f = (EdgeNode *)malloc(sizeof(EdgeNode));
        f->adjvex = m;
        f->weight = w;
        f->next = g->adjList[n].firstedge;
        g->adjList[n].firstedge = f;
    }
}
//打印图
void PrintGraph(GraphList *g)
{
    int i;
    for(i = 0; i < g->vexNum; i++)
    {
        printf("Vertex: %c ", g->adjList[i].data);
        EdgeNode *e = g->adjList[i].firstedge;
        while(e != NULL)
        {
            printf("-> <%c, %c> %d  ", g->adjList[i].data, g->adjList[e->adjvex].data, e->weight);
            e = e->next;
        }
        printf("\n");
    }
}
//邻接表的递归深搜：
void DFS(GraphList *g, int i)
{
    EdgeNode *e;
    visited[i] = true;
    printf("%c ", g->adjList[i].data);
    for(e = g->adjList[i].firstedge; e != NULL; e = e->next)
    {
        if(!visited[e->adjvex])
        {
            DFS(g, e->adjvex);
        }
    }
}
//深搜遍历：
void DFSTraverse(GraphList *g)
{
	int i;
    for(i = 0; i < g->vexNum; i++)
    {
        visited[i] = false;
    }
    printf("DFS Traverse:\n");
    for(i = 0; i < g->vexNum; i++)
    {
        if(!visited[i])
        {
            DFS(g, i);
            printf("\n");
        }
    }
}
//广搜遍历：
void BFSTraverse(GraphList *g)
{
    queue<int>q;
    int i, j;
    for(i = 0; i < g->vexNum; i++)//初始化visited数组
    {
        visited[i] = false;
    }
    printf("BFS Traverse:\n");
    for(i = 0; i < g->vexNum; i++)
    {
        if(!visited[i])//下标未i的顶点尚未访问
        {
            visited[i] = true;
            printf("%c ", g->adjList[i].data);
            q.push(i);//入队列
            while(!q.empty())
            {
                j = q.front();
                q.pop();
                for(EdgeNode *e = g->adjList[i].firstedge; e != NULL; e = e->next)//当前顶点的邻边存在
                {
                    if(!visited[e->adjvex])
                    {
                        visited[e->adjvex] = true;
                        printf("%c ", g->adjList[e->adjvex].data);
                        q.push(e->adjvex);//出队列
                    }
                }
            }
            printf("\n");
        }
    }
}
int main()
{
    GraphList g;
    CreateGraph(&g);
    PrintGraph(&g);
    DFSTraverse(&g);
    BFSTraverse(&g);
    return 0;
}
