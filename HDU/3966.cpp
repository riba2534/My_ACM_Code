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
typedef long long ll;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int first[N], tot, n, m, p;
int sum[N << 2], lazy[N << 2];
int w[N], wt[N], cnt, siz[N], dep[N], fa[N], son[N], top[N], id[N];
struct edge
{
    int v, next;
} e[N];
void add_edge(int u, int v)
{
    e[tot].v = v;
    e[tot].next = first[u];
    first[u] = tot++;
}
void init()
{
    mem(first, -1);
    tot = 0;
    cnt = 0;
}
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m)
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
void build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if (l == r)
    {
        sum[rt] = wt[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L, int R, int k, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        lazy[rt] += k;
        sum[rt] += k * (r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, k, lson);
    if (R > m)
        update(L, R, k, rson);
    pushup(rt);
}
int query(int p, int l, int r, int rt)
{
    if (l == r)
        return sum[rt];
    int m = (l + r) >> 1;
    pushdown(rt, r - l + 1);
    int ans = 0;
    if (p <= m)
        ans += query(p, lson);
    else
        ans += query(p, rson);
    pushup(rt);
    return ans;
}
void dfs1(int u, int f, int deep)
{
    siz[u] = 1;
    dep[u] = deep;
    fa[u] = f;
    son[u] = 0;
    int maxson = -1;
    for (int i = first[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
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
void dfs2(int u, int topf)
{
    top[u] = topf;
    id[u] = ++cnt;
    wt[cnt] = w[u];
    if (!son[u])
        return;
    dfs2(son[u], topf);
    for (int i = first[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
void change(int x, int y, int k)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(id[top[x]], id[x], k, 1, n, 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update(id[x], id[y], k, 1, n, 1);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int u, v;
    while (~scanf("%d%d%d", &n, &m, &p))
    {
        init();
        for (int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        build(1, n, 1);
        char s[5];
        int x, y, k;
        while (p--)
        {
            scanf("%s", s);
            if (s[0] == 'I')
            {
                scanf("%d%d%d", &x, &y, &k);
                change(x, y, k);
            }
            else if (s[0] == 'D')
            {
                scanf("%d%d%d", &x, &y, &k);
                change(x, y, -k);
            }
            else if (s[0] == 'Q')
            {
                scanf("%d", &x);
                printf("%d\n", query(id[x], 1, n, 1));
            }
        }
    }
    return 0;
}
