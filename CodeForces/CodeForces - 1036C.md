# 描述

> Let's call some positive integer classy if its decimal representation contains no more than 33 non-zero digits. For example, numbers 44, 200000200000, 1020310203 are classy and numbers 42314231, 102306102306, 72774200007277420000 are not.
>
> You are given a segment [L;R][L;R]. Count the number of classy integers xx such that L≤x≤RL≤x≤R.
>
> Each testcase contains several segments, for each of them you are required to solve the problem separately.

# Input

> The first line contains a single integer TT (1≤T≤1041≤T≤104) — the number of segments in a testcase.
>
> Each of the next TT lines contains two integers LiLi and RiRi (1≤Li≤Ri≤10181≤Li≤Ri≤1018).

# Output

> Print TT lines — the ii-th line should contain the number of classy integers on a segment [Li;Ri][Li;Ri].

## input

```
4
1 1000
1024 1024
65536 65536
999999 1000001
```

## output

```
1000
1
0
2
```

# 思路

先说题意，给你`t`组数据,询问区间`[L,R]`内非`0`数字出现次数`<=3`次的数的个数.

定义状态：`dp[i][j]`表示前`i`位数字，非`0`数字出现`j`次的方案数。

模板修改:

num代表当前这一位，为0数字出现的次数.

所以当pos枚举完之后，直接判断`num`是否`<=3`即可.

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const ll N = 3e5 + 10;
ll dp[20][20], a[20];
ll dfs(ll pos, ll num, ll limit)
{
    if (pos == -1)
        return num <= 3;
    if (!limit && ~dp[pos][num])
        return dp[pos][num];
    ll up = limit ? a[pos] : 9, ans = 0;
    for (ll i = 0; i <= up; i++)
        ans += dfs(pos - 1, num + (i != 0), limit && (i == up));
    return limit ? ans : dp[pos][num] = ans;
}
ll solve(ll x)
{
    ll pos = 0;
    while (x)
    {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, 1);
}
int main()
{
    ll n, m, t;
    mem(dp, -1);
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", solve(m) - solve(n - 1));
    }
    return 0;
}
```







