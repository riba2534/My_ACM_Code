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
const int N = 3e5 + 10;
int first[N], tot;
int sum[N << 2], MAX[N<<2];
int n, q;
int son[N], id[N], fa[N], cnt, dep[N], siz[N], top[N];
int w[N], wt[N];
int summ,maxx;
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
    MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = wt[l];
        MAX[rt] = sum[rt];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p, int sc, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = sc;
        MAX[rt] = sc;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, sc, lson);
    else
        update(p, sc, rson);
    pushup(rt);
}
void query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        summ += sum[rt];
        maxx = max(maxx, MAX[rt]);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        query(L, R, lson);
    if (R > m)
        query(L, R, rson);
}
void dfs1(int u, int f, int deep)
{
    dep[u] = deep;
    fa[u] = f;
    siz[u] = 1;
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
    id[u] = ++cnt;
    wt[cnt] = w[u];
    top[u] = topf;
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
void ask(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        query(id[top[x]], id[x], 1, n, 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    query(id[x], id[y], 1, n, 1);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int u, v, x, y;
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, n, 1);
    scanf("%d", &q);
    char s[10];
    while (q--)
    {
        scanf("%s", s);
        scanf("%d%d", &x, &y);
        if (s[0] == 'C') //change
            update(id[x], y, 1, n, 1);
        else
        {
            summ=0;
            maxx=-10000000;
            ask(x, y);
            if (s[1] == 'M') //qmax
                printf("%d\n", maxx);
            else if (s[1] == 'S') //qsum
                printf("%d\n", summ);
        }
    }
    return 0;
}
