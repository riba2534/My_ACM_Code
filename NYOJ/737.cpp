 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=200+5;
int a[N],dp[N][N],sum[N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        mem(dp,0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int l=1; l<=n; l++)
        {
            for(int i=0; i+l<=n; i++)
            {
                int j=i+l;
                dp[i][j]=inf;
                for(int k=i; k<=j; k++)
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]+sum[j]-sum[i-1]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
        