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
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
int node_cnt, n, m;
int sum[N << 5], rt[N], lc[N << 5], rc[N << 5];
int a[N], p; //原序列和离散序列和修改点
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

int query(int u, int v, int l, int r, int k) //求u,v这两棵线段树的差的树中的第k大
{
    int mid = (l + r) >> 1, ans;
    int x = sum[lc[v]] - sum[lc[u]];
    int y = sum[rc[v]] - sum[rc[u]];
    if (l == r)
        return l;
    if (x > k)
        ans = query(lc[u], lc[v], l, mid, k);
    else if (y > k)
        ans = query(rc[u], rc[v], mid + 1, r, k);
    else
        ans = 0;
    return ans;
}
void init()
{
    node_cnt = 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init();
    build(rt[0], 1, n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        p = a[i];
        rt[i] = modify(rt[i - 1], 1, n);
    }
    int l, r;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        int k = (r - l + 1) >> 1;
        printf("%d\n", query(rt[l - 1], rt[r], 1, n, k));
    }

    return 0;
}