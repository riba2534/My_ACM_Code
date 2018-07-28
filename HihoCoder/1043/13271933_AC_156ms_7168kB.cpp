#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e6+10;
int dp[N],c[N],v[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>c[i]>>v[i];
    mem(dp,0);
    for(int i=1; i<=n; i++)
    {
        for(int j=c[i]; j<=m; j++)
            dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
    }
    cout<<dp[m]<<endl;
    return 0;
}
