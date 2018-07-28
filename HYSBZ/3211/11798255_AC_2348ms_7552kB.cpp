#include <cstdio>
#include <cstring>
#include <cctype>
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
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const ll N=100000+20;
ll sum[N<<2];
ll flag[N<<2];
void pushup(ll rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    flag[rt]=flag[rt<<1]&flag[rt<<1|1];
}
void build(ll l,ll r,ll rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        if(sum[rt]<=1)flag[rt]=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
//void update(ll p,ll l,ll r,ll rt)
//{
//    if(flag[rt]==1)return;
//    if(l==r)
//    {
//        sum[rt]=floor(sqrt(sum[rt]));
//        if(sum[rt]<=1)flag[rt]=1;
//        return;
//    }
//    ll m=(l+r)>>1;
//    if(p<=m)
//        update(p,lson);
//    else
//        update(p,rson);
//    pushup(rt);
//}
void update(int a,int b,int l,int r,int rt)
{
    if(flag[rt]==1) return;
    if(l==r)
    {
        sum[rt]=floor(sqrt(sum[rt]));
        if(sum[rt]<=1)flag[rt]=1;
        return;
    }
    int m=(l+r)>>1;
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
        ans+=query(L,R,lson);
    if(R>m)
        ans+=query(L,R,rson);
    return ans;
}
int main()
{
    // mem(flag,-1);
    ll n,m;
    scanf("%lld",&n);
    build(1,n,1);
    scanf("%lld",&m);
    ll q,a,b;
    while(m--)
    {
        scanf("%lld%lld%lld",&q,&a,&b);
        if(q==1)
            printf("%lld\n",query(a,b,1,n,1));
        else if(q==2)
        {
//            for(ll i=a; i<=b; i++)
//                update(i,1,n,1);
            update(a,b,1,n,1);
        }
    }
    return 0;
}
