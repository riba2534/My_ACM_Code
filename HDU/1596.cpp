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
double map[N][N],dis[N];
int n,vis[N];
void dijkstra(int st,int ed)
{
    int k,flag=0;
    for(int i=1; i<=n; i++)
    {
        dis[i]=map[st][i];
        vis[i]=0;
    }
    vis[st]=1;
    for(int i=1; i<n; i++)
    {
        k=0;
        double maxx=0;
        for(int j=1; j<=n; j++)
            if(vis[j]==0&&dis[j]>maxx)
            {
                maxx=dis[j];
                k=j;
            }
        if(fabs(maxx)<=10e-6)
        {
            flag=1;
            break;
        }
        vis[k]=1;
        for(int j=1; j<=n; j++)
            if(vis[j]==0&&dis[k]*map[k][j]>dis[j])
                dis[j]=dis[k]*map[k][j];
    }
    if(flag)puts("What a pity!");
    else printf("%.3lf\n",dis[ed]);
    return;
}
int main()
{
    while(~scanf("%d",&n))
    {
        mem(map,0);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%lf",&map[i][j]);
        int t,st,ed;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&st,&ed);
            dijkstra(st,ed);
        }
    }
    return 0;
}
