#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y),t;
	t=x;
	x=y;
	y=t-(a/b)*y;
	return g;
}
int main()
{
	ll a,b,c,x,y;
	cin>>a>>b>>c;
		c=-c;
	ll m=exgcd(a,b,x,y);
	if(c%m==0)
		printf("%lld %lld\n",x*c/m,y*c/m);
	else puts("-1");
}