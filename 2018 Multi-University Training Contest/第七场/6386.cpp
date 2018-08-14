#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 100;
const int M = 2e5 + 100;
int first[N], tot, n, m;
int vis[N], dis[N];
struct edge
{
    int v, cost, next;
} e[M * 2];

void add_edge(int u, int v, int cost)
{
    e[tot].v = v, e[tot].cost = cost;
    e[tot].next = first[u];
    first[u] = tot++;
}
struct node
{
    int pre, v, c;
    node() {}
    node(int _v = 0, int _c = 0, int _pre = 0)
    {
        pre = _pre, v = _v, c = _c;
    }
    bool friend operator<(node a, node b)
    {
        return a.c > b.c;
    }
};
priority_queue<node> q;
void bfs()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        dis[i] = inf;
    }
    while (!q.empty())
        q.pop();
    dis[1] = 0;
    q.push(node(1, 0, 0));
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        int u = now.v;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = first[u]; ~i; i = e[i].next)
        {
            int v = e[i].v, cost = e[i].cost;
            int w;
            if (cost == now.pre)
                w = 0;
            else
                w = 1;
            if (!vis[v] && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push(node(v, dis[v], cost));
            }
        }
    }
}
void init()
{
    mem(first, -1);
    tot = 0;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int u, v, c;
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        bfs();
        if (dis[n] == inf)
            puts("-1");
        else
            printf("%d\n", dis[n]);
    }

    return 0;
}
