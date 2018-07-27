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
const int N=100000+7;
const int M=2*100000+20;

int dfn[N],low[N],times;
int root,son;
int n,m;
int first[N],tot,subnets[N];

struct edge
{
    int v;
    int next;
} e[M];

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}

void init()
{
    mem(dfn,0);
    mem(low,0);
    mem(first,-1);
    mem(subnets,0);
    //mem(vis,0);
    tot=0;
    times=0;
}

void tarjan(int u)
{
    low[u]=dfn[u]=++times;
   //vis[u]=1;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                if(u==root)
                {
                    son++;
                }
                else
                    subnets[u]++;
            }
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    int u,v;
    init();
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    for(int i=1; i<=n; i++)
        if(!dfn[i])
        {
            root=i;
            son=0;
            tarjan(i);
            if(son>1)
                subnets[i]=1;
        }
    int sum=0;
    for(int i=1; i<=n; i++)
        if(subnets[i])
            sum++;
    printf("%d\n",sum);
    for(int i=1; i<=n; i++)
        if(subnets[i])
            printf("%d ",i);
    return 0;
}
