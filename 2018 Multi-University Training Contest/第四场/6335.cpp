#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const ll N = 1e5 + 10;
ll b[N];
int main()
{
    ll t, n, m;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        for (ll i = 1; i <= n; i++)
            scanf("%*d%lld", &b[i]);
        sort(b + 1, b + n + 1);
        ll now = 1, ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            now *= b[i] + 1;
            if (m >= now)
                ans = i;
            else
                break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}