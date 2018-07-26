 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100];
void init()
{
    f[0]=2;
    f[1]=3;
    for(ll i=2; i<95; i++)
        f[i]=f[i-1]+f[i-2];
}
int main()
{
    init();
    ll n;
    while(~scanf("%lld",&n))
    {
        ll flag=1;
        for(ll i=0; i<95&&f[i]<=n; i++)
            if(f[i]==n)
            {
                flag=0;
                break;
            }
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}
        