#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pir;
const int N=1e5+10;
const int M=1e6+10;
int n,m;
int first[N],tot;
int dis[N],vis[N];
struct edge
{
    int v,w,next;
} e[M];
void add_edge(int u,int v,int w)
{
    e[tot].v=v;
    e[tot].w=w;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    tot=0;
}
void dijkstra(int st)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    dis[st]=0;
    for(int i=1; i<=n; i++)
    {
        int minn=inf,k=0;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        vis[k]=1;
        for(int j=first[k]; ~j; j=e[j].next)
            if(!vis[e[j].v]&&dis[k]+e[j].w<dis[e[j].v])
                dis[e[j].v]=dis[k]+e[j].w;
    }
}
int main()
{
    int st,ed,u,v,w;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dijkstra(st);
    printf("%d\n",dis[ed]);
    return 0;
}
