#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
int main()
{
    ll t,n,q=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1||n==2)
            printf("Case #%lld: 1\n",q++);
        else
        {
            ll y=(ll)sqrt(2.0*n);
            if((y*(y+1))/2>n)
                y--;
            printf("Case #%lld: %lld\n",q++,(y*(y+1))/2);
        }
    }
    return 0;
}
