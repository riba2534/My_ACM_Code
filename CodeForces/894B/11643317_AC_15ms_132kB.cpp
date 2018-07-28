#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000+20;
const ll mod=1e9+7;
ll pow_mod(ll a,ll b,ll c)
{
    a%=c;
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k==-1&&(n+m)&1) 
        puts("0");
    else
        printf("%lld\n",pow_mod(pow_mod(2,n-1,mod),m-1,mod));
    return 0;
}