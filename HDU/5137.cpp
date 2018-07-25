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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 1200
#define M 1000000
#define ll long long
using namespace std;
int map[50][50];
int vis[50];
int dis[50];
int n,m;
void spfa(int p)
{
    queue<int>q;
    mem(vis,0);
    for(int i=1; i<=n; i++)
        dis[i]=inf;
    vis[1]=1;
    dis[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int k=q.front();
        vis[k]=0;
        q.pop();
        for(int i=1; i<=n; i++)
        {
            int w=map[k][i];
            if(i==p||k==p)
                w=inf;
            if(dis[k]+w<dis[i])
            {
                dis[i]=dis[k]+w;
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
}
int main()
{
    int a,b,c;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        mem(map,inf);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]>c)
                map[a][b]=c;
            if(map[b][a]>c)
                map[b][a]=c;
        }
        int maxx=0;
        for(int i=2; i<n; i++)
        {
            spfa(i);
            maxx=max(maxx,dis[n]);
        }
        if(maxx==inf)
            puts("Inf");
        else
            printf("%d\n",maxx);
    }
    return 0;
}




