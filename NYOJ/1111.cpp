 
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
#define N 220
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int a[N],b[N];
int dp[N][N];
int main()
{
	int t,n,q=1;
	scanf("%d",&t);
	while(t--)
	{
		mem(b,0);
		mem(dp,0);
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		for(int i=1; i<=n; i++) scanf("%d",&b[i]);
		for(int l=1; l<=n; l++)
			for(int i=1; i<=n-l+1; i++)
			{
				int j=i+l-1;
				dp[i][j]=inf;
				for(int k=i; k<=j; k++)
					dp[i][j]=min(dp[i][j],dp[i][k-1]+a[k]+dp[k+1][j]);
				dp[i][j]+=b[i-1]+b[j+1];
			}
		printf("Case #%d: %d\n",q++,dp[1][n]);
	}
	return 0;
}
        