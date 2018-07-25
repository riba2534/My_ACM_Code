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
const int N=200000+7;

int n,m,s;
int tot;
int first[N],d[N],p[N][21];
int dis[N];



vector<int>G[N];

struct edge
{
    int v,next,w;
} e[2*N];

void add_edge(int u,int v,int w)
{
    e[tot].w=w;
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}

void dfs(int u,int fa,int len)
{
    d[u]=d[fa]+1;//dfs处理深度
    dis[u]=len;
    p[u][0]=fa;//u的第一号祖先(父亲节点)
    for(int i=1; (1<<i)<=d[u]; i++)
        p[u][i]=p[p[u][i-1]][i-1];
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v,w=e[i].w;
        if(v!=fa)
            dfs(v,u,len+w);
    }
}

int lca(int a,int b)
{
    if(d[a]>d[b])
        swap(a,b);//保证a在b点的上方
    for(int i=20; i>=0; i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];  //把b移到和a同一个深度
    if(a==b)
        return a;
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
    mem(p,0);
    mem(G,0);
    mem(dis,0);
}
int main()
{
    int t,u,v,w,q;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        int num,x;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&x);
                G[i].push_back(x);
            }
        }
        dfs(1,0,0);
        scanf("%d",&q);
        while(q--)
        {
            int ans=inf;
            scanf("%d%d",&u,&v);
            for(int i=0; i<G[u].size(); i++)
                for(int j=0; j<G[v].size(); j++)
                {
                    int a=G[u][i];
                    int b=G[v][j];
                    ans=min(ans,dis[a]+dis[b]-2*dis[lca(a,b)]);
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}
