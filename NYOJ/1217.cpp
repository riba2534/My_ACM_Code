 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
typedef long long ll;
const ll N=8e4+100;
ll color[N<<2],lazy[N<<2],sum[N<<2],vis[N<<2],cnt;
void pushup(ll rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(ll rt,ll m)
{
    if(lazy[rt])
    {
        color[rt<<1]=color[rt<<1|1]=color[rt];
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        sum[rt<<1]+=lazy[rt]*(m-(m>>1));
        sum[rt<<1|1]+=lazy[rt]*(m>>1);
        color[rt]=-1;
        lazy[rt]=0;
    }
}
void build(ll l,ll r,ll rt)
{
    color[rt]=-1;
    lazy[rt]=0;
    sum[rt]=0;
    if(l==r) return;
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(ll L,ll R,ll c,ll d,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
    {
        color[rt]=c;
        lazy[rt]+=d;
        sum[rt]+=(r-l+1)*d;
        return;
    }
    pushdown(rt,r-l+1);
    ll m=(l+r)>>1;
    if(L<=m) update(L,R,c,d,lson);
    if(R>m) update(L,R,c,d,rson);
    pushup(rt);
}
ll query(ll L,ll R,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    ll m=(l+r)>>1;
    ll ans=0;
    if(L<=m) ans+=query(L,R,lson);
    if(R>m) ans+=query(L,R,rson);
    pushup(rt);
    return ans;
}
void queryc(ll L,ll R,ll l,ll r,ll rt)
{
    if(color[rt]!=-1)
    {
        if(!vis[color[rt]])
        {
            cnt++;
            vis[color[rt]]=1;
            return;
        }
    }
    if(l==r) return;
    pushdown(rt,r-l+1);
    ll m=(l+r)>>1;
    if(L<=m) queryc(L,R,lson);
    if(R>m) queryc(L,R,rson);
    pushup(rt);
}
int main()
{
    ll n,m,op,l,r,c,d;
    while(~scanf("%lld%lld",&n,&m))
    {
        mem(vis,0);
        cnt=0;
        build(1,n-1,1);
        while(m--)
        {
            scanf("%lld%lld%lld",&op,&l,&r);
            if(op==1)
            {
                scanf("%lld%lld",&c,&d);
                update(l,r-1,c,d,1,n-1,1);
            }
            else
            {
                printf("%lld\n",query(l,r-1,1,n-1,1));
            }
        }
        queryc(1,n-1,1,n-1,1);
        printf("%lld %lld\n",sum[1],cnt);
    }
    return 0;
}
        