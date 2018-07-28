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
#define N 110
#define inf 9999999
#define ll long long
using namespace std;
int n,m,ans,cnt;
int map[N][N],dis[N][N];
int vis[N][N],path[N];
void init()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			dis[i][j]=inf;
			vis[i][j]=0;
		}
}
void record(int i,int j)
{
	if(vis[i][j])
	{
		record(i,vis[i][j]);
		record(vis[i][j],j);
	}
	else
		path[cnt++]=j;
}
void floyd()
{
	ans=inf;
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<k; i++)
			for(int j=i+1; j<k; j++)
				if(ans>dis[i][j]+map[i][k]+map[k][j])
				{
					ans=dis[i][j]+map[i][k]+map[k][j];
					cnt=0;
					path[cnt++]=i;
					record(i,j);
					path[cnt++]=k;
				}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					vis[i][j]=k;
				}
	}
}
int main()
{
	int u,v,w;
	while(~scanf("%d",&n)&&n!=-1)
	{
		scanf("%d",&m);
		init();
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if(w<dis[u][v])
				dis[u][v]=dis[v][u]=w;
		}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				map[i][j]=dis[i][j];
		floyd();
		if(ans==inf)
			puts("No solution.");
		else
		{
			printf("%d",path[0]);
			for(int i=1; i<cnt; i++)
				printf(" %d",path[i]);
			puts("");
		}
	}
	return 0;
}
