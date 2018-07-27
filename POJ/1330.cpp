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
const int N=1e4+7;

int n,m,s;
int tot;
int first[N],d[N],p[N][21];
int fa[N];

struct edge
{
    int v,next;
} e[2*N];

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}

void dfs(int u,int fa)
{
    d[u]=d[fa]+1;//dfs处理深度
    p[u][0]=fa;//u的第一号祖先(父亲节点)
    for(int i=1; (1<<i)<=d[u]; i++)
        p[u][i]=p[p[u][i-1]][i-1];
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v!=fa)
            dfs(v,u);
    }
}

int lca(int a,int b)
{
    if(d[a]>d[b]) swap(a,b);//保证a在b点的上方
    for(int i=20; i>=0; i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];  //把b移到和a同一个深度
    if(a==b) return a;
    for(int i=20; i>=0; i--)
    {
        if(p[a][i]==p[b][i])
            continue;
        else
            a=p[a][i],b=p[b][i];//一起向上跳跃
    }
    return p[a][0];
}


void init()
{
    tot=0;
    mem(first,-1);
    mem(d,0);
    mem(fa,-1);
    mem(p,0);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        int a,b;
        scanf("%d",&n);
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            add_edge(a,b);
            add_edge(b,a);
            fa[b]=a;
        }
        int root=1;
        while(fa[root]!=-1)
            root=fa[root];
        dfs(root,0);
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}
