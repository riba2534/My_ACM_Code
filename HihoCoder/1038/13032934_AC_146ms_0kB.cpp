#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=500+20;
const int M=1e5+10;
int v[N],w[N];
int dp[M];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&w[i],&v[i]);
    mem(dp,0);
    for(int i=1; i<=n; i++)
        for(int j=m; j>=w[i]; j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    printf("%d\n",dp[m]);
    return 0;
}
