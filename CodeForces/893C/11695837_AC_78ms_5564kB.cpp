#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const ll N=1e5+20;
ll n,m;
ll pre[N],a[N];
void init()
{
    for(ll i=1; i<=n; i++)
        pre[i]=i;
}
ll find(ll x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=find(pre[x]);
        return pre[x];
    }
}
ll mix(ll x,ll y)
{
    ll fx=find(x);
    ll fy=find(y);
    if(fx!=fy)
    {
        pre[fy]=fx;
        return 1;
    }
    return 0;
}
int main()
{
    ll x,y;
    scanf("%lld%lld",&n,&m);
    init();
    for(ll i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    for(ll i=1; i<=m; i++)
    {
        scanf("%lld%lld",&x,&y);
        mix(x,y);
    }
    map<ll,ll>mp;
    for(ll i=1; i<=n; i++)
    {
        pre[i]=find(i);
        if(mp.find(pre[i])!=mp.end())
            mp[pre[i]]=min(mp[pre[i]],a[i]);
        else
            mp[pre[i]]=a[i];
    }
    map<ll,ll>::iterator it;
    ll sum=0;
    for(it=mp.begin(); it!=mp.end(); it++)
        sum+=(*it).second;
    printf("%lld\n",sum);
    return 0;
}