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
const int N = 3e5 + 10;
const int inf = 0x3f3f3f3f;
int a[N], n, m, ans[N], c[N];
map<int, int> mp;
int lowbit(int x)
{
    return x & -x;
}
void add(int i, int k)
{
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}
int sum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}
struct node
{
    int l, r, id;
} query[N];
bool cmp(node x, node y)
{
    return x.r < y.r;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n))
    {
        mem(c, 0);
        mp.clear();
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &query[i].l, &query[i].r);
            query[i].id = i;
        }
        sort(query, query + m, cmp);

        int cur = 1; //从下标为1的位置开始扫描
        for (int i = 0; i < m; i++)
        {
            for (int j = cur; j <= query[i].r; j++)
            {
                if (mp.find(a[j]) != mp.end())
                {
                    add(mp[a[j]], -1);
                }
                add(j, 1);

                mp[a[j]] = j;
                //printf("mp[%d]=%d\n", a[j], mp[a[j]]);
            }
            cur = query[i].r + 1;
            ans[query[i].id] = sum(query[i].r) - sum(query[i].l - 1);
        }
        for (int i = 0; i < m; i++)
            printf("%d\n", ans[i]);
    }

    return 0;
}
