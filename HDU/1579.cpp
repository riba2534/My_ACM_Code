#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
long long dp[620][620][620];//存储结果
long long dfs(long long a,long long b,long long c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
    {
        if(dp[a][b][c])
            return dp[a][b][c];
        else
        {
            dp[a][b][c]=dfs(20,20,20);//更新dp的值
            return dp[a][b][c];
        }
    }
    else if(a<b&&b<c)
    {
        if(dp[a][b][c])
            return dp[a][b][c];
        else
        {
            dp[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);//更新dp的值
            return dp[a][b][c];
        }
    }
    else
    {
        if(dp[a][b][c])
            return dp[a][b][c];
        else
        {
            dp[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);//更新dp的值
            return dp[a][b][c];
        }
    }
}
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c))
    {
        if(a==-1&&b==-1&&c==-1)return 0;
        if(a>0&&b>0&&c>0&&(a>20||b>20||c>20))
            printf("w(%lld, %lld, %lld) = 1048576\n",a,b,c);
        else
            printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,dfs(a,b,c));
    }
    return 0;
}
