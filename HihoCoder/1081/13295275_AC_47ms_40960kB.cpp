#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=10000+20;
int e[N][N],vis[N],dis[N];
int n,m,st,ed;
void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            e[i][j]=i==j?0:inf;
}
void dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    dis[st]=0;
    for(int i=1; i<=n; i++)
    {
        int minn=inf,k;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        vis[k]=1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dis[k]+e[k][j]<dis[j])
                dis[j]=dis[k]+e[k][j];
    }
}
int main()
{
    int u,v,w;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<e[u][v])
            e[u][v]=e[v][u]=w;
    }
    dijkstra();
    printf("%d\n",dis[ed]);
    return 0;
}
