#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
typedef unsigned long long ll;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const ll N=1e5+20;
const ll mod=9223372034707292160ull;
ll sum[N<<2];
bool flag[N<<2];
void pushup(ll rt)
{
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%mod;
    flag[rt]=flag[rt<<1]&flag[rt<<1|1];
}
void build(ll l,ll r,ll rt)
{
    if(l==r)
    {
        scanf("%llu",&sum[rt]);
        flag[rt]=0;
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
ll q_mul(ll a,ll b)
{
    ll ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%mod;
        }
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
void update(ll a,ll b,ll l,ll r,ll rt)
{
    if(flag[rt]&&a<=l&&r<=b)return;
    if(l==r)
    {
        ll tmp=q_mul(sum[rt],sum[rt]);
        if(tmp==sum[rt])
            flag[rt]=true;
        sum[rt]=tmp;
        return;
    }
    ll m=(l+r)>>1;
    if(a<=m)
        update(a,b,lson);
    if(b>m)
        update(a,b,rson);
    pushup(rt);
}
ll query(ll L,ll R,ll l,ll r,ll rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    ll m=(l+r)>>1;
    ll ans=0;
    if(L<=m)
        ans=(ans+query(L,R,lson))%mod;
    if(R>m)
        ans=(ans+query(L,R,rson))%mod;
    return ans;
}
int main()
{
    ll t,n,m,q=1,x;
    scanf("%llu",&t);
    while(t--)
    {
        mem(flag,0);
        scanf("%llu%llu",&n,&m);
        build(1,n,1);
        ll sum=0,a,b;
        printf("Case #%llu:\n",q++);
        while(m--)
        {
            scanf("%llu%llu",&a,&b);
            sum=(sum+query(a,b,1,n,1))%mod;
            printf("%llu\n",sum);
            update(a,b,1,n,1);
        }
    }
    return 0;
}


