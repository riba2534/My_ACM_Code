# 描述

> A prince of the Science Continent was imprisoned in a castle because of his contempt for mathematics when he was young, and was entangled in some mathematical curses. He studied hard until he reached adulthood and decided to use his knowledge to escape the castle.
>
> There are NN rooms from the place where he was imprisoned to the exit of the castle. In the i^{th}ith room, there is a wizard who has a resentment value of a[i]a[i]. The prince has MM curses, the j^{th}jth curse is f[j]f[j], and f[j]f[j] represents one of the four arithmetic operations, namely addition(`'+'`), subtraction(`'-'`), multiplication(`'*'`), and integer division(`'/'`). The prince's initial resentment value is KK. Entering a room and fighting with the wizard will eliminate a curse, but the prince's resentment value will become the result of the arithmetic operation f[j]f[j] with the wizard's resentment value. That is, if the prince eliminates the j^{th}jth curse in the i^{th}ith room, then his resentment value will change from xx to (x\ f[j]\ a[i]x f[j] a[i]), for example, when x=1, a[i]=2, f[j]=x=1,a[i]=2,f[j]=`'+'`, then xx will become 1+2=31+2=3.
>
> Before the prince escapes from the castle, he must eliminate all the curses. He must go from a[1]a[1] to a[N]a[N] in order and cannot turn back. He must also eliminate the f[1]f[1] to f[M]f[M] curses in order(It is guaranteed that N\ge MN≥M). What is the maximum resentment value that the prince may have when he leaves the castle?

### Input

> The first line contains an integer T(1 \le T \le 1000)T(1≤T≤1000), which is the number of test cases.
>
> For each test case, the first line contains three non-zero integers: N(1 \le N \le 1000), M(1 \le M \le 5)N(1≤N≤1000),M(1≤M≤5) and K(-1000 \le K \le 1000K(−1000≤K≤1000), the second line contains NN non-zero integers: a[1], a[2], ..., a[N](-1000 \le a[i] \le 1000)a[1],a[2],...,a[N](−1000≤a[i]≤1000), and the third line contains MM characters: f[1], f[2], ..., f[M](f[j] =f[1],f[2],...,f[M](f[j]=`'+','-','*','/'`, with no spaces in between.

### Output

> For each test case, output one line containing a single integer.

#### 样例输入

```
3
2 1 5
2 3
/
3 2 1
1 2 3
++
4 4 5
1 2 3 4
+-*/
```

#### 样例输出

```
2
6
3
```

#### 题目来源

[ACM-ICPC 2018 焦作赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E7%84%A6%E4%BD%9C%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

有`n`个格子，每个格子里面有一个数，有`m`个运算符，你的初始值为`k`.

现在规定，你必须按照从1到n的顺序去访问每个格子，并且决定在当前格子中要不要进行运算，运算的方式为:`你的当前值 = 你的当前值 你要使用的符号 格子里面的值`。你必须用完所有的符号，格子里面的数可能为负，现在你需要走完这些格子，然后求一个最大值。

思路就是dp，从1到n，每个格子有两种状态，用符号和不用符号，我们记录一个最大值和最小值直接dp即可。

`dp[i][j]`表示前i个格子，用了j个符号，所能达到的最大最小值。

首先初始化`dp[i][0]`为`k`,然后初始化`dp[1~m][1~m]`的值为运算的结果。

然后转移方程为:

```cpp
dp[i][j].min = smin(dp[i - 1][j].min, calc(dp[i - 1][j - 1].min, a[i], s[j]), calc(dp[i - 1][j - 1].max, a[i], s[j]));
dp[i][j].max = smax(dp[i - 1][j].max, calc(dp[i - 1][j - 1].min, a[i], s[j]), calc(dp[i - 1][j - 1].max, a[i], s[j]));
```

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e3 + 10;
ll a[N];
char s[20];
struct node
{
    ll max, min;
} dp[N][10];
ll calc(ll x, ll y, char ch)
{
    if (ch == '+')
        return x + y;
    else if (ch == '-')
        return x - y;
    else if (ch == '*')
        return x * y;
    else if (ch == '/')
        return x / y;
}
ll smin(ll x, ll y, ll z)
{
    return min(x, min(y, z));
}
ll smax(ll x, ll y, ll z)
{
    return max(x, max(y, z));
}

void solve()
{
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    scanf("%s", s + 1);
    for (ll i = 0; i <= n; i++)
        dp[i][0].max = dp[i][0].min = k;
    for (ll i = 1; i <= m; i++)
        dp[i][i].max = dp[i][i].min = calc(dp[i - 1][i - 1].max, a[i], s[i]);
    for (ll j = 1; j <= m; j++)
    {
        for (ll i = j + 1; i <= n; i++)
        {
            dp[i][j].min = smin(dp[i - 1][j].min, calc(dp[i - 1][j - 1].min, a[i], s[j]), calc(dp[i - 1][j - 1].max, a[i], s[j]));
            dp[i][j].max = smax(dp[i - 1][j].max, calc(dp[i - 1][j - 1].min, a[i], s[j]), calc(dp[i - 1][j - 1].max, a[i], s[j]));
        }
    }
    printf("%lld\n", dp[n][m].max);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ll t;
    scanf("%lld", &t);
    while (t--)
        solve();
    return 0;
}

```

