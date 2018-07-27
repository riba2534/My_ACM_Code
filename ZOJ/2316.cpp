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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 100+20
#define M 1000000+10
#define ll long long
using namespace std;
ll x[100010];
int main()
{
    ll t,n,m,a,b,maxx;
    scanf("%lld",&t);
    while(t--)
    {
        mem(x,0);
        maxx=0;
        ll sum=0;
        scanf("%lld%lld",&n,&m);
        for(ll i=0;i<m;i++)
        {
            scanf("%lld%lld",&a,&b);
            x[a]++;
            x[b]++;
            maxx=max(max(a,b),maxx);
        }
        for(ll i=0;i<=maxx;i++)
        {
            sum+=x[i]*x[i];
        }
        printf("%lld\n",sum);
        if(t)
            printf("\n");
    }
    return 0;
}