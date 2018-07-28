#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
typedef long long ll;
using namespace std;
const ll N=1e5+20;
vector<ll>G[N];
ll color[N],vis[N];
void dfs(ll rt)
{
	vis[rt]=1;
	if(color[rt]==0)
		color[rt]=1;
	for(ll i=0; i<G[rt].size(); i++)
	{
		ll v=G[rt][i];
		if(!vis[v])
		{
			if(color[rt]==1)
				color[v]=2;
			else
				color[v]=1;
			vis[v]=1;
			dfs(v);
		}
	}
}
int main()
{
	ll n,x,y;
	scanf("%lld",&n);
	for(ll i=0; i<n-1; i++)
	{
		scanf("%lld%lld",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	ll a=0,b=0;
	for(ll i=1; i<=n; i++)
		if(color[i]==1)
			a++;
		else
			b++;
	printf("%lld\n",a*b-(n-1));
	return 0;
}
