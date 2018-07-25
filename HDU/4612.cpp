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
const int N=200000+7;
const int M=1000000*2+20;
int first[N],tot;//邻接表
int dfn_2[N],vis[N];//求树的直径
int dfn[N],low[N],times,color[N],cnt;//tarjan
stack<int>s;//存储进栈的节点
vector<int>e2[N];//染色后的新图
int n,m;
struct edge
{
    int u,v,w;
    int next;
} e[M];

void init()
{
    mem(first,-1);
    tot=0;
    cnt=0;
    times=0;
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
        if(v==fa&&!flag)//去重边
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
    if(low[u]==dfn[u])
    {
        cnt++;
        while(1)
        {
            int now=s.top();
            s.pop();
            color[now]=cnt;//染色
            if(now==u) break;
        }
    }
}
void dfs(int s,int fa,int len)
{
    vis[s]=1;
    dfn_2[s]=len;
    for(int i=0; i<e2[s].size(); i++)
    {
        int v=e2[s][i];
        if(!vis[v])
            dfs(v,s,len+1);
    }
}


int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        init();
        for(int i=0; i<=n; i++) e2[i].clear();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        for(int i=1; i<=n; i++)
            if(!dfn[i])
                tarjan(i,-1);
        for(int u=1; u<=n; u++)
        {
            for(int j=first[u]; ~j; j=e[j].next)
            {
                int v=e[j].v;
                if(color[u]==color[v]) continue;
                e2[color[u]].push_back(color[v]);//建立新图
            }
        }
        mem(vis,0);
        mem(dfn_2,0);
        dfs(1,-1,1);//搜索出当前搜索树中最远的标号
        int maxx=0,pos=-1;
        for(int i=0; i<=cnt; i++)
        {
            if(maxx<dfn_2[i])
            {
                maxx=dfn_2[i];
                pos=i;
            }
        }
        mem(vis,0);
        mem(dfn_2,0);
        dfs(pos,-1,1);
        maxx=0;
        for(int i=1; i<=cnt; i++)
            maxx=max(maxx,dfn_2[i]);
        printf("%d\n",cnt-maxx);
    }
    return 0;
}



