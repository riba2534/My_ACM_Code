#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int value[1000];
int weight[1000];
int dp[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int v,wa,wb;
        scanf("%d%d",&wa,&wb);
        v=wb-wa;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d%d",&value[i],&weight[i]);
        for(int i=0; i<=v; i++)
            dp[i]=10000000;
        dp[0]=0;
        for(int i=0; i<n; i++)
            for(int j=weight[i]; j<=v; j++)
                dp[j]=min(dp[j],dp[j-weight[i]]+value[i]);
        if(dp[v]==10000000)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);




    }
    return 0;
}
