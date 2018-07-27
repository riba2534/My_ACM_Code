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
const int N=5000+7;
const int M=1e5+20;
int first[N],tot;

int dfn[N],low[N],times;
int cnt,inq[N];
stack<int>s;
int n,m;
struct edge
{
    int u,v,w;
    int next;
} e[M];

void init()
{
    mem(inq,0);
    mem(first,-1);
    tot=0;
    times=0;
    cnt=0;
    mem(dfn,0);
    mem(low,0);
    while(!s.empty())s.pop();
}
void add_edge(int u,int v)
{
    e[tot].u=u;
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void tarjan(int u,int fa)
{
    int flag=0;
    dfn[u]=low[u]=++times;
    s.push(u);
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa&&!flag)
        {
            flag=1;
            continue;
        }
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}
int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        tarjan(1,-1);
        int sum=0;
        for(int i=0; i<tot; i++)
        {
            u=low[e[i].u];
            v=low[e[i].v];
            if(u!=v)
                inq[v]++;
        }
        for(int i=1; i<=n; i++)
            if(inq[i]==1)
                sum++;
        printf("%d\n",(sum+1)/2);
    }
    return 0;
}
