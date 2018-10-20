### 描述

> 如果一个二进制数包含连续的两个1，我们就称这个二进制数是非法的。
>
> 小Hi想知道在所有 n 位二进制数（一共有2n个）中，非法二进制数有多少个。
>
> 例如对于 n = 3,有 011, 110, 111 三个非法二进制数。
>
> 由于结果可能很大，你只需要输出模109+7的余数。

### 输入

> 一个整数 n (1 ≤ n ≤ 100)。

### 输出

> n 位非法二进制数的数目模109+7的余数。

## 样例输入

```
3
```

## 样例输出

```
3
```

# 思路

首先用python打表，把符合条件的数前20个找到。然后BM板子过去或者。找规律，一个数的值等于他的前一项的值*2+一个斐波那契数

# 代码

py打表:

```python
def get0(n):
    ans = 0
    for i in range(2**n):
        s = bin(i)[2:].zfill(n)
        for i in range(1, len(s)):
            if s[i] == '1' and s[i-1] == '1':
                ans += 1
                break
    return ans
for i in range(1, 20):
    print(i, get0(i))

```

bm算法暴力过:

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ll;
typedef vector<int> VI;
const int maxn = 10005;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;

ll fast_mod(ll a, ll n, ll Mod)
{
    ll ans = 1;
    a %= Mod;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % Mod;
        a = (a * a) % Mod;
        n >>= 1;
    }
    return ans;
}

namespace linear_seq
{
ll res[maxn], base[maxn], num[maxn], md[maxn]; //数组大小约10000
vector<int> vec;
void mul(ll *a, ll *b, int k)
{
    for (int i = 0; i < 2 * k; i++)
        num[i] = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i])
            for (int j = 0; j < k; j++)
                num[i + j] = (num[i + j] + a[i] * b[j]) % mod;
    }
    for (int i = 2 * k - 1; i >= k; i--)
    {
        if (num[i])
            for (int j = 0; j < vec.size(); j++)
                num[i - k + vec[j]] = (num[i - k + vec[j]] - num[i] * md[vec[j]]) % mod;
    }
    for (int i = 0; i < k; i++)
        a[i] = num[i];
}
ll solve(ll n, VI a, VI b)
{
    ll ans = 0, cnt = 0;
    int k = a.size();
    assert(a.size() == b.size());
    for (int i = 0; i < k; i++)
        md[k - 1 - i] = -a[i];
    md[k] = 1;
    vec.clear();
    for (int i = 0; i < k; i++)
        if (md[i])
            vec.push_back(i);
    for (int i = 0; i < k; i++)
        res[i] = base[i] = 0;
    res[0] = 1;
    while ((1LL << cnt) <= n)
        cnt++;
    for (int p = cnt; p >= 0; p--)
    {
        mul(res, res, k);
        if ((n >> p) & 1)
        {
            for (int i = k - 1; i >= 0; i--)
                res[i + 1] = res[i];
            res[0] = 0;
            for (int j = 0; j < vec.size(); j++)
                res[vec[j]] = (res[vec[j]] - res[k] * md[vec[j]]) % mod;
        }
    }
    for (int i = 0; i < k; i++)
        ans = (ans + res[i] * b[i]) % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}
VI BM(VI s)
{
    VI B(1, 1), C(1, 1);
    int L = 0, m = 1, b = 1;
    for (int i = 0; i < s.size(); i++)
    {
        ll d = 0;
        for (int j = 0; j < L + 1; j++)
            d = (d + (ll)C[j] * s[i - j]) % mod;
        if (d == 0)
            m++;
        else if (2 * L <= i)
        {
            VI T = C;
            ll c = mod - d * fast_mod(b, mod - 2, mod) % mod;
            while (C.size() < B.size() + m)
                C.push_back(0);
            for (int j = 0; j < B.size(); j++)
                C[j + m] = (C[j + m] + c * B[j]) % mod;
            L = i + 1 - L, B = T, b = d, m = 1;
        }
        else
        {
            ll c = mod - d * fast_mod(b, mod - 2, mod) % mod;
            while (C.size() < B.size() + m)
                C.push_back(0);
            for (int j = 0; j < B.size(); j++)
                C[j + m] = (C[j + m] + c * B[j]) % mod;
            m++;
        }
    }
    return C;
}
int gao(VI a, ll n)
{
    VI c = BM(a);
    c.erase(c.begin());
    for (int i = 0; i < c.size(); i++)
        c[i] = (mod - c[i]) % mod;
    return solve(n, c, VI(a.begin(), a.begin() + c.size()));
}
} // namespace linear_seq
int main()
{
    ll t, n;
    scanf("%lld", &n);
    printf("%lld\n", linear_seq::gao(VI{0, 1, 3, 8, 19, 43, 94, 201, 423, 880}, n - 1));
    return 0;
}
```

找规律:

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll a[110], b[110];
int main()
{
    ll n;
    scanf("%lld", &n);
    a[1] = 0, a[2] = 1, a[3] = 3;
    b[2] = 1, b[3] = 1;
    for (ll i = 4; i <= n; i++)
    {
        b[i] = (b[i - 1] + b[i - 2]) % mod;
        a[i] = (a[i - 1] * 2 + b[i]) % mod;
    }
    printf("%lld\n", a[n]);
    return 0;
}
```

