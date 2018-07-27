// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const ll N=100000+10;
ll sum[N<<2],lazy[N<<2];
void pushup(ll rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(ll rt,ll m)
{
    if(lazy[rt])
    {
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        sum[rt<<1]+=lazy[rt]*(m-(m>>1));
        sum[rt<<1|1]+=lazy[rt]*(m>>1);
        lazy[rt]=0;
    }
}
void build(ll l,ll r,ll rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(ll L,ll R,ll c,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]+=c;
        sum[rt]+=c*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    ll m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt);
}
ll query(ll L,ll R,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    pushdown(rt,r-l+1);
    ll m=(l+r)>>1;
    ll ans=0;
    if(L<=m) ans+=query(L,R,lson);
    if(R>m) ans+=query(L,R,rson);
    return ans;
}

int main()
{
    ll n,m,op,x,y,k;
    scanf("%lld%lld",&n,&m);
    build(1,n,1);
    for(ll i=1; i<=m; i++)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            update(x,y,k,1,n,1);
        }
        else
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",query(x,y,1,n,1));
        }
    }
    return 0;
}
