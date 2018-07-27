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
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 1000007
#define N 50000+50
#define M 100000+50
#define ll long long
using namespace std;
ll t,n,m,len;
ll first[N],dis[N],vis[N];
ll num[N];
struct node
{
	ll u,v,w,next;
} G[M];
void add_edge(ll u,ll v,ll w)
{
	G[len].v=v;
	G[len].w=w;
	G[len].next=first[u];
	first[u]=len++;
}
void spfa(ll st)
{
	for(ll i=1; i<=n; i++)
	{
		dis[i]=inf;
		vis[i]=0;
	}
	queue<ll>q;
	dis[st]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		vis[st]=0;
		for(ll i=first[st]; ~i; i=G[i].next)
		{
			ll v=G[i].v,w=G[i].w;
			if(dis[v]>dis[st]+w)
			{
				dis[v]=dis[st]+w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		len=1;
		mem(first,-1);
		ll x,y,z;
		scanf("%lld%lld",&n,&m);
		for(ll i=1; i<=n; i++)
			scanf("%lld",&num[i]);
		for(ll i=1; i<=m; i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			add_edge(x,y,z);
			add_edge(y,x,z);
		}
		spfa(1);
		ll sum=0;
		for(ll i=2; i<=n; i++)
		{
			if(dis[i]==inf)
			{
				sum=inf;
				break;
			}
			else
				sum+=dis[i]*num[i];
		}
		if(sum==inf)
			printf("No Answer\n");
		else
			printf("%lld\n",sum);
	}
	return 0;
}
