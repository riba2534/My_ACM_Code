#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5 + 10;
ll a[N], b[N];
int main()
{
    ll n, m, sum1 = 0, sum2 = 0;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]), sum1 += a[i];
    scanf("%lld", &m);
    for (ll i = 1; i <= m; i++)
        scanf("%lld", &b[i]), sum2 += b[i];
    if (sum1 != sum2)
    {
        puts("-1");
        return 0;
    }
    sum1 = 0, sum2 = 0;
    ll i = 1, j = 1, ans = 0;
    while (i <= n && j <= m)
    {
        if (sum1 == sum2 && sum1 > 0)
        {
            ans++;
            sum1 = 0;
            sum2 = 0;
        }
        if (sum1 > sum2)
            sum2 += b[j++];
        else
            sum1 += a[i++];
    }
    if (sum1 || sum2)
        ans++;
    printf("%lld\n", ans);

    return 0;
}
