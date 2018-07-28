#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=1000+20;
int e[N][N];
int n,m;
void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            e[i][j]=i==j?0:inf;
}
struct Dijkstra
{
    int vis[N],dis[N];
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
} ac1,ac2;
int main()
{
    int u,v,st,ed;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u,&v);
        e[u][v]=e[v][u]=1;
    }
    ac1.dijkstra(st);
    ac2.dijkstra(ed);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(e[i][j]==inf)
            {
                if(ac1.dis[i]+1+ac2.dis[j]>=ac1.dis[ed]&&ac2.dis[i]+1+ac1.dis[j]>=ac2.dis[st])
                {
                    ans++;
                    e[i][j]=e[j][i]=1;

                }

            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
