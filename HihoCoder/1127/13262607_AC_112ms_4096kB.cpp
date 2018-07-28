#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e3+10;
int n,m,match[N],vis[N];
int e[N][N];
int dfs(int u)
{
	for(int i=1;i<=n;i++)
	{
		if(e[u][i]&&!vis[i])
		{
			vis[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int query()
{
	mem(match,0);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		mem(vis,0);
		if(dfs(i))sum++;
	}
	return sum;
}
int main()
{
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
	}
	int ans=query()/2;
	printf("%d\n%d\n",ans,n-ans);
	return 0;
}