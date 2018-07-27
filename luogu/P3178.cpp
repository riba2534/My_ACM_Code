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
const ll N = 2e5 + 10;
ll n, m;
ll sum[N << 2], lazy[N << 2];
ll siz[N], dep[N], son[N], fa[N], cnt, top[N], id[N], wt[N], w[N];
ll first[N], tot;
ll res=0;
struct edge
{
    ll v, next;
} e[N];
void add_edge(ll u, ll v)
{
    e[tot].v = v;
    e[tot].next = first[u];
    first[u] = tot++;
}
void init()
{
    mem(first, -1);
    tot = 0;
    cnt=0;
}
ll pushup(ll rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
ll pushdown(ll rt, ll m)
{
    if (lazy[rt])
    {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        sum[rt << 1] += lazy[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += lazy[rt] * (m >> 1);
        lazy[rt] = 0;
    }
}
void build(ll l, ll r, ll rt)
{
    lazy[rt] = 0;
    if (l == r)
    {
        sum[rt] = wt[l];
        return;
    }
    ll m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(ll L, ll R, ll c, ll l, ll r, ll rt)
{
    if (L <= l && r <= R)
    {
        lazy[rt]+=c;
        sum[rt]+=c*(r-l+1);
        return;
    }
    pushdown(rt, r - l + 1);
    ll m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, lson);
    if (R > m)
        update(L, R, c, rson);
    pushup(rt);
}
void query(ll L, ll R, ll l, ll r, ll rt)
{
    if (L <= l && r <= R)
    {
        res+=sum[rt];
        return;
    }
    pushdown(rt, r - l + 1);
    ll m = (l + r) >> 1;
    if (L <= m)
        query(L, R, lson);
    if (R > m)
        query(L, R, rson);
}
void dfs1(ll u, ll f, ll deep)
{
    siz[u] = 1;
    fa[u] = f;
    dep[u] = deep + 1;
    ll maxson = -1;
    for (ll i = first[u]; ~i; i = e[i].next)
    {
        ll v = e[i].v;
        if (v == f)
            continue;
        dfs1(v, u, deep + 1);
        siz[u] += siz[v];
        if (siz[v] > maxson)
        {
            son[u] = v;
            maxson = siz[v];
        }
    }
}
void dfs2(ll u, ll topf)
{
    top[u] = topf;
    id[u] = ++cnt;
    wt[cnt] = w[u];
    if (!son[u])
        return;
    dfs2(son[u], topf);
    for (ll i = first[u]; ~i; i = e[i].next)
    {
        ll v = e[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
void upd1(ll x, ll k)
{
    update(id[x], id[x], k, 1, n, 1);
}
void upd2(ll x, ll k)
{
    update(id[x], id[x] + siz[x] - 1, k, 1, n, 1);
}
ll qsum(ll x, ll y)
{
    ll ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res=0;
        query(id[top[x]], id[x], 1, n, 1);
        ans +=res;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res=0;
    query(id[x], id[y], 1, n, 1);
    ans +=res;
    return ans;
}
int main()
{
    ll u, v, x, y;
    scanf("%lld%lld", &n, &m);
    init();
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    for (ll i = 1; i <= n - 1; i++)
    {
        scanf("%lld%lld", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, n, 1);
    while (m--)
    {
        ll op;
        scanf("%lld", &op);
        if (op == 1)
        {
            scanf("%lld%lld", &x, &y);
            upd1(x, y);
        }
        else if (op == 2)
        {
            scanf("%lld%lld", &x, &y);
            upd2(x, y);
        }
        else if (op == 3)
        {
            scanf("%lld", &x);
            printf("%lld\n", qsum(x, 1));
        }
    }
    return 0;
}

