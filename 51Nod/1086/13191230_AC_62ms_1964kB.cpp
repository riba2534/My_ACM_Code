#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const ll N=50000+10;
ll dp[N],v;
ll num[N],weight[N],value[N];
void bag01(ll c,ll w)
{
    for(ll i=v; i>=c; i--)
        dp[i]=max(dp[i],dp[i-c]+w);
}
void bagall(ll c,ll w)
{
    for(ll i=c; i<=v; i++)
        dp[i]=max(dp[i],dp[i-c]+w);
}
void multbag(ll c,ll w,ll n)
{
    if(c*n>=v)
    {
        bagall(c,w);
        return;
    }
    ll k=1;
    while(k<=n)
    {
        bag01(k*c,k*w);
        n-=k;
        k*=2;
    }
    bag01(n*c,n*w);
}
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&v);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld",&weight[i],&value[i],&num[i]);
    }
    for(ll i=1; i<=n; i++)
        multbag(weight[i],value[i],num[i]);
    printf("%lld\n",dp[v]);
    return 0;
}



        