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
const ll N=1e3+10;
ll a[N][N],b[N];
int main()
{
    ll n,m;
    scanf("%lld%lld",&m,&n);
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++)
            scanf("%lld",&a[i][j]);
    ll maxx=0;
    for(ll i=1; i<=n; i++)
    {
        mem(b,0);
        for(ll j=i; j<=n; j++)
        {
            ll sum=0;
            for(ll k=1; k<=m; k++)
            {
                b[k]+=a[j][k];
                sum+=b[k];
                if(sum<0)sum=0;
                maxx=max(maxx,sum);
            }
        }
    }
    printf("%lld\n",maxx);
    return 0;
}