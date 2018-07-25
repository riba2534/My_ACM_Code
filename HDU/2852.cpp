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
int sum[N << 2], vis[N];
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = 0;
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
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, add, lson);
    else
        update(p, add, rson);
    pushup(rt);
}
int query(int k, int l, int r, int rt) //求整个线段树中第k大
{
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    if (sum[rt << 1] >= k)
        return query(k, lson);
    return query(k - sum[rt << 1], rson);
}
int Rank(int p, int l, int r, int rt) //<=p的数出现的总次数
{
    if (p >= r)
        return sum[rt];
    int m = (l + r) >> 1;
    int ans = 0;
    ans += Rank(p, lson);
    if (m <= p - 1)
        ans += Rank(p, rson);
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
        mem(vis, 0);
        int op, x, k;
        build(1, N, 1);
        while (n--)
        {
            scanf("%d", &op);
            if (op == 0)
            {
                scanf("%d", &x);
                update(x, 1, 1, N, 1);
                vis[x]++;
            }
            else if (op == 1)
            {
                scanf("%d", &x);
                if (!vis[x])
                    puts("No Elment!");
                else
                {
                    update(x, -1, 1, N, 1);
                    vis[x]--;
                }
            }
            else if (op == 2)
            {
                scanf("%d%d", &x, &k);
                int ans = Rank(x, 1, N, 1); //查找<=x的数个个数
                if (sum[1] < ans + k)
                    puts("Not Find!");
                else
                    printf("%d\n", query(ans + k, 1, N, 1));
            }
        }
    }
    return 0;
}