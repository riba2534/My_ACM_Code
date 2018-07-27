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
const int N=1000+20;
int e[N][N];
int nodes;//顶点数目
int tmpdfn;//深度优先搜索的标号
int dfn[N],low[N];
int son;//根节点的子女节点的个数
int subnets[N];//记录每个节点的连通分量的个数
int vis[N];
void dfs(int u)
{
    for(int v=1; v<=nodes; v++)
        if(e[u][v])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dfn[v]=low[v]=++tmpdfn;
                dfs(v);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u])
                {
                    if(u!=1) subnets[u]++;
                    if(u==1) son++;
                }
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
}
void init()
{
    low[1]=dfn[1]=1;
    tmpdfn=1;
    son=0;
    mem(vis,0);
    vis[1]=1;
    mem(subnets,0);
}
int main()
{
    int u,v,q=1;
    while(scanf("%d",&u)&&u)
    {
        scanf("%d",&v);
        mem(e,0);
        nodes=0;
        nodes=max(nodes,max(u,v));
        e[u][v]=e[v][u]=1;
        while(scanf("%d",&u)&&u)
        {
            scanf("%d",&v);
            nodes=max(nodes,max(u,v));
            e[u][v]=e[v][u]=1;
        }
        printf("Network #%d\n",q++);
        init();
        dfs(1);
        if(son>1) subnets[1]=son-1;
        int flag=0;
        for(int i=1; i<=nodes; i++)
            if(subnets[i])
            {
                flag=1;
                printf("  SPF node %d leaves %d subnets\n",i,subnets[i]+1);
            }
        if(!flag)
            printf("  No SPF nodes\n");
        puts("");
    }
    return 0;
}
