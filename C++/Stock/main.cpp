//
//  main.cpp
//  First
//
//  Created by 章贝贝 on 17/1/10.
//  Copyright © 2017年 章贝贝. All rights reserved.
//


/*
#include <stdio.h>
#include <string.h>
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[9][9];
int cnt, cntt;
bool vis[9][9], flag;
struct node
{
    int x, y;
}a[90];
void DFS(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx<0||xx>=9||yy<0||yy>=9)
        {
            continue;
        }
        if(vis[xx][yy])
        {
            continue;
        }
        if(map[xx][yy] == '.')
        {
            cntt++;
        }
        else
        {
            if(map[xx][yy] == 'o')
            {
                vis[xx][yy] = true;
                DFS(xx, yy);
            }
        }
    }
}
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        for(int i = 0; i < 9; i++)
        {
            scanf("%s", map[i]);
            for(int j = 0; j < 9; j++)
            {
                if(map[i][j] == 'o')
                {
                    a[cnt].x = i;
                    a[cnt++].y = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        flag = 0;
        for(int i = 0; i < cnt; i++)
        {
            if(!vis[a[i].x][a[i].y])
            {
                cntt = 0;
                vis[a[i].x][a[i].y] = true;
                DFS(a[i].x, a[i].y);
                if(cntt == 1)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("Case #%d: Can kill in one move!!!\n", ++cas);
        }
        else
        {
            printf("Case #%d: Can not kill in one move!!!\n", ++cas);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
#define N 15
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[N][N];
int cnt, cntt = 0;
bool flag, vis[N][N], viso[N][N];
struct node
{
    int x, y;
}a[100];
void DFS(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx<0||xx>=9||yy<0||yy>=9)
        {
            continue;
        }
        if(vis[xx][yy])
        {
            continue;
        }
        vis[xx][yy] = true;
        if(map[xx][yy] == '.')
        {
            cntt++;
        }
        else if(map[xx][yy] == 'o')
        {
            viso[xx][yy] = true;
            DFS(xx, yy);
        }
    }
}
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        for(int i = 0; i < 9; i++)
        {
            scanf("%s", map[i]);
            for(int j = 0; j < 9; j++)
            {
                if(map[i][j] == 'o')
                {
                    a[cnt].x = i;
                    a[cnt++].y = j;
                }
            }
        }
        memset(viso, false, sizeof(viso));
        flag = false;
        for(int i = 0; i < cnt; i++)
        {
            if(!viso[a[i].x][a[i].y])
            {
                memset(vis, false, sizeof(vis));
                viso[a[i].x][a[i].y] = true;
                cntt = 0;
                DFS(a[i].x, a[i].y);
                if(cntt == 1)
                {
                    flag = true;
                    break;
                }
                
            }
        }
        printf("Case #%d: ", ++cas);
        if(flag)
        {
            printf("Can kill in one move!!!\n");
        }
        else
        {
            printf("Can not kill in one move!!!\n");
        }
    }
    return 0;
}
*/



/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#define N 10
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
    printf("Input the number of vertices and the number of edges:\n");
    scanf("%d%d%*c", &(g->vexcnt), &(g->arccnt));
    //输入顶点:
    for(int i = 0; i < g->vexcnt; i++)
    {
        printf("Vertex.%d:", i+1);
        g->vexs[i] = getchar();
        getchar();
    }
    //memset(g->arc, INF, sizeof(g->arc));
    //初始化:
    for(int i = 0; i < g->vexcnt; i++)
    {
        for(int j = 0; j < g->vexcnt; j++)
        {
            g->arc[i][j] = INF;
        }
    }
    EdgeType w;
    //输入两点间的权值:
    printf("Input vi and vj and w:\n");
    for(int i = 0; i < g->arccnt; i++)
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
    for(int i = 0; i < g->vexcnt; i++)
    {
        visited[i] = false;
    }
    for(int i = 0; i < g->vexcnt; i++)
    {
        if(!visited[i])
        {
            DFS(g, i);
            printf("\n");
        }
    }
}
void BFSTraverse(Graph *g)
{
    queue<int>q;
    int i, v;
    for(i = 0; i < g->vexcnt; i++)
    {
        visited[i] = false;
    }
    for(v = 0; v < g->vexcnt; v++)
    {
        if(!visited[v])
        {
            visited[v] = true;
            printf("%c ", g->vexs[v]);
            q.push(v);
            while(!q.empty())
            {
                q.pop();
                for(int j = 0; j < g->vexcnt; j++)
                {
                    if(g->arc[i][j] > 0 && g->arc[i][j] != INF && !visited[j])
                    {
                        visited[j] = true;
                        printf("%c ", g->vexs[j]);
                        q.push(j);
                    }
                }
            }
        }
        printf("\n");
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
*/

/*
#include <GLUT/GLUT.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    glutMainLoop();
}
*/




/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <stack>
#define N 10010
using namespace std;
int cnt, ans;
bool flag;
char c;
stack<char>s;
int main()
{
    cnt = ans = 0;
    flag = false;
    while(~scanf("%c", &c))
    {
        if(c == '\n')
        {
            if(s.empty())
            {
                printf("YES %d\n", ans);
            }
            else
            {
                printf("NO\n");
            }
            cnt = ans = 0;
            flag = false;
            while(!s.empty())
            {
                s.pop();
            }
            continue;
        }
        else
        {
            char tmp = '0';
            if(!s.empty())
            {
                tmp = s.top();
            }
            s.push(c);
            if(c == '(')
            {
                cnt++;
                ans = max(cnt, ans);
            }
            else
            {
                cnt = 0;
                if(tmp == '(')
                {
                    s.pop();
                    s.pop();
                }
            }
        }
    }
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5010
int p[N] ;
int rank[N];
void InitSet(int p[])
{
    for(int i = 0; i<N; i++)
    {
        p[i] = i ;
    }
    memset(rank, 0, sizeof(rank));
}
int Find(int x)
{
    if(x != p[x])
        p[x] = Find(p[x]) ;
    return p[x] ;
}
void Union(int x, int y)
{
    int t1 = Find(x) ;
    int t2 = Find(y) ;
    if(t1 > t2)
    {
        p[t1] = t2 ;
        rank[t2]++;
    }
    else if(t1 < t2)
    {
        p[t2] = t1 ;
        rank[t1]++;
    }
    else
        return ;
}
int main()
{
    int n, m, x, y;
    bool flag;
    int gro = 0;
    while(~scanf("%d %d", &n, &m))
    {
        InitSet(p);
        while(m--)
        {
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
        gro = 0;
        flag = true;
        for(int i = 1; i <= n; i++)
        {
            if(rank[i] != 0)
            {
                gro++;
                if((rank[i]+1)%3)
                {
                    flag = false;
                }
            }
        }
        if(n >= 3 && n % 3 == 0 && gro >= 1 && gro <= n/3 && flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0 ;
}
*/

/*
#include <stdio.h>
#define N 7
void Shell_Sort1(int a[], int n)//希尔排序--------时间复杂度:O(n*logn)~O(n*n)   空间复杂度:O(1)   不稳定
{
    int i, j, gap;
    for(gap = n /2; gap > 0; gap /= 2)//增量
    {
        for(i = 0; i < gap; i++)//直接插入排序
        {
            for(j = i + gap; j < n; j += gap)
            {
                if(a[j] < a[j - gap])
                {
                    int temp = a[j];
                    int k = j - gap;
                    while(k >= 0 && a[k] > temp)
                    {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = temp;
                }
            }
        }
    }
}
void Shell_Sort2(int a[], int n)
{
    int i, gap;
    for(gap = n /2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            if(a[i] < a[i - gap])//每个元素与自己组内的数据进行直接插入排序
            {
                int temp = a[i];
                int k = i - gap;
                while(k >= 0 && a[k] > temp)
                {
                    a[k + gap] = a[k];
                    k -= gap;
                }
                a[k + gap] = temp;
            }
        }
    }
}
void Shell_Sort3(int a[], int n)
{
    int i, j, gap;
    for(gap = n / 2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            for(j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
            {
                int temp = a[j];
                a[j] = a[j + gap];
                a[j + gap] = temp;
            }
        }
    }
}
void Print_Arr(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i)
        {
            printf(" ");
        }
        printf("%d", a[i]);
        if(i == n-1)
        {
            printf("\n");
        }
    }
}
int main()
{
    int a[N] = {1, 7, 5, 3, 4, 6, 2};
    printf("Before sorting:\n") ;
    Print_Arr(a, N);
    Shell_Sort1(a, N);
    //Shell_Sort2(a, N);
    //Shell_Sort3(a, N);
    printf("After sorting:\n") ;
    Print_Arr(a, N);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define N 100010
using namespace std;
int arr[N], Arr[N];
int B[N];
int len;
int BiSearch(int *b, int len, int w)
{
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right-left)/2;
        if (b[mid] > w)
            right = mid - 1;
        else if (b[mid] < w)
            left = mid + 1;
        else
            return mid;
    }
    return left;
}
int LIS(int *arr, int n)
{
    len = 1;
    B[0] = arr[0];
    int i, pos = 0;
    for(i=1; i<n; ++i)
    {
        if(arr[i] > B[len-1])
        {
            B[len] = arr[i];
            ++len;
        }
        else
        {
            pos = BiSearch(B, len, arr[i]);
            B[pos] = arr[i];
        }
    }
    return len;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            Arr[n-1-i] = arr[i];
        }
        if(n - max(LIS(arr, n), LIS(Arr, n)) <= 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
*/

/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100050
#define INF 0x3f3f3f3f
int t, a[MAXN], ans[MAXN], d[MAXN], S[MAXN],n;
int BSearch(int x, int y, int v)
{
    while(x <= y)
    {
        int mid = x+(y-x)/2;
        if(S[mid] >= v)
        {
            x = mid+1;
        }
        else
            y = mid-1;
    }
    return x;
}
int BSearch2(int x, int y, int v)
{
    while(x <= y)
    {
        int mid = x+(y-x)/2;
        if(S[mid] <= v)
        {
            x = mid+1;
        }
        else
            y = mid-1;
    }
    return x;
}
int LIS()
{
    memset(d,0,sizeof(d));
    for(int i = 1; i <=n; i++)
    {
        S[i] = INF;
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = 1, y = i;
        int pos = BSearch2(x, y, a[i]);
        d[i] = pos;
        S[d[i]] = min(S[d[i]], a[i]);
        res = max(res, d[i]);
    }
    return res;
}
int LFS()
{
    for(int i = 1; i <=n; i++)
    {
        S[i] = -INF;
    }
    memset(d, 0, sizeof(d));
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = 1, y = i;
        int pos = BSearch(x, y, a[i]);
        d[i] = pos;
        S[d[i]] = max(S[d[i]], a[i]);
        res = max(res, d[i]);
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int len1=LIS();
        int len2=LFS();
        int flag=max(len1,len2);
        if(n-1<=flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
*/

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 0x3f3f3f3f
#define N 1010
using namespace std;
int map[N][N];//城市之间的邻接矩阵表示法
int dist[N];//  起点到各个点的最短路径
int pre[N];//存储最短路径
bool vis[N];//标记是否访问过
int t, s, d;
int a, b, tim;
int nn, minn;
void Dijkstra(int v0)//计算单源最短路径, v0为起点
{
    for(int i = 1; i <= nn; i++)//初始化
    {
        dist[i] = map[v0][i];
        vis[i] = false;//所有城市都未访问过
        if(dist[i] == M)
        {
            pre[i] = -1;//与起点之间没有路径，设它的前一座城市为-1, 否则就是起点
        }
        else
        {
            pre[i] = v0;
        }
    }
    dist[v0] = 0;//起点到自身的距离为0
    vis[v0] = true;//标记为访问过
    for(int i = 2; i <= nn; i++)
    {
        minn = M;
        int pos = v0;
        for(int j = 1; j <= nn; j++)//寻找已存在路径中的最短路径
        {
            if(!vis[j] && dist[j] < minn)
            {
                minn = dist[j];
                pos = j;
            }
        }
        vis[pos] = true;//加入到访问过的集合中去
        for(int j = 1;j <= nn; j++)//松弛---经过pos这座城市且以之为中心点的最短路径
        {
            if(!vis[j] && map[pos][j] < M)
            {
                if(dist[pos] + map[pos][j] < dist[j])
                {
                    dist[j] = dist[pos] + map[pos][j];
                    pre[j] = pos;
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d%d", &t, &s, &d))
    {
        nn = 0;
        memset(map, M, sizeof(map));
        for(int i = 0; i < t; i++)
        {
            scanf("%d%d%d", &a, &b, &tim);
            nn = max(nn, max(a, b));
            map[a][b] = map[b][a] = min(tim, map[a][b]);
        }
        for(int i = 0; i < s; i++)
        {
            scanf("%d", &a);
            map[0][a] = 0;
        }
        int m = M;
        Dijkstra(0);
        for(int i = 0; i < d; i++)
        {
            scanf("%d", &a);
            m = min(m, dist[a]);
        }
        printf("%d\n", m);
    }
    return 0;
}
*/

/*
#include <iostream>
#include <climits>
using namespace std;
class Person
{
private:
    int age = 10;
public:
    int Getage()
    {
        return this->age;
    }
};
int main()
{
    int n = 10;
    char name[n];
    Person me;
    cout << me.Getage();
    cout << "Hello, World!\n";
    cout << n << endl;
    cin.getline(name, 10);
    cout << name << endl;

    return 0;
}
*/
/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 510;
int match[N];
bool vis[N],mp[N][N];
void Init()
{
    memset(match, 0, sizeof(match));
    memset(mp, false, sizeof(mp));
}
bool Find(int x, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i] && mp[x][i])
        {
            vis[i] = true;
            if(!match[i])
            {
                match[i] = x;
                return true;
            }
            else if(Find(match[i], n))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int k, m, n, a, b, cnt;
    while(~scanf("%d", &k) && k)
    {
        scanf("%d%d", &m, &n);
        Init();
        cnt = 0;
        for(int i = 1; i <= k; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a][b] = true;
        }
        for(int i = 1; i <= min(m, n); i++)
        {
            memset(vis, false, sizeof(vis));
            if(Find(i, n))
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
*/

/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 510;
int match[N];
bool vis[N],mp[N][N];
void Init()
{
    memset(match, 0, sizeof(match));
    memset(mp, false, sizeof(mp));
}
bool Find(int x, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i] && mp[x][i])
        {
            vis[i] = true;
            if(!match[i] || Find(match[i], n))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int k, m, n, a, b, cnt;
    while(~scanf("%d", &k) && k)
    {
        scanf("%d%d", &m, &n);
        Init();
        cnt = 0;
        for(int i = 1; i <= k; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a][b] = true;
        }
        for(int i = 1; i <= m; i++)
        {
            memset(vis, false, sizeof(vis));
            if(Find(i, n))
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
*/

/*

#include <cstdio>
#include <cstring>
const int N = 20;
struct Point
{
    int x, y;
}p[N];
char mp[5][5];
char c, d;
bool vis[N];
bool Check()
{
    if(mp[1][1]==c&&mp[1][2]==c&&mp[1][3]==c)
        return true;
    if(mp[2][1]==c&&mp[2][2]==c&&mp[2][3]==c)
        return true;
    if(mp[3][1]==c&&mp[3][2]==c&&mp[3][3]==c)
        return true;
    if(mp[1][1]==c&&mp[2][1]==c&&mp[3][1]==c)
        return true;
    if(mp[1][2]==c&&mp[2][2]==c&&mp[3][2]==c)
        return true;
    if(mp[1][3]==c&&mp[2][3]==c&&mp[3][3]==c)
        return true;
    if(mp[1][1]==c&&mp[2][2]==c&&mp[3][3]==c)
        return true;
    if(mp[1][3]==c&&mp[2][2]==c&&mp[3][1]==c)
        return true;
    return false;
}
bool Solve(int k)
{
    if(Check())
    {
        return true;
    }
    if(k == 1)
    {
        mp[p[k-1].x][p[k-1].y] = c;
        if(Check())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(k == 2)
    {
        mp[p[k-2].x][p[k-2].y] = c;
        if(Check())
        {
            return true;
        }
        mp[p[k-2].x][p[k-2].y] = '.';
        mp[p[k-1].x][p[k-1].y] = c;
        if(Check())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //bool flag = false;
        int cnt = 0;
        for(int i = 0; i < k; i++)
        {
            mp[p[i].x][p[i].y] = c;
            vis[i] = true;
            if(Check())
            {
                return true;
            }
            cnt = 0;
            for(int j = 0; j < k; j++)
            {
                if(!vis[j])
                {
                    mp[p[j].x][p[j].y] = d;
                    vis[j] = true;
                    for(int l = 0; l < k; l++)
                    {
                        if(!vis[l])
                        {
                            mp[p[l].x][p[l].y] = c;
                            vis[l] = true;
                            if(Check())
                            {
                                cnt++;
                                mp[p[l].x][p[l].y] = '.';
                                vis[l] = false;
                                break;
                            }
                            mp[p[l].x][p[l].y] = '.';
                            vis[l] = false;
                        }
                    }
                    mp[p[j].x][p[j].y] = '.';
                    vis[j] = false;
                }
            }
            mp[p[i].x][p[i].y] = '.';
            vis[i] = false;
            if(cnt == k-1)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t, k;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        k = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1 ; j <= 3; j++)
            {
                scanf("%c", &mp[i][j]);
                getchar();
                if(mp[i][j] == '.')
                {
                    p[k].x = i;
                    p[k].y = j;
                    k++;
                }
            }
        }
        scanf("%c", &c);
        getchar();
        if(c == 'o')
        {
            d = 'x';
        }
        else
        {
            d = 'o';
        }
        if(Solve(k))
        {
            printf("Kim win!\n");
        }
        else
        {
            printf("Cannot win!\n");
        }
    }
    return 0;
}
 */

/*
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define maxn 1000010
int a[maxn],mmax[maxn],mmin[maxn];
struct cmp1
{
    bool operator()(const int x,const int y)
    {
        return a[x]<a[y];
    }
};
struct cmp2
{
    bool operator()(const int x,const int y)
    {
        return a[x]>a[y];
    }
};
priority_queue<int,vector<int>,cmp1>Q1;//元素从小到大排
priority_queue<int,vector<int>,cmp2>Q2;//元素从大到小排
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>n)
        k=n;
    int s1=0,s2=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)//先让前k个元素入队
        Q1.push(i),Q2.push(i);
    mmax[s1++]=a[Q1.top()];//从队列首取出最大值
    mmin[s2++]=a[Q2.top()];//从队列首取出最小值
    for(int i=k+1;i<=n;i++)
    {
        Q1.push(i);//入队
        Q2.push(i);//入队
        while(i-Q1.top()>=k)//让跑出窗口外的元素出队
            Q1.pop();
        mmax[s1++]=a[Q1.top()];//从队列首取出最大值
        while(i-Q2.top()>=k)//让跑出窗口外的元素出队
            Q2.pop();
        mmin[s2++]=a[Q2.top()];//从队列首取出最小值
    }
    for(int i=0;i<=n-k;i++)//输出最小值
        printf("%d%c",mmin[i],i<n-k?' ':'\n');
    for(int i=0;i<=n-k;i++)//输出最大值
        printf("%d%c",mmax[i],i<n-k?' ':'\n');
    return 0;
}
*/

/*
#include <cstdio>
#define lint long long
const int N = 100010;
lint a[N], m;
int main()
{
    int n, t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld", &n, &m);
        lint cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            lint ans = a[i];
            for(int j = i; j >= 0; j--)
            {
                ans = ans|a[j];
                if(ans < m)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n", ++cas, cnt);
    }
    return 0;
}
*/

/*
#include <cstdio>
#include <stdlib.h>
#include <math.h>

#define MAXN 100005
int a[MAXN];

int main() {
    int t, tt = 0;
    scanf("%d", &t);
    while(t--) {
        int cnt = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int tmp;
        for(int i = 0; i < n; i++) {
            tmp = a[i];
            for(int j = i; j < n; j++) {
                tmp = tmp|a[j];
                if(tmp < m)
                    cnt++;
                else        //如果没有这个判断，会超时
                    break;
            }
        }
        printf("Case #%d: %d\n", ++tt, cnt);
    }
    return 0;
}
 */

/*
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int a[300000];
int b[300000];
struct node
{
    int a,id;
};
struct cmp
{
    bool operator ()(const node &a,const node &b)
    {
        return a.a<b.a;
    }
};
priority_queue< node ,vector<node > ,cmp> Q;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            a[i] -= i;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",b+i);
        }
        while(!Q.empty()) Q.pop();
        sort(b+1,b+1+n);
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            Q.push(node{a[i],i});
        }
        for(int i=n+1;i<=n+n;i++)
        {
            while(Q.top().id<b[i-n]) Q.pop();
            node now = Q.top();
            ans += now.a;
            ans %= MOD;
            Q.push(node{now.a-i,i});
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/


#include <iostream>
#include "stock10.h"
#include "stock10.cpp"
int main()
{
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);
    stock2.show();
    
    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();
    
    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Food", 10, 50.0);
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "Done\n";
    return 0;
}


















