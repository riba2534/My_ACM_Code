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
const int N=1000+7;
const int M=N*N;
int pre[N],first[N],first2[N],tot,tot2;
bool vis[N];//标记有没有询问
int n;
int fa[N],ans[N];
struct edge
{
    int v,next;
} e[M];
struct Query
{
    int v,next;
} query[M];

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}

void add_query(int u,int v)
{
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
            ans[find(v)]++;
    }
}

void init()
{
    mem(first,-1);
    mem(first2,-1);
    mem(vis,0);
    mem(fa,-1);
    mem(ans,0);
    tot=0;
    tot2=0;
    for(int i=1; i<=n; i++)
        pre[i]=i;
}

int main()
{
    int u,v,k,q;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1; i<=n; i++)
        {
            scanf("%d:(%d)",&u,&k);
            while(k--)
            {
                scanf("%d",&v);
                add_edge(u,v);
                add_edge(v,u);
                fa[v]=u;
            }
        }
        int root=1;
        while(fa[root]!=-1)
            root=fa[root];
        scanf("%d",&q);
        for(int i=1; i<=q; i++)
        {
            scanf(" (%d %d)",&u,&v);
            add_query(u,v);
            add_query(v,u);
        }
        lca(root,root);
        for(int i=1; i<=n; i++)
            if(ans[i])
                printf("%d:%d\n",i,ans[i]);
    }
    return 0;
}
