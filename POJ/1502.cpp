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
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
int map[N][N],dis[N],vis[N];
int n;
void dijkstra(int n)
{
    int k,min;
    for(int i=1; i<=n; i++)
    {
        dis[i]=map[1][i];
        vis[i]=0;
    }
    for(int i=1; i<=n; i++)//遍历顶点
    {
        k=0;
        min=inf;
        for(int j=1; j<=n; j++)
            if(vis[j]==0&&dis[j]<min)
            {
                min=dis[j];
                k=j;
            }
        vis[k]=1;
        for(int j=1; j<=n; j++)
            if(vis[j]==0&&dis[k]+map[k][j]<dis[j])
                dis[j]=dis[k]+map[k][j];//如果找到了通路就加上
    }
    return;
}
int main()
{

    while(~scanf("%d",&n))
    {
        int maxx=0;
        char s[10];
        mem(map,inf);
        mem(vis,0);
        mem(dis,0);
        for(int i=1; i<=n-1; i++)
        {
            for(int j=1; j<=i; j++)
            {
                scanf("%s",s);
                if(strcmp(s,"x")==0)
                    map[i+1][j]=map[j][i+1]=inf;
                else
                    map[i+1][j]=map[j][i+1]=atoi(s);
            }
        }
        for(int i=1; i<=n; i++)
            map[i][i]=0;
        dijkstra(n);
        for(int i=1; i<=n; i++)
            if(dis[i]>maxx)
                maxx=dis[i];
        printf("%d\n",maxx);
    }
    return 0;
}
