#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
int dp[1000][1000];//定义状态
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,v;//个数 和 容量
        scanf("%d %d",&n,&v);
        int a[1010],b[1010];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);//每一个的价值
        for(int i=1; i<=n; i++)
            scanf("%d",&b[i]);//每一个的体积
        mem(dp,0);
        for(int i=1; i<=n; i++)//遍历个数
        {
            for(int j=0; j<=v; j++)//遍历背包容量
            {
                if(b[i]<=j)//可以放进去
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i]]+a[i]);
                else//不能放进去
                    dp[i][j]=dp[i-1][j];
            }
        }
        printf("%d\n",dp[n][v]);
    }
    return 0;
}
