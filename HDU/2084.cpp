#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[101][101];
int dp[101][101];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        mem(a,0);
        mem(dp,0);
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=i; j++)
                scanf("%d",&a[i][j]);
        for(int i=n; i>=1; i--)
            for(int j=1; j<=i; j++)
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
