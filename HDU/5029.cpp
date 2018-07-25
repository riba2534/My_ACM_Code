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
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int first[N], tot;
int MAX[N << 2], ans[N], idmax[N << 2];
int cnt, siz[N], dep[N], fa[N], son[N], top[N], id[N], wt[N];
struct edge
{
    int v, next;
} e[N * 2];
struct qnode
{
    int l, r, k;
    qnode(int _l, int _r, int _k)
    {
        l = _l;
        r = _r;
        k = _k;
    }
};
vector<qnode> op;
vector<int> a[N];
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
    op.clear();
    mem(a, 0);
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
    wt[cnt] = u;
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
void pushup(int rt)
{
    if (MAX[rt << 1 | 1] > MAX[rt << 1])
        idmax[rt] = idmax[rt << 1 | 1];
    else
        idmax[rt] = idmax[rt << 1];
    MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        idmax[rt] = l;
        MAX[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p, int add, int l, int r, int rt)
{
    if (l == r)
    {
        MAX[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, add, lson);
    else
        update(p, add, rson);
    pushup(rt);
}

void change(int x, int y, int k)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        op.push_back(qnode(id[top[x]], id[x], k));
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    op.push_back(qnode(id[x], id[y], k));
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m, u, v;
    while (~scanf("%d%d", &n, &m) && (n || m))
    {
        init();
        for (int i = 1; i <= n - 1; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        int x, y, k;
        while (m--)
        {
            scanf("%d%d%d", &x, &y, &k);
            change(x, y, k);
        }
        int len = op.size();
        for (int i = 0; i < len; i++)
        {
            int l = op[i].l, r = op[i].r, k = op[i].k;
            // printf("l=%d,r=%d,k=%d\n", l, r, k);
            a[l].push_back(k);
            a[r + 1].push_back(-k);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        build(1, N, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                int tmp = a[i][j];
                if (tmp < 0)
                    update(-tmp, -1, 1, N, 1);
                else
                    update(tmp, 1, 1, N, 1);
            }
            ans[wt[i]] = idmax[1];
            if (MAX[1] == 0)
                ans[wt[i]] = 0;
        }
        for (int i = 1; i <= n; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
