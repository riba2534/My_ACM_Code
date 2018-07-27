#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const ll N=100000+50;
ll lazy[N<<2],sum[N<<2];

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
void update(ll a,ll b,ll c,ll l,ll r,ll rt)
{
    if(a<=l&&r<=b)
    {
        lazy[rt]+=c;
        sum[rt]+=c*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    ll m=(l+r)>>1;
    if(a<=m) update(a,b,c,lson);
    if(b>m) update(a,b,c,rson);
    pushup(rt);
}
ll query(ll a,ll b,ll l,ll r,ll rt)
{
    if(a<=l&&r<=b)
        return sum[rt];
    pushdown(rt,r-l+1);
    ll ans=0;
    ll m=(l+r)>>1;
    if(a<=m) ans+=query(a,b,lson);
    if(b>m) ans+=query(a,b,rson);
    return ans;
}
int main()
{
    char s[5];
    ll n,m,a,b,c;
    scanf("%lld%lld",&n,&m);
    build(1,n,1);
    while(m--)
    {
        scanf("%s",s);
        if(s[0]=='Q')
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",query(a,b,1,n,1));
        }
        else
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
    }
    return 0;
}
