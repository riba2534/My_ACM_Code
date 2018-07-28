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
int dp[110][110],sum[110],n,x;
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		mem(dp,-inf);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&x);
			sum[i]=sum[i-1]+x;
			dp[i][i]=x;
		}
		for(int l=1; l<=n-1; l++) //枚举间隔
			for(int i=1; i+l<=n; i++) //区间起点
			{
				int j=i+l;//区间终点
				for(int k=i; k<j; k++) //枚举区间
					dp[i][j]=max(dp[i][j],(sum[j]-sum[i-1])-min(dp[i][k],dp[k+1][j]));
				dp[i][j]=max(dp[i][j],(sum[j]-sum[i-1]));
			}
		printf("%d\n",2*dp[1][n]-sum[n]);
	}
}


