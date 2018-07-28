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
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const ll N=200005;
ll MAX[N<<2],MIN[N<<2];
void pushup(ll rt)
{
	MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
	MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
}
void build(ll l,ll r,ll rt)
{
	if(l==r)
	{
		scanf("%lld",&MAX[rt]);
		MIN[rt]=MAX[rt];
		return;
	}
	ll m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(ll p,ll add,ll l,ll r,ll rt)
{
	if(l==r)
	{
		MAX[rt]=add;
		MIN[rt]=add;
		return;
	}
	ll m=(l+r)>>1;
	if(p<=m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}
ll query_max(ll L,ll R,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
		return MAX[rt];
	ll m=(l+r)>>1;
	ll ans=-inf;
	if(L<=m)
		ans=max(ans,query_max(L,R,lson));
	if(R>m)
		ans=max(ans,query_max(L,R,rson));
	return ans;
}
ll query_min(ll L,ll R,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
		return MIN[rt];
	ll m=(l+r)>>1;
	ll ans=inf;
	if(L<=m)
		ans=min(ans,query_min(L,R,lson));
	if(R>m)
		ans=min(ans,query_min(L,R,rson));
	return ans;
}
int main()
{
	ll t,n,q,m,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n=1<<n;
		build(1,n,1);
		scanf("%lld",&m);
		while(m--)
		{
			scanf("%lld%lld%lld",&q,&a,&b);
			a++;
			if(q==1)
			{
				b++;
				ll minn=query_min(a,b,1,n,1);
				ll maxx=query_max(a,b,1,n,1);
				if(maxx<=0)
					printf("%lld\n",maxx*maxx);
				else if(minn>=0)
					printf("%lld\n",minn*minn);
				else
					printf("%lld\n",minn*maxx);
			}
			else if(q==2)
				update(a,b,1,n,1);
		}
	}
}
