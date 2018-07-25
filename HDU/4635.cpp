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

int dfn[N],low[N],times,vis[N],color[N],cnt;
int first[N],tot;
int in[N],out[N];//记录出度和入度
int num[N];//记录每个连通图里面有几个点
stack<int>s;//记录强连通分量的顶点
struct edge
{
    int v,w;
    int next;
} e[2*N];
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
    mem(vis,0);
    mem(color,0);
    mem(num,0);
    times=0;
    mem(first,-1);
    tot=0;
    cnt=0;
    mem(in,0);
    mem(out,0);
    while(!s.empty())s.pop();
}
void tarjan(int u)
{
    vis[u]=1;
    s.push(u);
    dfn[u]=low[u]=++times;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        while(1)
        {
            int now=s.top();
            s.pop();
            color[now]=cnt;//染色
            num[cnt]++;//记录同一个分量中顶点的个数
            vis[now]=0;
            if(now==u) break;
        }
    }
}

int main()
{
    int n,m,t,q=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        int u,v;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        for(int i=1; i<=n; i++)
            if(!dfn[i])
                tarjan(i);
        if(cnt==1)
        {
            printf("Case %d: %d\n",q++,-1);
            continue;
        }
        int ans=n*(n-1)-m;
        for(int u=1; u<=n; u++)
        {
            for(int j=first[u]; ~j; j=e[j].next)
            {
                int v=e[j].v;
                if(color[u]!=color[v])
                {
                    in[color[u]]++;
                    out[color[v]]++;
                }
            }
        }
        int minn=inf;
        for(int i=1; i<=cnt; i++)
            if(in[i]==0||out[i]==0)
                minn=min(minn,num[i]);
        ans-=minn*(n-minn);
        printf("Case %d: %d\n",q++,ans);
    }
    return 0;
}

/*
3
3 3
1 2
2 3
3 1
3 3
1 2
2 3
1 3
6 6
1 2
2 3
3 1
4 5
5 6
6 4
*/
