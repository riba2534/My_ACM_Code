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
char s[N][12];
int map[N][N];
int dis[N],vis[N];
int n,m,w;
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
		sum+=dis[k];
		for(int j=1; j<=n; j++)
		{
			if(!vis[j]&&map[k][j]<dis[j])
				dis[j]=map[k][j];
		}
	}
	printf("%d\n",sum+m);
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&w))
	{
		for(int i=1; i<=n; i++)
			scanf("%s",s[i]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				if(i==j)map[i][j]=inf;
				else
				{
					int cnt=0;
					for(int k=0; k<m; k++)
						if(s[i][k]!=s[j][k])
							cnt++;
					map[i][j]=map[j][i]=min(cnt*w,m);
				}
			}
			Prim();
	}
	return 0;
}
