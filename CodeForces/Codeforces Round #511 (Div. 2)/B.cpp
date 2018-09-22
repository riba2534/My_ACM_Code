#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
const ll N = 1e5 + 10;
struct pos
{
    ll x, y;
} e[N];
bool cmp(pos a, pos b)
{
    return a.x < b.x;
}
int main()
{
    ll n, maxx = 0;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &e[i].x, &e[i].y);
        maxx = max(maxx, e[i].x + e[i].y);
    }
    printf("%lld\n", maxx);

    return 0;
}
