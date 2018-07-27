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
typedef long long ll;
const ll N=1e5+500;
const ll inf=1e18;
ll dis[N],vis[N],first[N],tot,n,m;
struct edge
{
    ll v,t,c,next;
} e[N*2];
void add_edge(ll u,ll v,ll t,ll c)
{
    e[tot].v=v,e[tot].t=t,e[tot].c=c;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    tot=0;
}
void spfa()
{
    for(ll i=1; i<=n; i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    queue<ll>q;
    q.push(1);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        vis[u]=0;
        for(ll i=first[u]; ~i; i=e[i].next)
        {
            ll v=e[i].v,t=e[i].t;
            if(dis[u]+t<dis[v])
            {
                dis[v]=dis[u]+t;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    ll ans1=0,ans2=0;
    for(ll i=1; i<=n; i++)
        ans1+=dis[i];
    vector<ll>g[N];
    q.push(1);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=first[u]; ~i; i=e[i].next)
        {
            ll c=e[i].c,v=e[i].v,t=e[i].t;
            if(dis[u]+t==dis[v])
            {
                g[v].push_back(c);
                q.push(v);
            }
        }
    }
    for(ll i=1; i<=n; i++)
    {
        ll minn=inf;
        for(ll j=0; j<g[i].size(); j++)
            minn=min(minn,g[i][j]);
        if(minn!=inf)
            ans2+=minn;
    }
    printf("%lld %lld\n",ans1,ans2);
}
int main()
{
    ll t,u,v,kase,c;
    scanf("%lld",&kase);
    while(kase--)
    {
        scanf("%lld%lld",&n,&m);
        init();
        for(ll i=1; i<=m; i++)
        {
            scanf("%lld%lld%lld%lld",&u,&v,&t,&c);
            u++,v++;
            add_edge(u,v,t,c);
            add_edge(v,u,t,c);
        }
        spfa();
    }
    return 0;
}

/*
4
4 4
0 1 1 1
1 2 1 1
0 2 2 2
0 3 1 2
*/