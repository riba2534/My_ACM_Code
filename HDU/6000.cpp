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
#define inf 0x3f3f3f3f
typedef long long ll;
const ll N=1e6+20;
struct node
{
    ll x,val;//洗处理衣服的时间和当前时间
    node() {}
    node(ll _x,ll _val)
    {
        x=_x;
        val=_val;
    }
    bool friend operator < (node a,node b)
    {
        return a.val>b.val;//使花费时间小的先出队
    }
} a[N];
ll t[N],L,n,m;//t[i]代表第i个衣服最早的洗完时间
int main()
{
    ll T,x,kase=1;
    scanf("%lld",&T);
    while(T--)
    {
        priority_queue<node>q;
        scanf("%lld%lld%lld",&L,&n,&m);
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&x);
            q.push(node(x,x));
        }
        for(ll i=0; i<L; i++)
        {
            node now=q.top();
            q.pop();
            t[i]=now.val;
            q.push(node(now.x,now.x+now.val));
        }
        while(!q.empty())q.pop();
        for(ll i=0; i<m; i++)
        {
            scanf("%lld",&x);
            q.push(node(x,x));
        }
        ll ans=0;
        for(ll i=L-1; i>=0; i--)
        {
            node now=q.top();
            q.pop();
            ans=max(ans,t[i]+now.val);
            q.push(node(now.x,now.x+now.val));
        }
        printf("Case #%lld: %lld\n",kase++,ans);
    }
    return 0;
}

