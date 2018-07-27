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
const int N=5000+120;
const int M=50000+5;

int top;//当前边下标
int dis[N],pre[N];//源点到点i的最小距离，pre[i]记录前驱
bool vis[N];//标记数组
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
bool spfa(int s,int t)
{
    int i,u,v;
    queue<int>q;
    mem(vis,false);
    mem(pre,-1);
    mem(dis,inf);
    vis[s]=true;
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
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    if(dis[t]==inf)
        return false;
    return true;
}
int MCMF(int s,int t)//minCostMaxFlow
{
    int d;
    int i,mincost=0;//maxflow当前最大流量，mincost当前最小费用
    while(spfa(s,t))//表示找到了从s到t的最小费用路
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
int a[N][N],b[N][N],c[N];
/*
a[i][j]存储第i个店主需要第j种货物的个数
b[i][j]存储第i个供货地点第j种货物的剩余量
c[i][j]存储第j个供货商把当前的货物运送到第i个店主的花费
*/
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,k,x;
    while(scanf("%d%d%d",&n,&m,&k)&&(n||m||k))
    {
        mem(c,0);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=k; j++)
            {
                scanf("%d",&a[i][j]);
                c[j]+=a[i][j];
            }
        for(int i=1; i<=m; i++)
            for(int j=1; j<=k; j++)
                scanf("%d",&b[i][j]);
        int ans=0,flag=1;
        for(int o=1; o<=k; o++)//第o个商品
        {
            init();
            for(int i=1; i<=n; i++)//第i个店主
                for(int j=1; j<=m; j++)//第j个进货商
                {
                    scanf("%d",&x);
                    add(j,m+i,b[j][o],x);
                }
                if(flag==0)
                continue;
            for(int i=1; i<=m; i++)
                add(0,i,b[i][o],0);//从源点到第i个仓库的流量是仓库的当前物品的存货量，花费是0
            for(int i=1; i<=n; i++)
                add(m+i,m+n+1,a[i][o],0);//从店主到当前所需要的物品(汇点)，流量是店主对于这个物品的需求量，花费是0
            int now=MCMF(0,m+n+1);
            if(maxflow!=c[o])
            {
                flag=0;
                continue;
            }
            else
                ans+=now;
        }
        if(flag)
            printf("%d\n",ans);
        else
            puts("-1");
    }
    return 0;
}
