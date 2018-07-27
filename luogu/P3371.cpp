#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int inf=2147483647;
const int N=10000+20;
int len,dis[N],first[N],vis[N];
int t,n,m,s;
struct node
{
    int u,v,w,next;
} G[500000+20];
void add_edge(int u,int v,int w)//存图函数
{
    G[len].v=v,G[len].w=w;
    G[len].next=first[u];
    first[u]=len++;
}
void dijkstra(int st)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    int k,minn;
    dis[st]=0;
    for(int i=1; i<=n; i++)
    {
        k=0;
        minn=inf;
        for(int j=1; j<=n; j++)
            if(vis[j]==0&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        vis[k]=1;
        for(int j=first[k]; j!=-1; j=G[j].next)
            if(vis[G[j].v]==0&&dis[k]+G[j].w<dis[G[j].v])
                dis[G[j].v]=dis[k]+G[j].w;
    }
}
int main()
{
    int a,b,w;
    scanf("%d%d%d",&n,&m,&s);
    len=1;
    mem(first,-1);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        add_edge(a,b,w);
        //add_edge(b,a,w);
    }
    dijkstra(s);
    for(int i=1; i<=n; i++)
        printf("%d ",dis[i]);
    puts("");
    return 0;
}
