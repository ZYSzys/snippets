#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int Max[50][100]={0};//各进程所需各类资源的最大需求
int Available[100]={0};//系统可用资源
int Allocation[50][100]={0};//系统已分配资源
int Need[50][100]={0};//还需要资源
int Request[50][100]={0};//请求资源向量
int Finish[50]={0};
int p[50]={0};
int m,n; //m个进程，n个资源

int IsSafe()//安全性算法
{
    int i,j,l=0;
    int Work[100];
    for(i=0;i<n;i++)
        Work[i]= Available[i];
    for(i=0;i<m;i++)
        Finish[i]=0;
    for(i=0;i<m;i++)
    {
        if(Finish[i]==1) continue;
        else
        {
            for(j=0;j<n;j++)
            {
                if(Need[i][j]>Work[j]) break;
            }
            if(j==n)
            {
                Finish[i]=1;
                for(int k=0;k<n;k++)
                    Work[k]+=Allocation[i][k];
                p[l++]=i;
                i=-1;
            }
            else continue;
        }
        if(l==m)
        {
            cout<<"系统是安全的"<<'\n';
            cout<<"安全序列是：\n";
            for(i = 0; i < m; i++)
            {
                cout<<p[i];
                if(i!=l-1) cout<<"-->";
            }
            cout<<'\n';
            return 1;
        }
    }
    return 0;
}


int main() //银行家算法
{
    //readTxt("input.txt");
    ifstream filein("input.txt");
    int i, j, mi;
    cout << "输入进程的数目：\n";
    filein >> m;
    cout << m << "\n";
    cout << "输入资源的种类";
    filein >> n;
    cout << n << "\n";
    cout << "输入每个进程最多所需的各资源数，按照" << m << "x" << n <<"矩阵输入\n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            filein >> Max[i][j];
            cout << Max[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "输入每个进程已分配的各资源数，也按照" << m << "x" << n <<"矩阵输入\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            filein >> Allocation[i][j];
            cout << Allocation[i][j] << " ";
            Need[i][j] = Max[i][j]-Allocation[i][j];
            if(Need[i][j]<0)
            { 
                cout<<"你输入的第"<<i+1<<"个进程所拥有的第"<<j+1<<"个资源数错误，请重新输入：\n";
                j--;
                continue;
            }
        }
        cout << "\n";
    }
    cout << "请输入各个资源现有的数目：\n";
    for(i=0;i<n;i++)
    {
        filein >> Available[i];
        cout << Available[i] << " ";
    }
    cout << "\n";    
    IsSafe();
    while(1)
    { 
        cout<<"输入要申请资源的进程号（注：第1个进程号为0，以此类推）\n";
        cin>>mi;
        cout<<"输入进程所请求的各资源的数量\n";
        for(i=0;i<n;i++)
            cin>>Request[mi][i];
        for(i=0;i<n;i++)
        {
            if(Request[mi][i]>Need[mi][i])
            {
                cout<<"你输入的请求数超过进程的需求量！\n";
                return 0;
            }
            if(Request[mi][i]>Available[i])
            {
                cout<<"你输入的请求数超过系统有的资源数！\n";
                return 0;
            }
        }
        for(i=0;i<n;i++)
        {
            Available[i]-=Request[mi][i];
            Allocation[mi][i]+=Request[mi][i];
            Need[mi][i]-=Request[mi][i];
        }
        if(IsSafe()) cout<<"同意分配请求！\n";
        else
        {
            cout<<"你的请求被拒绝！\n";
            for(i=0;i<n;i++)
            {
                Available[i]+=Request[mi][i];
                Allocation[mi][i]-=Request[mi][i];
                Need[mi][i]-=Request[mi][i];
            }
        }
        for(i=0;i<m;i++)
            Finish[i]=0;
        char YesOrNo;
        cout<<"你还想再次请求分配吗？是请按y/Y，否按n/N，再确定\n";
        while(1)
        {
            cin>>YesOrNo;
            if (YesOrNo == 'y'||YesOrNo == 'Y'||YesOrNo == 'n'||YesOrNo == 'N') break;
            else
            {
                cout<<"请按要求输入：\n";
                continue;
            }
        }
        if(YesOrNo=='y'||YesOrNo=='Y') continue;
        else break;
    }
    return 0;
}