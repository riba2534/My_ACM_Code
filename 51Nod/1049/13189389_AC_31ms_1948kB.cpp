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
const ll N=50000+7;
ll n,a[N];
int main()
{
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    ll ans=0,maxx=0;
    for(ll i=1; i<=n; i++)
    {
        ans+=a[i];
        maxx=max(maxx,ans);
        if(ans<0)ans=0;
    }
    printf("%lld\n",maxx);
    return 0;
}
