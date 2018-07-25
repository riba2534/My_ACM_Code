#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 500010
#define M 1000000
#define ll long long
using namespace std;
ll n;
struct node
{
    ll p,q;
    ll num;
} zz[N];

int main()
{
    ll t,a,b;
    while(scanf("%lld",&n)&&n)
    {
        ll len=0;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld%lld%lld",&t,&a,&b);
            if(t==1)
            {
                zz[len].p=a;
                zz[len].q=b;
                zz[len++].num=1;
            }
            else if(t==0)
            {
                ll maxx=-inf;
                for(ll j=0; j<len; j++)
                {
                    if(zz[j].num)
                    {
                         maxx=max(maxx,a*zz[j].p+b*zz[j].q);
                    }

                }
                printf("%lld\n",maxx);
            }
            else if(t==-1)
            {
                for(ll j=0; j<len; j++)
                    if(zz[j].p==a&&zz[j].q==b&&zz[j].num)
                    {
                        zz[j].num=0;
                        break;
                    }
            }
        }
    }
    return 0;
}