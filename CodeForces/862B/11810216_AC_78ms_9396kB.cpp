#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const ll N=1e5+20;
ll color[N],vis[N],match[N],n,m;
vector<ll>G[N];
ll judge()
{
    queue<ll>q;
    q.push(1);
    color[1]=1;
    vis[1]=1;
    while(!q.empty())
    {
        ll v1=q.front();
        q.pop();
        for(ll i=0; i<G[v1].size(); i++)
        {
            ll v2=G[v1][i];
            if(color[v2]==-1&&!vis[v2])
            {
                color[v2]=-color[v1];
                vis[v2]=1;
                q.push(v2);
            }
//            else if(color[v1]==color[v2])
//                return 0;
        }
    }
    return 1;
}
int main()
{
    mem(color,-1);
    ll n,a,b;
    scanf("%lld",&n);
    for(ll i=1; i<=n-1; i++)
    {
        scanf("%lld%lld",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    judge();
    ll sum=0;
    for(ll i=1; i<=n; i++)
        if(color[i]==1)
            sum++;
    // cout<<sum<<endl;
    printf("%lld\n",sum*(n-sum)-(n-1));
    return 0;
}
