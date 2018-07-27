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
const int N = 5000 + 10;
struct edge
{
    int x, y, w;
} e[N];
struct node
{
    int val, w;
    node() {}
    node(int _val, int _w)
    {
        val = _val, w = _w;
    }
};
int pos[N], flag, vis[N];
vector<node> g[N];
int Y, W; //当前的右端点和当前所求区间的奇偶性
void dfs(int u, int step)
{
    if (u == Y)
    {
        if (step % 2 != W)
            flag = 0;
        return;
    }
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        node now = g[u][i];
        if (!vis[now.val])
            dfs(now.val, now.w + step);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, q;
    char s[10];
    int len = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%s", &e[i].x, &e[i].y, s);
        if (s[0] == 'e')
            e[i].w = 0;
        else
            e[i].w = 1;
        e[i].y++;
        pos[len++] = e[i].x;
        pos[len++] = e[i].y;
    }
    sort(pos, pos + len);
    int m = unique(pos, pos + len) - pos;
    for (int i = 1; i <= q; i++)
    {
        int x = lower_bound(pos, pos + m, e[i].x) - pos;
        int y = lower_bound(pos, pos + m, e[i].y) - pos;
        e[i].x = x;
        e[i].y = y;
    }
    for (int i = 1; i <= q; i++)
    {
        flag = 1;
        Y = e[i].y;
        W = e[i].w;
        mem(vis, 0);
        dfs(e[i].x, 0);
        if (flag == 0)
        {
            printf("%d\n", i - 1);
            return 0;
        }
        g[e[i].x].push_back(node(e[i].y, e[i].w));
        g[e[i].y].push_back(node(e[i].x, e[i].w));
    }
    printf("%d\n", q);

    return 0;
}