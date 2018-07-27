// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define mod 10007
const int N = 200000 + 10;
int first[N], tot = 0;
struct edge
{
    int v, next;
} e[N * 2];
int a[N];
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
}
int max_ans = 0, ans;
void solve(int u)
{
    int maxx = 0, sum = 0, m = 0;
    for (int i = first[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (a[v] > maxx)
        {
            m = maxx;
            maxx = a[v];
        }
        else if (a[v] > m)
        {
            m = a[v];
        }
        ans = (ans + sum * a[v]) % mod;
        sum = (sum + a[v]) % mod;
    }
    max_ans = max(max_ans, maxx * m);
}
int main()
{
    int n, u, v;
    scanf("%d", &n);
    init();
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        solve(i);
    printf("%d %d\n", max_ans, ans * 2 % mod);
    return 0;
}