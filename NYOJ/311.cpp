 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=2000+20;
const int M=50005+10;
#define inf 0x3f3f3f3f
int v[N],w[N];
int dp[M];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&w[i],&v[i]);
        mem(dp,-inf);
        dp[0]=0;
        for(int i=1; i<=n; i++)
            for(int j=w[i]; j<=m; j++)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        if(dp[m]<0)
            puts("NO");
        else
            printf("%d\n",dp[m]);
    }
    return 0;
}

        