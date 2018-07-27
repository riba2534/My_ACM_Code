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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1000+20)
#define ll long long
using namespace std;
ll c[N];
struct node
{
    ll x,y;
} g[N*N];
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
ll lowbit(ll x)//用来维护树状数组,得到管辖区间
{
    return x&-x;
}
void add(ll k,ll num,ll n)//给数组的第k位增加num个
{
    while(k<=n)
    {
        c[k]+=num;
        k+=lowbit(k);
    }
}
ll sum(ll n)//求要查询的区间的前n项和
{
    ll sum=0;
    while(n>0)
    {
        sum+=c[n];
        n-=lowbit(n);
    }
    return sum;
}

int main()
{
    ll t,n,m,k,q=1;
    scanf("%lld",&t);
    while(t--)
    {
        mem(c,0);
        scanf("%lld%lld%lld",&n,&m,&k);
        for(ll i=1; i<=k; i++)
            scanf("%lld%lld",&g[i].x,&g[i].y);
        sort(g+1,g+k+1,cmp);
        ll ans=0;
        for(ll i=1; i<=k; i++)
        {
            add(g[i].y,1,m);
            ans+=(sum(m)-sum(g[i].y));
        }
        printf("Test case %lld: %lld\n",q++,ans);
    }
    return 0;
}
