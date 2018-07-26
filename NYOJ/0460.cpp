 
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
#define N 300
#define ll long long
using namespace std;
int a[N],dp[N][N];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		mem(dp,0);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			a[i+n]=a[i];
		}
		for(int v=1; v<2*n; v++)
			for(int i=1; i<2*n-v; i++)
			{
				int j=i+v;
				for(int k=i; k<j; k++)
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		int maxx=0;
		for(int i=1; i<=n; i++)
			maxx=max(dp[i][i+n-1],maxx);
		printf("%d\n",maxx);
	}
	return 0;
}
        