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
const int N=100000+7;
ll x;
int main()
{
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        ll maxx=0,sum=0;
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&x);
            maxx=max(x,maxx);
            sum+=x;
        }
        if(sum-maxx>=maxx-1)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
