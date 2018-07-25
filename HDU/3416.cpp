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
const int N=1000+20;
const int M=2*100000+20;
int top;
int h[N],pre[N],g[N],first[N],cur[N];//h[i]记录每个节点的高度，pre[i]记录前驱,g[i]表示距离为i个节点数有多少个
struct node
{
    int v,next,cap;
} E[M];
void init()
{
    mem(first,-1);
    top=0;
}
void add_edge(int u,int v,int c)
{
    E[top].v=v;
    E[top].cap=c;
    E[top].next=first[u];
    first[u]=top++;
    E[top].v=u;
    E[top].cap=0;
    E[top].next=first[v];
    first[v]=top++;
}
int sap(int start,int end,int nodenum)
{
    memset(h,0,sizeof(h));
    memset(g,0,sizeof(g));
    memcpy(cur,first,sizeof(first));
    int u=pre[start]=start,maxflow=0,aug=-1;
    g[0]=nodenum;
    while(h[start]<nodenum)
    {
loop:
        for(int &i=cur[u]; i!=-1; i=E[i].next)
        {
            int v=E[i].v;
            if(E[i].cap&&h[u]==h[v]+1)
            {
                if(aug==-1||aug>E[i].cap)
                    aug=E[i].cap;
                pre[v]=u;
                u=v;
                if(v==end)
                {
                    maxflow+=aug;
                    for(u=pre[u]; v!=start; v=u,u=pre[u])
                    {
                        E[cur[u]].cap-=aug;
                        E[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int mindis=nodenum;
        for(int i=first[u]; i!=-1; i=E[i].next)
        {
            int v=E[i].v;
            if(E[i].cap&&mindis>h[v])
            {
                cur[u]=i;
                mindis=h[v];
            }
        }
        if((--g[h[u]])==0)break;
        g[h[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}

int n,m;
struct SPFA
{
    void init()
    {
        mem(first,-1);
        mem(vis,0);
        mem(dis,0);
        len=1;
    }
    int first[N],len,vis[N],dis[N];
    struct node
    {
        int u,v,w,next;
    } G[M];
    void add_edge(int u,int v,int w)
    {
        G[len].v=v,G[len].w=w;
        G[len].next=first[u];
        first[u]=len++;
    }
    void spfa(int st)
    {
        for(int i=1; i<=n; i++)
        {
            dis[i]=inf;
            vis[i]=0;
        }
        dis[st]=0;
        vis[st]=1;
        queue<int>q;
        q.push(st);
        while(!q.empty())
        {
            st=q.front();
            q.pop();
            vis[st]=0;
            for(int i=first[st]; i!=-1; i=G[i].next)
            {
                int v=G[i].v,w=G[i].w;
                if(dis[v]>dis[st]+w)
                {
                    dis[v]=dis[st]+w;
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
} ac1,ac2;
int main()
{
    int t,st,ed,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        init();
        ac1.init();
        ac2.init();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            ac1.add_edge(u,v,w);
            ac2.add_edge(v,u,w);
        }
        scanf("%d%d",&st,&ed);
        ac1.spfa(st);
        ac2.spfa(ed);
        for(int i=1; i<=n; i++)
        {
            for(int j=ac1.first[i]; ~j; j=ac1.G[j].next)
            {
                u=i,v=ac1.G[j].v,w=ac1.G[j].w;
                if(ac1.dis[u]+w+ac2.dis[v]==ac1.dis[ed])
                    add_edge(u,v,1);
            }
        }
        printf("%d\n",sap(st,ed,n));
    }
    return 0;
}
