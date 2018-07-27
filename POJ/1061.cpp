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
#define ll long long
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main()
{
	ll x,y,m,n,L,t,p;
	while(~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L))
	{
		ll M=exgcd(n-m,L,t,p);
        if((x-y)%M||m==n)
			puts("Impossible");
		else
		{
			ll s=L/M;
			t=t*((x-y)/M);
			t=(t%s+s)%s;
			printf("%lld\n",t);
		}

	}
	return 0;
}
