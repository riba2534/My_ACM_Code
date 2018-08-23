#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 100000 + 200;
const int mod = 998244353;
typedef long long ll;
ll f[N];
int main()
{
    int t, n;
    scanf("%d", &t);
    f[0] = 1, f[1] = 0, f[2] = 0;
    f[3] = 1, f[4] = 1, f[5] = 8;
    for (int i = 6; i < N; i++)
        f[i] = (1ll * (i - 2) * f[i - 1] + (i - 1) * f[i - 2] - (i & 1 ? -1 : 1)) % mod;
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}