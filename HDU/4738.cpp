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

int dfn[N],low[N],times,vis[N],color[N],cnt;
int first[N],tot;
int in[N],out[N];//记录出度和入度
int num[N],minn;//记录每个连通图里面有几个点
stack<int>s;//记录强连通分量的顶点
struct edge
{
    int v,w;
    int next;
} e[2*N*N];
void add_edge(int u,int v,int w)
{
    e[tot].v=v;
    e[tot].w=w;
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
    minn=inf;
    while(!s.empty())s.pop();
}
void tarjan(int u,int fa)
{
    int flag=0;
    vis[u]=1;
    s.push(u);
    dfn[u]=low[u]=++times;
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
            if(low[v]>dfn[u])
            {
                minn=min(minn,e[i].w);
            }
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
    //freopen("in.txt","r",stdin);
    int n,m,u,v,w;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        init();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        int sum=0;
        for(int i=1; i<=n; i++)
            if(!dfn[i])
            {
                sum++;
                tarjan(i,-1);
            }
        if(sum>1)
            puts("0");
        else
        {
            if(minn==0)
                puts("1");
            else
                printf("%d\n",minn==inf?-1:minn);
        }
    }
    return 0;
}
/*
3 3
1 2 7
2 3 4
3 1 4

3 2
1 2 7
2 3 4

3 4
1 2 7
2 1 7
2 3 4
3 2 4

4 3
1 2 1
1 2 3
3 4 4

4 4
1 2 1
1 2 3
3 4 4
2 4 6

4 5
1 2 1
1 2 3
3 4 4
2 4 6
1 3 0

4 5
4 3 0
3 4 4
2 4 6
2 3 0
1 3 0

2 1
1 2 0

4 2
1 2 3
1 3 5

4 5
1 2 3
2 3 4
1 3 5
4 3 7
4 3 6

4 4
1 2 3
2 3 4
1 3 5
4 3 6

4 4
1 2 4
1 3 5
4 3 6
3 4 7

6 7
1 2 1
1 3 2
2 3 3
3 4 4
4 6 5
4 5 6
5 6 7

5 6
1 2 3
1 3 4
2 3 5
3 4 7
3 5 8
5 4 9

8 9
1 8 1
5 1 2
1 7 3
1 4 4
1 2 5
4 3 6
3 2 7
5 6 8
6 7 9

6 6
1 4 1
1 2 4
2 5 4
5 6 4
3 6 4
4 3 2

6 5
1 2 4
2 5 4
5 6 4
3 6 4
4 3 2

8 10
1 8 1
5 1 2
1 7 3
1 4 4
1 2 5
4 3 6
3 2 7
5 6 8
6 7 9
8 1 2

3 3
1 2 7
1 3 1
1 3 4

0 0
*/
