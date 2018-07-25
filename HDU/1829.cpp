//rank[i]表示i与根节点的关系，0为同性，1为异性
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define N 2020
#define M 1000000+10
#define ll long long
using namespace std;
ll pre[N],rank1[N],n,k;
ll flag=0;
void init()
{
    flag=0;
    for(ll i=0; i<=n; i++)
    {
        pre[i]=i;
        rank1[i]=0;
    }

}
ll find(ll x)
{
    if(x==pre[x])
        return pre[x];
    else
    {
        ll t=find(pre[x]);
        rank1[x]=(rank1[pre[x]]+rank1[x])&1;
        pre[x]=t;
        return pre[x];
    }
}
void mix(ll x,ll y)
{
    ll fx=find(x);
    ll fy=find(y);
    if(fx==fy)
    {
        if(rank1[x]==rank1[y])
            flag=1;
        return ;
    }
    pre[fx]=fy;
    rank1[fx]=(rank1[x]+rank1[y]+1)&1;
}
int main()
{
    ll t,q=1,a,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        init();
        for(ll i=0; i<k; i++)
        {
            scanf("%lld%lld",&a,&b);
            mix(a,b);
        }
        if(flag)
            printf("Scenario #%lld:\nSuspicious bugs found!\n\n",q++);
        else
            printf("Scenario #%lld:\nNo suspicious bugs found!\n\n",q++);
    }
    return 0;
}
