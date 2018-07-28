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
const ll N=3e5+500;
const ll M=1e6+200;
ll sum[N<<2],MAX[N<<2],num[M];
ll pushup(ll rt)
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(ll l,ll r,ll rt)
{
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        MAX[rt]=sum[rt];
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(ll L,ll R,ll l,ll r,ll rt)
{
    if(l==r)
    {
        MAX[rt]=num[MAX[rt]];
        sum[rt]=num[sum[rt]];
        return;
    }
    ll m=(l+r)>>1;
    if(L<=m&&MAX[rt<<1]>2)
        update(L,R,lson);
    if(R>m&&MAX[rt<<1|1]>2)
        update(L,R,rson);
    pushup(rt);
}
ll query(ll L,ll R,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    ll m=(l+r)>>1;
    ll ans=0;
    if(L<=m) ans+=query(L,R,lson);
    if(R>m) ans+=query(L,R,rson);
    return ans;
}
void init()
{
    for(ll i=0; i<M; i++) num[i]=1;
    for(ll i=2; i<M; i++)
        for(ll j=i; j<M; j+=i)
            num[j]++;
}
int main()
{
    init();
    ll n,m,a,b,op;
    scanf("%lld%lld",&n,&m);
    build(1,n,1);
    while(m--)
    {
        scanf("%lld%lld%lld",&op,&a,&b);
        if(op==1) update(a,b,1,n,1);
        else printf("%lld\n",query(a,b,1,n,1));
    }
    return 0;
}
