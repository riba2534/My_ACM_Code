#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10007
#define M 1000000+10
#define ll long long
using namespace std;
const ll N=1e5+20;
ll a[N],b[N];
int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        mem(b,-1);
        for(ll i=0; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }
        ll ans=0;
        for(ll i=n; i>=0; i--)//从最大的数到最小的数开始枚举
        {
            ll p=0;
            if(b[i]==-1)
            {
                for(ll j=0; (1<<j)<i; j++)
                {
                    if((i&(1<<j))==0)//找到为1的这一位的数加上
                        p+=(1<<j);
                }
                ans+=(i^p)*2;
                b[p]=i;//把相对应的数存一下
                b[i]=p;
            }
        }
        printf("%lld\n",ans);
        for(ll i=0; i<n; i++)
        {
            printf("%lld ",b[a[i]]);
        }
        printf("%lld\n",b[a[n]]);
    }
    return 0;
}
