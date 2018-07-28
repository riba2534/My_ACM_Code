#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define int long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int N=200005;
int MAX[N<<2],MIN[N<<2];
void pushup(int rt)
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
    MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%lld",&MAX[rt]);
        MIN[rt]=MAX[rt];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int add,int l,int r,int rt)
{
    if(l==r)
    {
        MAX[rt]=add;
        MIN[rt]=add;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,add,lson);
    else
        update(p,add,rson);
    pushup(rt);
}
int query_max(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MAX[rt];
    int m=(l+r)>>1;
    int ans=-inf;
    if(L<=m)
        ans=max(ans,query_max(L,R,lson));
    if(R>m)
        ans=max(ans,query_max(L,R,rson));
    return ans;
}
int query_min(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MIN[rt];
    int m=(l+r)>>1;
    int ans=inf;
    if(L<=m)
        ans=min(ans,query_min(L,R,lson));
    if(R>m)
        ans=min(ans,query_min(L,R,rson));
    return ans;
}
int32_t main()
{
    int t,n,q,m,a,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        n=1<<n;
        build(1,n,1);
        scanf("%lld",&m);
        while(m--)
        {
            scanf("%lld%lld%lld",&q,&a,&b);
            a++;
            if(q==1)
            {
                b++;
                int minn=query_min(a,b,1,n,1);
                int maxx=query_max(a,b,1,n,1);
                if(maxx<=0)
                    printf("%lld\n",maxx*maxx);
                else if(minn>=0)
                    printf("%lld\n",minn*minn);
                else
                    printf("%lld\n",minn*maxx);
            }
            else if(q==2)
                update(a,b,1,n,1);
        }
    }
}
