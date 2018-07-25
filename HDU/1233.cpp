#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100+20
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int vis[120],map[120][120],dis[120];
void Prim()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=map[1][i];
        vis[i]=0;
    }
    vis[1]=1;
    int sum=0;
    for(int i=1; i<=n-1; i++)
    {
        int minn=inf,k=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        //sum+=dis[k];
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&map[k][j]<dis[j])
                dis[j]=map[k][j];
        }
    }
    for(int i=1; i<=n; i++)
        sum+=dis[i];
    printf("%d\n",sum);
}
void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            map[i][j]=(i==j)?0:inf;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        init();
        m=(n*n-n)/2;
        int a,b,c;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=c;
        }
        Prim();
    }
    return 0;
}
