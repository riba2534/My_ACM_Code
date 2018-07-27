// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem(a,b) mem(a,b,sizeof(a))
typedef long long ll;
const ll N=100000+20;
ll mul[N<<2],add[N<<2];//两个lazy标记
ll sum[N<<2],p;
void pushup(ll rt)
{
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p;
}
void build(ll l,ll r,ll rt)
{
    mul[rt]=1;
    add[rt]=0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        sum[rt]%=p;
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(ll l,ll r,ll rt)
{
    ll m=(l+r)>>1;
    sum[rt<<1]=(sum[rt<<1]*mul[rt]+add[rt]*(m-l+1))%p;
    sum[rt<<1|1]=(sum[rt<<1|1]*mul[rt]+add[rt]*(r-m))%p;
    //维护lazy
    mul[rt<<1]=(mul[rt<<1]*mul[rt])%p;
    mul[rt<<1|1]=(mul[rt<<1|1]*mul[rt])%p;
    add[rt<<1]=(add[rt<<1]*mul[rt]+add[rt])%p;
    add[rt<<1|1]=(add[rt<<1|1]*mul[rt]+add[rt])%p;
    //初始化父节点的lazy
    mul[rt]=1;
    add[rt]=0;
}
void update1(ll L,ll R,ll k,ll l,ll r,ll rt)//乘法
{
    if(L<=l&&r<=R)
    {
        sum[rt]=(sum[rt]*k)%p;
        mul[rt]=(mul[rt]*k)%p;
        add[rt]=(add[rt]*k)%p;
        return;
    }
    pushdown(l,r,rt);
    ll m=(l+r)>>1;
    if(L<=m) update1(L,R,k,lson);
    if(R>m) update1(L,R,k,rson);
    pushup(rt);
    return;
}
void update2(ll L,ll R,ll k,ll l,ll r,ll rt)//加法
{
    if(L<=l&&r<=R)
    {
        add[rt]=(add[rt]+k)%p;
        sum[rt]=(sum[rt]+k*(r-l+1))%p;
        return;
    }
    ll m=(l+r)>>1;
    pushdown(l,r,rt);
    if(L<=m) update2(L,R,k,lson);
    if(R>m) update2(L,R,k,rson);
    pushup(rt);
    return;
}
ll query(ll L,ll R,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    ll m=(l+r)>>1;
    pushdown(l,r,rt);
    ll ans=0;
    if(L<=m) ans=(ans+query(L,R,lson))%p;
    if(R>m) ans=(ans+query(L,R,rson))%p;
    return ans;
}
int main()
{
    ll n,m;
    scanf("%lld%lld%lld",&n,&m,&p);
    build(1,n,1);
    ll x,y,k,op;
    for(ll i=1; i<=m; i++)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            update1(x,y,k,1,n,1);
        }
        else if(op==2)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            update2(x,y,k,1,n,1);
        }
        else
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",query(x,y,1,n,1));
        }
    }
    return 0;
}
