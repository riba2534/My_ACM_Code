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
const int N=10000+20;
const int M=1e6+10;
struct edge
{
    int v,next;
    bool cut;//是否为桥
} e[M];
int first[N],tot;
int low[N],dfn[N],Stack[N];
//dfn[i]代表i在深度优先搜索中的访问序号
//low[i]代表从i或i的子孙出发，通过回边可以到达的最低深度优先数
int Index,top;
bool instack[N];
bool cut[N];
int add_block[N];
int bridge;

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    e[tot].cut=false;
    first[u]=tot++;
}

void tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=++Index;
    Stack[top++]=u;
    instack[u]=true;
    int son=0;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        v=e[i].v;
        if(v==pre) continue;
        if(!dfn[v])
        {
            son++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            //桥
            //一条无向边(u,v)是桥，满足dfn[u]<low[v]
            if(low[v]>dfn[u])//当是桥时
            {
                bridge++;
                e[i].cut=true;
                e[i^1].cut=true;
            }
            //割点的条件是dfn[u]<=low[v]
            if(u!=pre&&low[v]>=dfn[u])
            {
                cut[u]=true;
                add_block[u]++;
            }
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
    //树根，分支数大于1
    if(u==pre&&son>1) cut[u]=true;
    if(u==pre) add_block[u]=son-1;
    instack[u]=false;
    top--;
}
void solve(int n)
{
    mem(dfn,0);
    mem(instack,0);
    mem(add_block,0);
    mem(cut,0);
    Index=top=0;
    bridge=0;
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i,i);
    int ans=0;
    for(int i=1; i<=n; i++)
        if(cut[i])
            ans++;
    printf("%d\n",ans);
}
void init()
{
    tot=0;
    mem(first,-1);
}
char s[1100];
int g[110][110];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        gets(s);
        mem(g,0);
        while(gets(s))
        {
            if(strcmp(s,"0")==0) break;
            char *p=strtok(s," ");
            int u;
            sscanf(p,"%d",&u);
            p=strtok(NULL," ");
            int v;
            while(p)
            {
                sscanf(p,"%d",&v);
                p=strtok(NULL," ");
                g[u][v]=g[v][u]=1;
                // printf("u=%d,v=%d\n",u,v);
            }
        }
        init();
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                if(g[i][j])
                {
                    add_edge(i,j);
                    add_edge(j,i);
                }
        solve(n);
    }
    return 0;
}

