#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 330
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll n;
char s[100];
ll solve(ll len)
{
	if(len==0) return 0;
	ll l=len;
	ll cnt=0,t=1;
	for(ll i=len; i>=1 && t<n; i--)
	{
		if(cnt+(s[i]-'0')*t<n)
		{
			cnt+=(s[i]-'0')*t;
			if(s[i]!='0')
				l=i;
		}
		else
			break;
		t*=10;
	}
	return solve(l-1)*n+cnt;
}
int main()
{
	scanf("%lld%s",&n,s+1);
	ll len=strlen(s+1);
	printf("%lld\n",solve(len));
	return 0;
}
