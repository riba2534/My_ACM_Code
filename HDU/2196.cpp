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
const int N=1e4+20;
int dp[N][3];
int n;
int first[N],pos;

struct edge
{
    int v,w;
    int next;
} G[2*N];

void add_edge(int u,int v,int w)
{
    G[pos].v=v;
    G[pos].w=w;
    G[pos].next=first[u];
    first[u]=pos++;
}
void init()
{
    mem(first,-1);
    mem(dp,0);
    pos=0;
}

void dfs1(int u,int fa)
{
    int ans1=0,ans2=0;//分别代表最大和和次大和
    for(int i=first[u]; ~i; i=G[i].next)
    {
        int v=G[i].v;
        if(v==fa)continue;
        dfs1(v,u);
        int res=dp[v][0]+G[i].w;
        if(res>=ans1)
        {
            ans2=ans1;//先更新次大和
            ans1=res;//再更新最大和
        }
        else if(res>ans2)
            ans2=res;
    }
    dp[u][0]=ans1;
    dp[u][1]=ans2;
    //printf("dp[%d][0]=%d\tdp[%d][1]=%d\n",u,dp[u][0],u,dp[u][1]);
}

void dfs2(int u,int fa)
{
    for(int i=first[u]; ~i; i=G[i].next)
    {
        int v=G[i].v,w=G[i].w;
        if(v==fa)continue;
        if(dp[v][0]+w==dp[u][0])
            dp[v][2]=max(dp[u][2],dp[u][1])+w;
        else
            dp[v][2]=max(dp[u][2],dp[u][0])+w;
        dfs2(v,u);
    }
}

int main()
{
    int v,w;
    while(~scanf("%d",&n))
    {
        init();
        for(int u=2; u<=n; u++)
        {
            scanf("%d%d",&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for(int i=1; i<=n; i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
/*
12
1 1
1 1
2 1
2 1
4 1
4 1
5 1
5 1
9 1
10 1
8 1
*/

