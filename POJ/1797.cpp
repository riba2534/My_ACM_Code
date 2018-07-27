#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define maxnum 2010
#define inf 0x3f3f3f
using namespace std;
int n,m,maxx,u;
int map[maxnum][maxnum],dis[maxnum],vis[maxnum];
int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        mem(map,0);
        int a,b,c;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=c;
        }
        //dijikstra
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            dis[i]=map[1][i];
        }

        vis[1]=1;
        for(int i=1;i<=n-1;i++)
        {
            maxx=0;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j]&&dis[j]>maxx)
                {
                    maxx=dis[j];
                    u=j;
                }
            }
            vis[u]=1;
            for(int j=1;j<=n;j++)
                if(!vis[j]&&dis[j]<min(dis[u],map[u][j]))
                    dis[j]=min(dis[u],map[u][j]);

        }
        printf("Scenario #%d:\n%d\n\n",q++,dis[n]);
    }
    return 0;
}
