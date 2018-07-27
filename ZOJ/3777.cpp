#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=500+50;
int a[20][20],n,m;
int dp[1<<13][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        mem(dp,0);
        dp[0][0]=1;
        for(int i=0; i<(1<<n); i++)
        {
            int cnt=0;
            for(int j=1; j<=n; j++)
            {
                if(i&(1<<(j-1)))
                    cnt++;
            }
            for(int j=1; j<=n; j++)
            {
                if(i&(1<<(j-1)))continue;
                for(int k=0; k<=m; k++)
                {
                    dp[i|(1<<(j-1))][min(a[cnt+1][j]+k,m)]+=dp[i][k];
                }
            }
        }
        if(dp[(1<<n)-1][m]==0)
            puts("No solution");
        else
        {
            int zi=dp[(1<<n)-1][m],mu=1;
            for(int i=1; i<=n; i++)mu*=i;
            int gg=__gcd(zi,mu);
            printf("%d/%d\n",mu/gg,zi/gg);
        }
    }
    return 0;
}