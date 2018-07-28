#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const ll N=1e5+20;
const ll inf=INFINITY;
ll n,m;
ll vis[N],a[N];
vector<ll>G[N];
ll minn;
void dfs(ll x)
{
    vis[x]=1;
    minn=min(minn,a[x]);
    for(ll i=0; i<(ll)G[x].size(); i++)
    {
        ll to=G[x][i];
        if(!vis[to])
            dfs(to);
    }
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    ll x,y;
    for(ll i=1; i<=m; i++)
    {
        scanf("%lld%lld",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll sum=0;
    for(ll i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            minn=inf;
            dfs(i);
            sum+=minn;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
