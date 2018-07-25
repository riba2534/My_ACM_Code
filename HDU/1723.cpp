#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define N 8
#define M 12357
#define ll long long
using namespace std;
int n,m;
int dp[35];
int solve(int n,int m)
{
    memset(dp,0,sizeof(dp));
    dp[1] = 1;
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= m; j++)
        {
            int k = i + j;
            dp[k] += dp[i];
        }
    return dp[n];
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        printf("%d\n",solve(n,m));
    }
    return 0;
}
