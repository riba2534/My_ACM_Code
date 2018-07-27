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
const int N = 2e5 + 10;
int n, m;
int sum[N << 2], lazy[N << 2];
int siz[N], dep[N], son[N], fa[N], cnt, top[N], id[N], wt[N], w[N];
int first[N], tot;
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
int pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int pushdown(int rt, int m)
{
    if (~lazy[rt])
    {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        sum[rt << 1] = (m - (m >> 1)) * lazy[rt];
        sum[rt << 1 | 1] = (m >> 1) * lazy[rt];
        lazy[rt] = -1;
    }
}
void build(int l, int r, int rt)
{
    lazy[rt] = -1;
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
void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        lazy[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, lson);
    if (R > m)
        update(L, R, c, rson);
    pushup(rt);
}

void dfs1(int u, int f, int deep)
{
    siz[u] = 1;
    fa[u] = f;
    dep[u] = deep + 1;
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
void upd1(int x, int y, int k)
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
void upd2(int x, int k)
{
    update(id[x], id[x] + siz[x] - 1, k, 1, n, 1);
}
int main()
{
    int v, x;
    scanf("%d", &n);
    init();
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &v);
        v++;
        add_edge(i, v);
        add_edge(v, i);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, n, 1);
    char s[10];
    scanf("%d", &m);
    while (m--)
    {
        scanf("%s%d", s, &x);
        x++;
        int ans1 = sum[1];
        if (s[0] == 'i') //install
        {
            upd1(x, 1, 1);
            int ans2 = sum[1];
            printf("%d\n", abs(ans2 - ans1));
        }
        else if (s[0] == 'u') //uninstall
        {
            upd2(x, 0);
            int ans2 = sum[1];
            printf("%d\n", abs(ans2 - ans1));
        }
    }
    return 0;
}
