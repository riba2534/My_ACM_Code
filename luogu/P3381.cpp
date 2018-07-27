// luogu-judger-enable-o2
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
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=5000+20;
const int M=50000+20;

int top;//当前边下标
int dis[N],pre[N];//源点到点i的最小距离，pre[i]记录前驱
bool vis[N];//标记数组
//int c[N];//入队次数
int maxflow;
int first[N];//存储头结点
struct Edge
{
    int v,next;
    int cap,flow,cost;
} E[M*2];

void init()
{
    mem(first,-1);
    top=0;
    maxflow=0;
}

void add_edge(int u,int v,int c,int cost)
{
    E[top].v=v;
    E[top].cap=c;
    E[top].flow=0;
    E[top].cost=cost;
    E[top].next=first[u];
    first[u]=top++;
}
void add(int u,int v,int c,int cost)
{
    add_edge(u,v,c,cost);
    add_edge(v,u,0,-cost);
}
bool spfa(int s,int t,int n)
{
    int i,u,v;
    queue<int>q;
    mem(vis,false);
//    mem(c,0);
    mem(pre,-1);
    for(int i=1; i<=n; i++) dis[i]=inf;
    vis[s]=true;
//    c[s]++;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=first[u]; i!=-1; i=E[i].next)
        {
            v=E[i].v;
            if(E[i].cap>E[i].flow&&dis[v]>dis[u]+E[i].cost)
            {
                dis[v]=dis[u]+E[i].cost;
                pre[v]=i;
                if(!vis[v])
                {
//                    c[v]++;
                    q.push(v);
                    vis[v]=true;
//                    if(c[v]>n)
                  //      return false;//超过入队上线说明有负环
                }
            }
        }
    }
    if(dis[t]==inf)
        return false;
    return true;
}
int MCMF(int s,int t,int n)//minCostMaxFlow
{
    int d;
    int i,mincost=0;//maxflow当前最大流量，mincost当前最小费用
    while(spfa(s,t,n))//表示找到了从s到t的最小费用路
    {
        d=inf;
        for(int i=pre[t]; i!=-1; i=pre[E[i^1].v]) //遍历反向边
            d=min(d,E[i].cap-E[i].flow);
        maxflow+=d;//更新最大流
        for(int i=pre[t]; i!=-1; i=pre[E[i^1].v]) //增广路上正向边流量+d,反向边流量-d
        {
            E[i].flow+=d;
            E[i^1].flow-=d;
        }
        mincost+=dis[t]*d;//dis[t]为该路径上单位流量费用之和
    }
    return mincost;
}
int main()
{
    int n,m,st,ed;
    int u,v,w,c;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d%d",&u,&v,&w,&c);
        add(u,v,w,c);
    }
    int mincost=MCMF(st,ed,n);
    printf("%d %d\n",maxflow,mincost);
    return 0;
}
