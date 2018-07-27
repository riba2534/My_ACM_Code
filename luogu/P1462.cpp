// luogu-judger-enable-o2
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
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define rson m + 1, r, rt << 1 | 1
#define inf 0x3f3f3f3f
typedef long long ll;
const ll N = 10000 + 10;
const ll M = 50000 * 2 + 10;
ll n, m, b;
ll first[N], tot, f[N];
ll vis[N], dis[N];
struct edge
{
    ll v, w, next;
} e[M];
void add_edge(ll u, ll v, ll w)
{
    e[tot].v = v, e[tot].w = w;
    e[tot].next = first[u];
    first[u] = tot++;
}
void init()
{
    mem(first, -1);
    tot = 0;
}
void spfa(ll limit)
{
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    dis[1] = 0;
    vis[1] = 1;
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis[u] = 0;
        for (ll i = first[u]; ~i; i = e[i].next)
        {
            ll v = e[i].v, w = e[i].w;
            if (f[v] <= limit && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
ll judge(ll mid)
{
    spfa(mid);
    if (dis[n] > b)
        return 0;
    return 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ll u, v, w, l = 0, r = 0;
    scanf("%lld%lld%lld", &n, &m, &b);
    init();
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &f[i]);
        r = max(r, f[i]);
    }
    l = max(f[1], f[n]);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    //printf("l=%lld,r=%lld\n", l, r);
    spfa(r);
    if (dis[n] == inf || dis[n] > b)
    {
        puts("AFK");
        return 0;
    }
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (judge(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld\n", l);

    return 0;
}
