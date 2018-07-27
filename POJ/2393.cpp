#include<cstdio>
#include<cstring>
#include<string>
#include<set>
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
#define N (1010)
#define ll long long
using namespace std;
int main()
{
    ll n,s,minc = inf;
    scanf("%lld%lld",&n, &s);
    ll sum = 0;
    while(n --)
    {
        ll c, y;
        scanf("%lld%lld",&c, &y);
        c=min(c,minc+s);
        minc = c;
        sum +=c*y;
    }
    printf("%lld\n", sum);
    return 0;
}
