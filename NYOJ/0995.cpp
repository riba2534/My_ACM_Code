 
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
int n,v;
int a[100];
int dp[100000+50];
int main()
{
	while(~scanf("%d%d",&n,&v)&&(n||v))
	{
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		mem(dp,inf);
		dp[0]=0;
		for(int i=0; i<n; i++)
			for(int j=a[i]; j<=v; j++)
				dp[j]=min(dp[j],dp[j-a[i]]+1);
		printf("%d\n",dp[v]);
	}
	return 0;
}
        