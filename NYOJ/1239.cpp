 
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
#define N 8
#define M 12357
#define ll long long
using namespace std;
int t,n;
int dis[500],vis[500];
int map[350][350];
void Prim()
{
	int sum=0;
	mem(vis,0);
	for(int i=1; i<=n-1; i++)
	{
		int k=1,minn=inf;
		for(int j=1; j<=n; j++)
		{
			if(!vis[j]&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		}
		vis[k]=1;
		for(int j=1; j<=n; j++)
			if(!vis[j]&&map[k][j]<dis[j])
				dis[j]=map[k][j];
	}
	for(int i=1; i<=n; i++)
		sum+=dis[i];
	printf("%d\n",sum);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",&dis[i]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&map[i][j]);
		Prim();
	}
	return 0;
}
        