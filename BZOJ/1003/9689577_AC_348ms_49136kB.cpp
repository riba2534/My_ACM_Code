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
ll n,m,k,e;
ll vis[N],first[N],len;
int dis[N];
ll flag[N][N];//flag[x][i]代表x点在第i天不能用
ll dp[N];//dp[i]表示从第1天到第i天的最小花费
ll t[N][N];//t[i][j]表示从第i天到第j天，从第一个点走到第m个点的最短路径
struct node
{
	ll u,v,w,next;
} G[N*N];
void add_edge(ll u,ll v,ll w)
{
	G[len].v=v,G[len].w=w;
	G[len].next=first[u];
	first[u]=len++;
}
ll spfa(ll st,ll ed)
{
	ll book[N];
	mem(dis,inf);
	mem(book,0);
	mem(vis,0);
	for(ll i=1; i<=m; i++)
		for(ll j=st; j<=ed; j++)
			if(flag[i][j])
				book[i]=1;//第i个点不能走
	dis[1]=0;
	vis[1]=1;
	queue<ll>q;
	q.push(1);
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		vis[st]=0;
		for(ll i=first[st]; i!=-1; i=G[i].next)
		{
			ll v=G[i].v,w=G[i].w;
			if(!book[v]&&dis[v]>dis[st]+w)
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
	return dis[m];
}
void solve()
{
	for(ll i=1;i<=n;i++)
	{
		dp[i]=t[1][i]*i;//长度*单位长度的花费=花费
		for(ll j=0;j<i;j++)
			dp[i]=min(dp[i],dp[j]+t[j+1][i]*(i-j)+k);
	}
}
int main()
{
	ll x,y,z;
	mem(first,-1);
	mem(flag,0);
	len=1;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&e);
	for(ll i=1; i<=e; i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	ll d,p,a,b;
	scanf("%lld",&d);
	for(ll i=1; i<=d; i++)
	{
		scanf("%lld%lld%lld" ,&p,&a,&b);
		for(ll j=a; j<=b; j++)
			flag[p][j]=1;
	}
	for(ll i=1; i<=n; i++)
		for(ll j=1; j<=n; j++)
			t[i][j]=spfa(i,j);//找出满足从i天到j天的从1~m的最短路
	solve();
	printf("%lld\n",dp[n]);
	return 0;
}
