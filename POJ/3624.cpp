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
int dp[32000];
struct node
{
	int weight,value;
} a[32000];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		mem(dp,0);
		for(int i=0; i<n; i++)
			scanf("%d%d",&a[i].weight,&a[i].value);
		for(int i=0; i<n; i++)
			for(int j=m; j>=a[i].weight; j--)
				dp[j]=max(dp[j],dp[j-a[i].weight]+a[i].value);
		printf("%d\n",dp[m]);
	}
	return 0;
}
