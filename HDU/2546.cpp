#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);//菜的种类
        if(n==0)return 0;
        int a[1001];//价格
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
            sort(a,a+n);
        int m;//卡上余额
        scanf("%d",&m);
        int dp[1000];
        mem(dp,0);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        m-=5;//先用5块钱把最贵的菜买了
        int i,j;
        for(i=0;i<n-1;i++)
        {
            for(j=m;j>=a[i];j--)
            {
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        printf("%d\n",m+5-dp[m]-a[n-1]);//把减得五块加回来，再减去花费的再减去最大的菜价
    }
    return 0;
}
