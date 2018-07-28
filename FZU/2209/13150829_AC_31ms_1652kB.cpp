#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=100+10;
int cost[N][N][30],u,v,ans[N];
int dis[N],vis[N];
int t,n,m,k,d,s;
void dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        vis[i]=0;
        dis[i]=inf;
    }
    dis[1]=0;
    for(int i=1; i<=n; i++)
    {
        int kk=0,minn=inf;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dis[j]<=minn)
            {
                minn=dis[j];
                kk=j;
            }
        vis[kk]=1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dis[kk]+cost[kk][j][(s+dis[kk])%24]<dis[j])
                dis[j]=dis[kk]+cost[kk][j][(s+dis[kk])%24];
    }
}
int main()
{
    int q=1;
    scanf("%d",&t);
    while(t--)
    {
        mem(cost,inf);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            for(int j=0; j<=23; j++)
            {
                int x;
                scanf("%d",&x);
                //if(x<cost[u][v][j])
                    cost[v][u][j]=cost[u][v][j]=x;
            }
        }
        for(int i=1; i<=k; i++)
        {
            scanf("%d%d",&d,&s);
            dijkstra();
            if(dis[d]==inf)
                ans[i]=-1;
            else
                ans[i]=dis[d];
        }
        printf("Case #%d:",q++);
        for(int i=1; i<=k; i++)
            printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}

