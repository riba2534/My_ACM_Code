#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include <map>
#include<iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1000020)
#define ll long long
using namespace std;
ll a[700];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    ll l,n;
    while(~scanf("%lld%lld",&l,&n))
    {
        ll sum=0,ans=0;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        if(sum<l)
            puts("impossible");
        else if(sum==l)
            printf("%lld\n",n);
        else
        {
            sort(a,a+n,cmp);
            for(ll i=0; i<n; i++)
            {
                if(l<=0)break;
                ans++;
                l-=a[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
