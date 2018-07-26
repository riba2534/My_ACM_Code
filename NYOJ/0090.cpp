 
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
#define ll long long
using namespace std;
int dp[15][15];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		mem(dp,0);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					dp[i][j]=dp[i][j-1]+1;
				else if(i<j)
					dp[i][j]=dp[i][i];
				else if(i>j)
					dp[i][j]=dp[i-j][j]+dp[i][j-1];
			}
		}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}
        