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
const int N=200010+20;
const int M=50000+20;
int first[N],tot;

int dfn[N],low[N],times;
int n,m;
int bridge[N],sb;
struct edge
{
    int v,w;
    int next,id;
} e[N];

void init()
{
    mem(first,-1);
    tot=0;
    times=0;
    sb=0;
    mem(dfn,0);
    mem(low,0);
}
void add_edge(int u,int v,int id)
{
    e[tot].v=v;
    e[tot].id=id;
    e[tot].next=first[u];
    first[u]=tot++;
}
void tarjan(int u,int fa)
{
    int flag=0;
    dfn[u]=low[u]=++times;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(i==(fa^1)) continue;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])
                bridge[sb++]=e[i].id;
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    // freopen("in.txt","r",stdin);
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v,i);
            add_edge(v,u,i);
        }
        tarjan(1,-1);
        printf("%d\n",sb);
        if(sb)
        {
            sort(bridge,bridge+sb);
            for(int i=0; i<sb-1; i++)
            {
                printf("%d ",bridge[i]);
            }
            printf("%d\n",bridge[sb-1]);
        }
        if(t)puts("");
    }
    return 0;
}