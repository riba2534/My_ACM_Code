#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const ll N=1e5+20;
ll n,m;
ll a[N],b[N];
ll judge(ll x)
{
    for(ll i=1; i<=n; i++)b[i]=a[i];
    ll j=n;
    for(ll i=1; i<=m; i++)
    {
        ll w=x;
        while(b[j]==0)
        {
            j--;
            if(j==0) return 1;
        }
        w-=j;
        if(w<=0)return 0;
        while(w>=b[j])
        {
            w-=b[j];
            j--;
            if(j==0)return 1;
            while(b[j]==0)
            {
                j--;
                if(j==0)return 1;
            }
        }
        b[j]-=w;
        while(b[j]==0)
        {
            j--;
            if(j==0) return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    ll l=0,r=1e18;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
