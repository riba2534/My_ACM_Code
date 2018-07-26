 
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1010000)
#define ll long long
using namespace std;
ll a[1010];
int main()
{
	ll n,m,sum,st,ed;
	while(~scanf("%lld%lld",&m,&n))
	{
		ll maxx=-inf;
		for(ll i=0; i<m; i++)
			scanf("%lld",&a[i]);
		for(ll i=0; i<m; i++)
		{
			sum=0;
			for(ll j=i; j<i+n; j++)
			{
				if(j>=m)
					sum+=a[j%m];
				else
					sum+=a[j];
			}
			if(sum>maxx)
			{
				maxx=sum;
				st=i;
				ed=(st+n-1)%m;
			}
		}
		printf("%lld %lld %lld\n",maxx,st+1,ed+1);
	}


	return 0;
}
        