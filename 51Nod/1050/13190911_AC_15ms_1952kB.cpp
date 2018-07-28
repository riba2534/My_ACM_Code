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
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const ll N=50000+10;
ll a[N],n;
ll maxnum(ll a[])
{
    ll maxx=0,ans=0;
    for(ll i=1; i<=n; i++)
    {
        ans+=a[i];
        if(ans<0)ans=0;
        maxx=max(maxx,ans);
    }
    return maxx;
}
int main()
{
    ll sum=0;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    ll ans1=maxnum(a);
    for(ll i=1; i<=n; i++)
        a[i]=-a[i];
    ll ans2=maxnum(a);
    printf("%lld\n",max(ans1,sum+ans2));
    return 0;
}
