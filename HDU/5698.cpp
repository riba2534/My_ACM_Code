#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=200000+20;
ll fac[N]= {1,1},inv[N]= {1,1},f[N]= {1,1};
/*
fac[i]:i的阶乘
inv[i]:i的阶乘的逆元
f[i]:i的逆元
*/
ll C(ll a,ll b)//除以一个数等于乘这个数的逆元
{
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
void init()
{
    for(ll i=2; i<N; i++)
    {
        fac[i]=fac[i-1]*i%mod;
        f[i]=(mod-mod/i)*f[mod%i]%mod;
        inv[i]=inv[i-1]*f[i]%mod;
    }
}

int main()
{
    ll n,m;
    init();
    while(cin>>n>>m)
        cout<<C(m+n-4,m-2)<<endl;
    return 0;
}
