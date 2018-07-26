 
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
#define N 100000+10
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
char s[100];
ll sum[100][100];
ll len,maxx,n,m;
void dfs(ll i,ll ans,ll step)
{
	if(step==m)
	{
		maxx=max(ans,maxx);
		return;
	}
	for(ll j=1; j<=len-m+1; j++)
		if(i+j<=len)
			dfs(i+j,ans*sum[i+1][i+j],step+1);
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		maxx=0;
		scanf("%s%lld",s+1,&m);
		len=strlen(s+1);
		for(ll i=1; i<=len; i++)
		{
			sum[i][i]=s[i]-'0';
			for(ll j=i+1; j<=len; j++)
				sum[i][j]=sum[i][j-1]*10+s[j]-'0';
		}
		dfs(0,1,0);
		printf("%lld\n",maxx);
	}
	return 0;
}
        