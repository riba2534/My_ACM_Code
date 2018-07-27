#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100+20;
int g[N][N],pre[N];
bool vis[N];
int st,ed,p;
bool bfs(int s,int t)
{
    mem(pre,-1);
    mem(vis,false);
    queue<int>q;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=st; i<=ed; i++)
        {
            if(!vis[i]&&g[now][i]>0)
            {
                vis[i]=true;
                pre[i]=now;
                if(i==t)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}
int EK(int s,int t)
{
    int v,w,d,maxflow=0;
    while(bfs(s,t))
    {
        v=t;
        d=inf;
        while(v!=s)
        {
            w=pre[v];
            d=min(d,g[w][v]);
            v=w;
        }
        maxflow+=d;
        v=t;
        while(v!=s)
        {
            w=pre[v];
            g[w][v]-=d;
            g[v][w]+=d;
            v=w;
        }
    }
    return maxflow;
}

int cp[N][N];//备份图
int in[N][20];//输入信息
int line[N][4];//输出结果

int main()
{
    int p,n;
    while(~scanf("%d%d",&p,&n))
    {
        mem(g,0);
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<2*p+1; j++)
                scanf("%d",&in[i][j]);
        }
        for(int i=1; i<=n; i++) //拆点
            g[2*i-1][2*i]=in[i][0];
        st=0;//源点
        ed=2*n+1;//汇点
        for(int i=1; i<=n; i++)
        {
            bool flag_s=true;
            bool flag_t=true;
            for(int j=0; j<p; j++)
            {
                if(in[i][j+1]==1) flag_s=false;//输入必须全是0
                if(in[i][j+p+1]==0) flag_t=false;//输出必须全是1
            }
            if(flag_s) g[0][2*i-1]=inf;//超级源点和一个工厂容量无限大
            if(flag_t) g[2*i][ed]=inf;//从工厂刀汇点容量无限大
            for(int j=1; j<=n; j++)
            {
                if(i!=j)//枚举不相同的点
                {
                    bool flag=true;
                    for(int k=0; k<p; k++)//枚举部件
                    {
                        //这个点的输出和另一个点的输入不一样的时候，不能建立边
                        if((in[i][k+p+1]==0&&in[j][k+1]==1)||(in[i][k+p+1]==1&&in[j][k+1]==0))
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag)//一样的时候建边，权值为这两个工厂所能处理的量的最小值
                        g[2*i][2*j-1]=min(in[i][0],in[j][0]);
                }
            }
        }
        memcpy(cp,g,sizeof(g));
        printf("%d ",EK(st,ed));
        int tot=0;//记录要建立的边的数量
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(g[2*i][2*j-1]<cp[2*i][2*j-1])
                {
                    line[tot][0]=i;
                    line[tot][1]=j;
                    line[tot][2]=cp[2*i][2*j-1]-g[2*i][2*j-1];
                    tot++;
                }
            }
        }
        printf("%d\n",tot);
        for(int i=0; i<tot; i++)
            printf("%d %d %d\n",line[i][0],line[i][1],line[i][2]);
    }
    return 0;
}