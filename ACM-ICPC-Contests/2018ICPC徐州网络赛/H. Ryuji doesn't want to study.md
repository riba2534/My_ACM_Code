# 描述

> Ryuji is not a good student, and he doesn't want to study. But there are n books he should learn, each book has its knowledge a[i].
>
> Unfortunately, the longer he learns, the fewer he gets.
>
> That means, if he reads books from ll to rr, he will get a[l] \times L + a[l+1] \times (L-1) + \cdots + a[r-1] \times 2 + a[r]a[l]×L+a[l+1]×(L−1)+⋯+a[r−1]×2+a[r] (LL is the length of [ ll, rr ] that equals to r - l + 1r−l+1).
>
> Now Ryuji has qq questions, you should answer him:
>
> \11. If the question type is 11, you should answer how much knowledge he will get after he reads books [ ll, rr ].
>
> \22. If the question type is 22, Ryuji will change the ith book's knowledge to a new value.

### Input

> First line contains two integers nn and qq (nn, q \le 100000q≤100000).
>
> The next line contains n integers represent a[i]( a[i] \le 1e9)a[i](a[i]≤1e9) .
>
> Then in next qq line each line contains three integers aa, bb, cc, if a = 1a=1, it means question type is 11, and bb, ccrepresents [ ll , rr ]. if a = 2a=2 , it means question type is 22 , and bb, cc means Ryuji changes the bth book' knowledge to cc

### Output

> For each question, output one line with one integer represent the answer.

#### 样例输入

```
5 3
1 2 3 4 5
1 1 3
2 5 0
1 4 5
```

#### 样例输出

```
10
8
```

#### 题目来源

[ACM-ICPC 2018 徐州赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E5%BE%90%E5%B7%9E%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

题目给了n个数，有两种操作，第一种是求区间`[l,r]`的区间内所有前缀和的和，第二种是单点修改.

比如我们举个栗子

```
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
```

用两个树状数组维护一下，第一个维护一下$(n-i+1) \times a[i]$的和，如上面的数字。

然后查询的时候我们只需要用上面的区间和减去$(n-y) \times a[i]$的区间和。

单点修改直接改就行。

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef pair<ll, ll> pir;
const ll N = 1e5 + 10;
ll a[N];
struct binaryTree
{
    ll c[N], NN;
    ll init(ll n)
    {
        mem(c, 0);
        NN = n;
    }
    ll lowbit(ll x)
    {
        return x & -x;
    }
    ll sum(ll n)
    {
        ll sum = 0;
        while (n > 0)
        {
            sum += c[n];
            n = n - lowbit(n);
        }
        return sum;
    }
    ll query(ll l, ll r)
    {
        return sum(r) - sum(l - 1);
    }
    void add(ll i, ll k)
    {
        while (i <= NN)
        {
            c[i] += k;
            i += lowbit(i);
        }
    }
} ac1, ac2;

int main()
{
    //freopen("in.txt", "r", stdin);
    ll n, q, op, x, y;
    scanf("%lld%lld", &n, &q);
    ac1.init(n), ac2.init(n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        ac1.add(i, a[i]);
        ac2.add(i, (n - i + 1) * a[i]);
    }
    while (q--)
    {
        scanf("%lld%lld%lld", &op, &x, &y);
        if (op == 1)
        {
            ll L = n - y;
            ll ans = ac2.query(x, y) - L * ac1.query(x, y);
            printf("%lld\n", ans);
        }
        else if (op == 2)
        {
            ac1.add(x, y - a[x]);
            ac2.add(x, (y - a[x]) * (n - x + 1));
            a[x] = y;
        }
    }

    return 0;
}
```

