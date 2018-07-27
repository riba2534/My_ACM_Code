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
const int M=400000+5;
int dfn[N],low[N],tot,times;
int first[N],pre[N];
int bridge[N],cnt;
int n,m,k,q=1;
struct edge
{
    int v,next;
} e[M];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    mem(dfn,0);
    mem(low,0);
    mem(bridge,0);
    //mem(pre,-1);
    tot=0;
    cnt=0;
    times=0;
}
void tarjan(int u,int fa)
{
    low[u]=dfn[u]=++times;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(i==(fa^1)) continue;
        if(!dfn[v])
        {
            pre[v]=u;
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])
            {
                cnt++;
                bridge[v]=1;
            }
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}

void lca(int u,int v)
{
    while(dfn[u]>dfn[v])
    {
        if(bridge[u])
        {
            cnt--;
            bridge[u]=0;
        }
        u=pre[u];
    }
    while(dfn[v]>dfn[u])
    {
        if(bridge[v])
        {
            cnt--;
            bridge[v]=0;
        }
        v=pre[v];
    }
    while(u!=v)
    {
        if(bridge[u])
        {
            cnt--;
            bridge[u]=0;
        }
        if(bridge[v])
        {
            cnt--;
            bridge[v]=0;
        }
        u=pre[u];
        v=pre[v];
    }
}

int main()
{
    int u,v;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        init();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        for(int i=1; i<=n; i++)
            if(!dfn[i])
                tarjan(i,-1);
        printf("Case %d:\n",q++);
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d",&u,&v);
            lca(u,v);
            printf("%d\n",cnt);
        }
        puts("");
    }
    return 0;
}

