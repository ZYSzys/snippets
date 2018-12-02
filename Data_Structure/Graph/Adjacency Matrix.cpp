#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#define N 20
#define INF 99999
using namespace std;
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[N];//顶点数组
    EdgeType arc[N][N];//邻接矩阵
    int vexcnt, arccnt;
}Graph;
bool visited[N];//标记数组
//返回顶点v在顶点数组的下标位置，不存在则返回-1:
int LocateVex(Graph *g, VertexType v)
{
    int i;
    for(i = 0; i < g->vexcnt; i++)
    {
        if(g->vexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}
//邻接矩阵建无向图:
void CreateUndigraph(Graph *g)
{
	int i, j;
    printf("Input the number of vertices and the number of edges:\n");
    scanf("%d%d%*c", &(g->vexcnt), &(g->arccnt));
    //输入顶点:
    for(i = 0; i < g->vexcnt; i++)
    {
        printf("Vertex.%d:", i+1);
        g->vexs[i] = getchar();
        getchar();
    }
    //memset(g->arc, INF, sizeof(g->arc));
    //初始化:
    for(i = 0; i < g->vexcnt; i++)
    {
        for(j = 0; j < g->vexcnt; j++)
        {
            g->arc[i][j] = INF;
        }
    }
    EdgeType w;
    //输入两点间的权值:
    printf("Input vi and vj and w:\n");
    for(i = 0; i < g->arccnt; i++)
    {
        char vi, vj;
        scanf("%c %c %d", &vi, &vj, &w);
        getchar();
        int m = LocateVex(g, vi);
        int n = LocateVex(g, vj);
        if(m == -1 || n == -1)
        {
            exit(-1);
        }
        g->arc[m][n] = g->arc[n][m] = w;
    }
}
//打印无向图:
void PrintGraph(Graph *g)
{
    for(int i = 0; i < g->vexcnt; i++)
    {
        for(int j = 0; j < g->vexcnt; j++)
        {
            printf("%7d", g->arc[i][j]);
        }
        printf("\n");
    }
}
//递归深搜：
void DFS(Graph *g, int i)
{
    visited[i] = true;
    printf("%c ", g->vexs[i]);
    for(int j = 0; j < g->vexcnt; j++)
    {
        if(g->arc[i][j] > 0 && g->arc[i][j] != INF && !visited[j])
        {
            DFS(g, j);
        }
    }
}
//深搜遍历：
void DFSTraverse(Graph *g)
{
	int i;
    for(i = 0; i < g->vexcnt; i++)
    {
        visited[i] = false;
    }
    printf("DFS Traverse:\n");
    for(i = 0; i < g->vexcnt; i++)
    {
        if(!visited[i])
        {
            DFS(g, i);
            printf("\n");
        }
    }
}
//广搜遍历：
void BFSTraverse(Graph *g)
{
    queue<int>q;
    int i, v;
    for(i = 0; i < g->vexcnt; i++)
    {
        visited[i] = false;
    }
    printf("BFS Traverse:\n");
    for(v = 0; v < g->vexcnt; v++)
    {
        if(!visited[v])//下标为v的顶点尚未访问
        {
            visited[v] = true;
            printf("%c ", g->vexs[v]);
            q.push(v);//入队
            while(!q.empty())
            {
                i = q.front();
                q.pop();//出队
                for(int j = 0; j < g->vexcnt; j++)
                {
                    if(g->arc[i][j] > 0 && g->arc[i][j] != INF && !visited[j])//其他顶点与当前点存在边且尚未访问
                    {
                        visited[j] = true;
                        printf("%c ", g->vexs[j]);
                        q.push(j);//入队
                    }
                }
            }
            printf("\n");
        }
    }
}
int main()
{
    Graph g;
    CreateUndigraph(&g); 
    PrintGraph(&g);
    DFSTraverse(&g);
    BFSTraverse(&g);
    return 0;
}
