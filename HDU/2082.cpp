#include <stdio.h>
#include <string.h>
int dp[55][55];
int w[30],num[30];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        for(int i=1; i<=26; i++)
        {
            w[i]=i;
            scanf("%d",&num[i]);
        }
        dp[0][0]=1;
        for(int i=1; i<=26; i++)
            for(int j=0; j<=50; j++)
                for(int k=0; k<=num[i]&&k*w[i]<=j; k++)//k代表字母的数量,w[i]代表不同的字母
                    dp[i][j]+=dp[i-1][j-k*w[i]];
        int ans=0;
        for(int i=1; i<=50; i++)
            ans+=dp[26][i];
        printf("%d\n",ans);
    }
    return 0;
}