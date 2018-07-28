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
const ll N = 3e5 + 20;
ll n, st, ed;
ll num[N], pre[N];
vector<ll> e[N];
ll dfs(ll u, ll fa)
{
    pre[u] = fa;
    ll cnt = 0;
    for (auto v : e[u])
        if (v != fa)
            cnt += dfs(v, u);
    num[u] = cnt + 1;
    return num[u];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ll u, v;
    scanf("%lld%lld%lld", &n, &st, &ed);
    for (ll i = 1; i <= n - 1; i++)
    {
        scanf("%lld%lld", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(st, -1);
    ll son = ed;
    while (pre[son] != st)
        son = pre[son];
    ll ans = n * (n - 1);
    ans -= num[ed] * (n - num[son]);
    printf("%lld\n", ans);
    return 0;
}