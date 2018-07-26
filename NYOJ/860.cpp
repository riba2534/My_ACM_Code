 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int weight[2005],value[2005];
int dp[50005];
int main()
{
    int n,w;
    while(~scanf("%d %d",&n,&w))
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&weight[i],&value[i]);
            sum+=value[i];
        }
        mem(dp,0x3f);
        dp[0]=0;
        for(int i=0; i<n; i++)
            for(int j=sum; j>=value[i]; j--)
                dp[j]=min(dp[j],dp[j-value[i]]+weight[i]);
        for(int i=sum; i>=0; i--)
        {
            if(dp[i]<=w)
            {
                printf("%d\n",i);
                break;
            }
        }

    }

    return 0;
}

        