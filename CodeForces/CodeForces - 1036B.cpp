#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll abs(ll a, ll b)
{
    if (a > b)
        return a - b;
    return b - a;
}
int main()
{
    ll q, n, m, k;
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        if (k < max(n, m))
        {
            puts("-1");
            continue;
        }
        ll a = abs(n, k) % 2;
        ll b = abs(m, k) % 2;
        printf("%lld\n", k - a - b);
    }
    return 0;
}
