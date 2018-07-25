#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define N 1010
#define M 12357
#define ll long long
using namespace std;
int n,m,flag;
int map[N][N];
int dis[N];
int vis[N];
int pre[N];
void dijkstra(int x)
{
    int k,minn;
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    dis[x]=0;
    for(int i=1; i<=n-1; i++)
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
        for(int j=1; j<=n; j++)
            if(vis[j]==0&&dis[k]+map[k][j]<dis[j])
            {
                dis[j]=dis[k]+map[k][j];//如果找到了通路就加上
                if(!flag)pre[j]=k;
            }
    }
}
int main()
{
    int a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        flag=0;
        mem(map,0);
        mem(pre,-1);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                map[i][j]=(i==j)?0:inf;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<map[a][b])map[a][b]=map[b][a]=c;
        }
        dijkstra(1);
        flag=1;
        int temp,maxx=dis[n];
        for(int i=n; i!=-1; i=pre[i])
        {
            int j=pre[i];
            if(i<0||j<0)continue;
            temp=map[j][i];
            map[j][i]=map[i][j]=inf;
            dijkstra(1);
            map[j][i]=map[i][j]=temp;
            maxx=max(maxx,dis[n]);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
