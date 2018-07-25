#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        if(m<=n-1)
        {
            ll k=n-m-1;
            ll ans=((k*n-k*(k+1)/2)*n+n*n-n-2*k*n+k*(k+1)-m)*2;
            printf("%lld\n",ans);
        }
        else
        {
            ll w=n*(n-1),ans=2*(n*(n-1)-m);
            if(ans<w)
                ans=w;
            printf("%lld\n",ans);
        }
    }
    return 0;
}