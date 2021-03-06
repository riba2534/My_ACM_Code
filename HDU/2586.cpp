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
const int M=2*N;
int pre[N],first[N],first2[N],tot,tot2;
bool vis[N];//标记有没有询问
int n;
int fa[N],ans[N],cnt;
int vis2[N],dis[N];
map<string,int>mp;
struct edge
{
    int v,next,w;
} e[M];
struct Query
{
    int v,next,id;
} query[M];

void add_edge(int u,int v,int w)
{
    e[tot].v=v;
    e[tot].w=w;
    e[tot].next=first[u];
    first[u]=tot++;
}

void add_query(int u,int v,int id)
{
    query[tot2].id=id;
    query[tot2].v=v;
    query[tot2].next=first2[u];
    first2[u]=tot2++;
}

int find(int x)
{
    return x==pre[x]?x:pre[x]=find(pre[x]);
}

void lca(int u,int fa)
{
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa) continue;
        lca(v,u);
        pre[v]=u;
    }
    vis[u]=1;
    for(int i=first2[u]; ~i; i=query[i].next)
    {
        int v=query[i].v;
        if(vis[v])
        {
            int id=query[i].id;
            ans[id]=dis[u]+dis[v]-2*dis[find(v)];
        }
    }
}

void dfs(int u,int len)
{
    vis2[u]=1;
    dis[u]=len;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v,w=e[i].w;
        if(!vis2[v])
            dfs(v,len+w);
    }
}
void init()
{
    mem(first,-1);
    mem(first2,-1);
    mem(vis,0);
    mem(vis2,0);
    mem(fa,-1);
    mem(ans,0);
    tot=0;
    tot2=0;
    cnt=1;
    mp.clear();
    for(int i=1; i<=n; i++)
        pre[i]=i;
}
int main()
{
    int t,m;
    int u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_query(u,v,i);
            add_query(v,u,i);
        }
        dfs(1,0);
        lca(1,1);
        for(int i=1; i<=m; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
