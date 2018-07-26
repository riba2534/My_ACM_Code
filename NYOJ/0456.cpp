 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[10005];
int dp[50005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        mem(a,0);
        mem(dp,0);
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int v=sum/2;
        for(int i=0; i<n; i++)
            for(int j=v; j>=a[i]; j--)
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        printf("%d\n",sum-2*dp[v]);
    }
    return 0;
}
        