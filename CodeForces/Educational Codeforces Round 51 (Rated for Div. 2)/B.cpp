#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll dis = r - l + 1;
    if (dis & 1)
        puts("NO");
    else
    {
        puts("YES");
        for (ll i = l; i <= r; i += 2)
        {
            printf("%lld %lld\n", i, i + 1);
        }
    }

    return 0;
}
