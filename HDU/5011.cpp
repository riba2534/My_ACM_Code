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
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define ll long long
using namespace std;
int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        ll sum=0,x,flag=0;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&x);
            sum^=x;
            if(sum==0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            puts("Lose");
        else
            puts("Win");
    }
    return 0;
}
