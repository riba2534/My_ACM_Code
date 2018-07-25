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
const int N = 1000 + 10;
struct node
{
    int x, y, id;
} e[N];
int dp[N], pos[N], pre[N], n, a[N];
vector<int> v;
bool cmp(node a, node b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}
int get_lis()
{
    mem(dp, inf);
    pos[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int p = lower_bound(dp, dp + n, a[i]) - dp;
        dp[p] = a[i];
        pos[p] = i;
        pre[i] = (p ? pos[p - 1] : -1);
    }
    int ans = lower_bound(dp, dp + n, inf) - dp;
    return ans;
}
void print(int ans)
{
    int i;
    for (i = pos[ans - 1]; ~pre[i]; i = pre[i])
        v.push_back(e[i].id);
    v.push_back(e[i].id);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        printf("%d\n", v[i]);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int x, y;
    n = 0;
    while (~scanf("%d%d", &x, &y))
    {
        e[n].x = x;
        e[n].y = y;
        e[n].id = n + 1;
        n++;
    }
    sort(e, e + n, cmp);
    for (int i = 0; i < n; i++)
        a[i] = e[i].x;
    int ans = get_lis();
    printf("%d\n", ans);
    print(ans);

    return 0;
}