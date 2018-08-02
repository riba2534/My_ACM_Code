#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
int main()
{
    ll n, k, s;
    scanf("%lld%lld%lld", &n, &k, &s);
    if (s < k || k * (n - 1) < s)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    ll st = 1;
    while (k--)
    {
        ll dis = min(s - k, n - 1);
        s -= dis;
        if (st + dis <= n)
            st += dis;
        else
            st -= dis;
        printf("%lld ", st);
    }
    puts("");
    return 0;
}
