#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 1000+20
#define inf 0x3f3f3f3f
#define M 1000000+2000
#define LL long long
using namespace std;
LL n,m,x00,x11,y00,y11;
LL map[N][N],dis[N],vis[N];
LL xx[M],yy[M],zz[M];
void init()
{
    for(LL i=0; i<n; i++)
    {
        for(LL j=0; j<n; j++)
        {
            map[i][j]=inf;
        }
        map[i][i]=0;
    }
    xx[0]=x00;
    xx[1]=x11;
    yy[0]=y00;
    yy[1]=y11;
    for(LL k=2; k<=n*n; k++)
    {
        xx[k]=(12345+xx[k-1]*23456+xx[k-2]*34567+xx[k-1]*xx[k-2]*45678)%5837501;
        yy[k]=(56789+yy[k-1]*67890+yy[k-2]*78901+yy[k-1]*yy[k-2]*89012)%9860381;
    }
    for(LL k=0; k<=n*n; k++)
    {
        zz[k]=(xx[k]*90123+yy[k])%8475871+1;
    }
    for(LL i=0; i<n; i++)
    {
        for(LL j=0; j<n; j++)
        {
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=zz[i*n+j];
        }
    }
}
void dj()
{
    LL minn,k=0;
    for(LL i=0; i<=n; i++)
    {
        dis[i]=map[0][i];
        vis[i]=0;
    }
    dis[0]=0;
    for(LL j=0; j<n; j++)
    {
        minn=inf;
        for(LL i=0; i<n; i++)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
                k=i;
            }
        }
        vis[k]=1;
        for(LL i=0; i<n; i++)
        {
            if(!vis[i]&&dis[i]>dis[k]+map[k][j])
            {
                dis[i]=dis[k]+map[k][j];
                printf("dis[%lld]=%lld\n",i,dis[i]);
            }

        }
    }
    return;
}
void dij()
{
    int minx,k=0;
    for(int i=0; i<=n; i++)
    {
        dis[i]=map[0][i];
        vis[i]=0;
    }
    dis[0]=0;
    for(int j=0; j<n; j++)
    {
        minx=inf;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0&&minx>dis[i])
            {
                minx=dis[i];
                k=i;
            }
        }
        vis[k]=1;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0&&dis[i]>dis[k]+map[k][i])
            {
                dis[i]=dis[k]+map[k][i];
            }
        }
    }
    return ;
}
void solve()
{
    LL minn=inf;
    for(LL i=1; i<n; i++)
    {
        minn=min(minn,dis[i]%m);
    }

    printf("%lld\n",minn);
}
int main()
{
    while(~scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&x00,&x11,&y00,&y11))
    {
        init();
        dij();
        solve();
    }
    return 0;
}
