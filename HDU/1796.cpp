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
ll a[12],cnt,n,m,ans;
ll get_lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}
void dfs(ll th,ll now,ll step)
{
    if(step>cnt)
        return;
    ll lcm=get_lcm(a[th],now);
    if(step&1)
        ans+=(n-1)/lcm;
    else
        ans-=(n-1)/lcm;
    for(ll p=th+1; p<cnt; p++)
        dfs(p,lcm,step+1);
}
int main()
{
    ll x;
    while(~scanf("%lld%lld",&n,&m))
    {
        cnt=0;
        for(ll i=1; i<=m; i++)
        {
            scanf("%lld",&x);
            if(x)
                a[cnt++]=x;
        }
        ans=0;
        for(ll i=0; i<cnt; i++)
            dfs(i,a[i],1);
        printf("%lld\n",ans);
    }
    return 0;
}
