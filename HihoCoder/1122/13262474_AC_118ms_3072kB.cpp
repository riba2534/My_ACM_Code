#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e5+10;
int n,m,match[N],vis[N];
vector<int>e[N];
int dfs(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(!vis[v])
		{
			vis[v]=1;
			if(match[v]==-1||dfs(match[v]))
			{
				match[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int u,v;
	mem(match,-1);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		mem(vis,0);
		if(dfs(i))
			sum++;
	}
	printf("%d\n",sum/2);
	
	return 0;
}