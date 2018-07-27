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
#define inf 0x3f3f3f3f
typedef long long ll;
const int N = 50000 + 20;
int sum[N << 2], ans[N];
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
int update(int l, int r, int rt, int x)
{
    if (l == r)
    {
        sum[rt] = 0;
        return l;
    }
    int ret, m = (l + r) >> 1;
    if (x <= sum[rt << 1])
        ret = update(lson, x);
    else
        ret = update(rson, x - sum[rt << 1]);
    pushup(rt);
    return ret;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, x, m;
    while (~scanf("%d", &n))
    {
        mem(ans, 0);
        build(1, n, 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            ans[i] = update(1, n, 1, x);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &x);
            if (i == 1)
                printf("%d", ans[x]);
            else
                printf(" %d", ans[x]);
        }
        puts("");
    }
    return 0;
}