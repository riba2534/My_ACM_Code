#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
int main()
{
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll x = n / i;
            s.insert((1 + n - i + 1) * x / 2);
            s.insert((1 + n - x + 1) * i / 2);
        }
    }
    for (auto x : s)
        printf("%lld ", x);
    puts("");
    return 0;
}
