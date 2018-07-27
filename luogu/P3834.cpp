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
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int a[N], b[N];
int rt[N], lc[N << 5], rc[N << 5], node_cnt, sum[N << 5];
int p;
void build(int &t, int l, int r)
{
    t = ++node_cnt;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc[t], l, mid);
    build(rc[t], mid + 1, r);
}
int modify(int o, int l, int r)
{
    int oo = ++node_cnt;
    lc[oo] = lc[o];
    rc[oo] = rc[o];
    sum[oo] = sum[o] + 1;
    if (l == r)
        return oo;
    int mid = (l + r) >> 1;
    if (p <= mid)
        lc[oo] = modify(lc[oo], l, mid);
    else
        rc[oo] = modify(rc[oo], mid + 1, r);
    return oo;
}

int query(int u, int v, int l, int r, int k)
{
    int mid = (l + r) >> 1, ans;
    int x = sum[lc[v]] - sum[lc[u]];
    if (l == r)
        return l;
    if (x >= k)
        ans = query(lc[u], lc[v], l, mid, k);
    else
        ans = query(rc[u], rc[v], mid + 1, r, k - x);
    return ans;
}
void init()
{
    node_cnt = 0;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int q = unique(b + 1, b + n + 1) - (b + 1);
    build(rt[0], 1, q);
    for (int i = 1; i <= n; i++)
    {
        p = lower_bound(b + 1, b + q + 1, a[i]) - b;
        rt[i] = modify(rt[i - 1], 1, q);
    }
    int l, r, k;
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", b[query(rt[l - 1], rt[r], 1, q, k)]);
    }

    return 0;
}
/*
5 5
25957 6405 15770 26287 26465 
2 2 1
3 4 1
4 5 1
1 2 2
4 4 1
*/