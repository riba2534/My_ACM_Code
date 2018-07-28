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
#define N 101000
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll sum[N<<2],lazy[N<<2];
void pushup(ll rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(ll rt,ll m)
{
	if(lazy[rt])
	{
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		sum[rt<<1]+=lazy[rt]*(m-(m>>1));
		sum[rt<<1|1]+=lazy[rt]*(m>>1);
		lazy[rt]=0;
	}
}
void build(ll l,ll r,ll rt)
{
	lazy[rt]=0;
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		return;
	}
	ll m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(ll L,ll R,ll c,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
	{
		lazy[rt]+=c;
		sum[rt]+=(ll)c*(r-l+1);
		return;
	}
	pushdown(rt,r-l+1);
	ll m=(l+r)>>1;
	if(L<=m) update(L,R,c,lson);
	if(m<R) update(L,R,c,rson);
	pushup(rt);
}
ll query(ll L,ll R,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
		return sum[rt];
	pushdown(rt,r-l+1);
	ll m=(l+r)>>1;
	ll ans=0;
	if(L<=m)
		ans+=query(L,R,lson);
	if(R>m)
		ans+=query(L,R,rson);
	return ans;
}
int main()
{
	ll n,m,a,b,c;
	char s[5];
	scanf("%lld%lld",&n,&m);
	build(1,n,1);
	while(m--)
	{
		scanf("%s",s);
		if(s[0]=='Q')
		{
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",query(a,b,1,n,1));
		}
		if(s[0]=='C')
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
	}
	return 0;
}
