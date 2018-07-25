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
ll dp[25][25];
void init()
{
    mem(dp,0);
    dp[0][0]=1;
    for(ll i=1; i<=20; i++)
        for(ll j=0; j<=9; j++)
            for(ll k=0; k<=9; k++)
                if(!(j==4&&k==9))
                    dp[i][j]+=dp[i-1][k];
}
ll bit[25];
ll solve(ll n)
{
    ll ans=0,len=0;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    bit[len+1]=0;
    for(ll i=len; i>=1; i--)
    {
        for(ll j=0; j<bit[i]; j++)
            if(!(j==9&&bit[i+1]==4))
            {
                ans+=dp[i][j];
                //printf("dp[%lld]%lld]=%lld\n",i,j,dp[i][j]);
            }
        if(bit[i+1]==4&&bit[i]==9)
            break;
    }
    return ans;
}
int main()
{
    ll t,n;
    init();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",n+1-solve(n+1));
    }
    return 0;
}
