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
long long dp[40][40];
char map[40][40];
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<n; j++)
                map[i][j]-='0';
        }
        mem(dp,0);
        dp[0][0]=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(map[i][j]==0||dp[i][j]==0)
                    continue;
                if(i+map[i][j]<n)
                    dp[i+map[i][j]][j]+=dp[i][j];
                if(j+map[i][j]<n)
                    dp[i][j+map[i][j]]+=dp[i][j];
            }
        printf("%lld\n",dp[n-1][n-1]);

    }

    return 0;
}
