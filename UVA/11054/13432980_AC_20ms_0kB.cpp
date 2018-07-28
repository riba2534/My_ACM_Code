#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=2e5+10;
int main()
{
    ll n,x,ans=0,last=0;
    while(scanf("%lld",&n)&&n)
    {
        ans=0,last=0;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&x);
            ans+=abs(last);
            last+=x;
        }
        printf("%lld\n",ans);
    }
    
    
    return 0;
}
