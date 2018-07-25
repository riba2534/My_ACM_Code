#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1010)
#define ll long long
using namespace std;
int map[N][N];
int dp[N][N];
int main()
{
    int t,n,m,q=1;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,0);mem(map,0);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+map[i][j];
            }
        }
        printf("Scenario #%d:\n%d\n\n",q++,dp[n][m]);
    }
    return 0;
}
