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
const int N=50+20;
const int M=1000+20;
int top;
int h[N],pre[N],g[N];//h[i]记录每个节点的高度，pre[i]记录前驱,g[i]表示距离为i个节点数有多少个
int first[N];
bool vis[N];
int gra[N][N];
struct node
{
    int u,v,next;
    int cap,flow;
} E[M*2];
void init()
{
    mem(first,-1);
    top=0;
}
void add_edge(int u,int v,int c)
{
    E[top].u=u;
    E[top].v=v;
    E[top].cap=c;
    E[top].flow=0;
    E[top].next=first[u];
    first[u]=top++;
}
void add(int u,int v,int c)
{
    add_edge(u,v,c);
    add_edge(v,u,c);
}

void set_h(int t)//标高函数,从终点向起点标高
{
    queue<int>q;
    mem(h,-1);
    mem(g,0);
    h[t]=0;
    q.push(t);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        g[h[v]]++;//当前高度的个数+1
        for(int i=first[v]; ~i; i=E[i].next)
        {
            int u=E[i].v;
            if(h[u]==-1)//当前节点未标高
            {
                h[u]=h[v]+1;
                q.push(u);
            }
        }
    }
}

int Isap(int s,int t,int n)//isap算法
{
    set_h(t);
    int ans=0,u=s;
    int d;
    while(h[s]<n)//节点的高度小于顶点数
    {
        int i=first[u];
        if(u==s) d=inf;
        for(; ~i; i=E[i].next)
        {
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&h[u]==h[v]+1)//容量大于流量且当前的高度等于要去的高度+1
            {
                u=v;
                pre[v]=i;
                d=min(d,E[i].cap-E[i].flow);//找最小增量
                if(u==t)//到达汇点
                {
                    while(u!=s)
                    {
                        int j=pre[u];//找到u的前驱
                        E[j].flow+=d;//正向流量+d
                        E[j^1].flow-=d;//反向流量-d
                        u=E[j^1].v;//向前搜索
                    }
                    ans+=d;
                    d=inf;
                }
                break;
            }
        }
        if(i==-1)//邻接边搜索完毕，无法行进
        {
            if(--g[h[u]]==0)//重要的优化，这个高度的节点只有一个,结束
                break;
            int hmin=n-1;//重贴标签的高度初始为最大
            for(int j=first[u]; ~j; j=E[j].next)
            {
                if(E[j].cap>E[j].flow)
                    hmin=min(hmin,h[E[j].v]);//取所有邻接点高度的最小值
            }
            h[u]=hmin+1;//重新标高
            g[h[u]]++;//标高后该高度的点数+1
            if(u!=s)//不是源点时，向前退一步，重新搜
                u=E[pre[u]^1].v;
        }
    }
    return ans;
}
//void dfs(int s)
//{
//    int a=s,b;
//    for(int i=first[s]; ~i; i=E[i].next)
//    {
//        if(E[i].flow>0)
//        {
//            int u=E[i].v;
//            printf("%d %d\n",a,u);
//            //dfs(u);
//        }
//    }
//}
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=first[now]; ~i; i=E[i].next)
        {
            if(E[i].cap-E[i].flow>0&&!vis[E[i].v])
            {
                //printf("%d %d\n",now,E[i].v);
                vis[E[i].v]=1;
                q.push(E[i].v);
            }
        }
    }
}
int main()
{
    int n,m,u,v,w;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        init();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        Isap(1,2,n);
        mem(vis,0);
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=first[i]; ~j; j=E[j].next)
//            {
//                if(E[j].flow>0)
//                    printf("%d %d\n",i,E[j].v);
//            }
//        }
        bfs(1);
        mem(gra,0);
        for(int i=0; i<=top; i++)
        {
            u=E[i].u;
            v=E[i].v;
            //if(u>v) swap(u,v);
            if((vis[u] && !vis[v]) ||(!vis[u] && vis[v] ) )
            {
                gra[u][v]=gra[v][u]=1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(gra[i][j])
                {
                    printf("%d %d\n",i,j);
                }
            }
        }
        puts("");
    }
    return 0;
}
