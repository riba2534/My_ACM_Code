#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int value[1000];//价值
int weight[1000];//重量
int num[1000];//数量
int dp[1000005];
int v,m;
void bag01(int c,int w)//01背包
{
    int i;
    for(i=v; i>=c; i--)
    {
        if(dp[i]<dp[i-c]+w)
        {
            dp[i]=dp[i-c]+w;
        }
    }
}
void bagall(int c,int w)//完全背包
{
    int i;
    for(i=c; i<=v; i++)
    {
        if(dp[i]<dp[i-c]+w)
        {
            dp[i]=dp[i-c]+w;
        }
    }
}
void multbag(int c,int w,int n)//多重背包
{
    if(c*n>=v)
    {
        bagall(c,w);
        return ;
    }
    int k=1;
    while(k<=n)
    {
        bag01(k*c,k*w);
        n=n-k;
        k=k*2;
    }
    bag01(n*c,n*w);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,0);

        scanf("%d%d",&v,&m);
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&value[i],&weight[i],&num[i]);
        for(int i=0; i<m; i++)
            multbag(value[i],weight[i],num[i]);
//        for(int i=0; i<m; i++)
//            for(int j=1; j<=num[i]; j++)//把数量展开
//                for(int k=v; k>=value[i]; k--)
//                    dp[k]=max(dp[k],dp[k-value[i]]+weight[i]);
        printf("%d\n",dp[v]);
    }
    return 0;
}
