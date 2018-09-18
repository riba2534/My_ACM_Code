# 描述

> God Water likes to eat meat, fish and chocolate very much, but unfortunately, the doctor tells him that some sequence of eating will make them poisonous.
>
> Every hour, God Water will eat one kind of food among meat, fish and chocolate. If there are 33 continuous hours when he eats only one kind of food, he will be unhappy. Besides, if there are 33 continuous hours when he eats all kinds of those, with chocolate at the middle hour, it will be dangerous. Moreover, if there are 33 continuous hours when he eats meat or fish at the middle hour, with chocolate at other two hours, it will also be dangerous.
>
> Now, you are the doctor. Can you find out how many different kinds of diet that can make God Water happy and safe during NN hours? Two kinds of diet are considered the same if they share the same kind of food at the same hour. The answer may be very large, so you only need to give out the answer module 1000000007.

### Input

> The fist line puts an integer TT that shows the number of test cases. (T \le 1000T≤1000)
>
> Each of the next TT lines contains an integer NN that shows the number of hours. (1 \le N \le 10^{10}1≤N≤1010)

### Output

> For each test case, output a single line containing the answer.

#### 样例输入复制

```
3
3
4
15
```

#### 样例输出复制

```
20
46
435170
```

#### 题目来源

[ACM-ICPC 2018 焦作赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E7%84%A6%E4%BD%9C%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

有三种食物，肉 鱼 巧克力。

现在题目与有一些规定:

1. 相同的食物连续吃三小时就会不高兴
2. 在三个小时中，中间吃巧克力，另外的时间分别吃鱼和肉，他就会不高兴
3. 在三个小时中，他第一个小时和第三个小时吃巧克力，其他时间吃其他的，他会不高兴

题目给出你他要吃多少个小时，问你使它高兴的方案数。

方法1：

那么我们可以想到[POJ2778 DNA Sequence(AC自动机+矩阵快速幂)](https://blog.csdn.net/riba2534/article/details/78452202)这个题,要求长度为n的序列中，不包含给的序列的方案数。我们用ac自动机+矩阵快速幂可以解决，那么思路就一样了，先把病毒串插入字典树，然后矩阵快速幂，记得加稀疏矩阵优化。

方法2:

暴力算出来前几项的值，然后用杜教BM线性递推板子。。(tql)



# 代码

方法1:

```cpp
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll N = 19;
const ll mod = 1e9 + 7;
struct Matrix
{
    ll mat[N][N], n;
    Matrix() {}
    Matrix(ll _n)
    {
        n = _n;
        mem(mat, 0);
    }
    Matrix operator*(const Matrix &b) const
    {
        //printf("n=%lld\n", n);
        Matrix ret = Matrix(n);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                if (mat[i][j])
                    for (ll k = 0; k < n; k++)
                        ret.mat[i][k] = ret.mat[i][k] + mat[i][j] * b.mat[j][k] % mod;
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                ret.mat[i][j] %= mod;
        return ret;
    }
};
Matrix mat_pow(Matrix a, ll n)
{
    Matrix ret = Matrix(a.n);
    for (ll i = 0; i < ret.n; i++)
        ret.mat[i][i] = 1;
    Matrix tmp = a;
    while (n)
    {
        if (n & 1)
            ret = ret * tmp;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ret;
}
struct dicTree
{
    ll next[N][4], fail[N];
    bool end[N];
    ll root, sz;
    ll newnode()
    {
        for (ll i = 0; i < 3; i++)
            next[sz][i] = -1;
        end[sz++] = 0;
        return sz - 1;
    }
    void init()
    {
        sz = 0;
        root = newnode();
    }
    ll getch(char ch)
    {
        if (ch == '1')
            return 0;
        if (ch == '2')
            return 1;
        if (ch == '3')
            return 2;
    }
    void insert(string s)
    {
        ll len = s.size();
        ll now = root;
        for (ll i = 0; i < len; i++)
        {
            ll to = getch(s[i]);
            if (next[now][to] == -1)
                next[now][to] = newnode();
            now = next[now][to];
        }
        end[now] = true;
    }
    void build()
    {
        queue<ll> q;
        fail[root] = root;
        for (ll i = 0; i < 3; i++)
        {
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty())
        {
            ll now = q.front();
            q.pop();
            if (end[fail[now]] == true)
                end[now] = true;
            for (ll i = 0; i < 3; i++)
            {
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    q.push(next[now][i]);
                }
            }
        }
    }
    Matrix get_mat()
    {
        Matrix res = Matrix(sz);
        for (ll i = 0; i < sz; i++)
            for (ll j = 0; j < 3; j++)
                if (end[next[i][j]] == false && end[i] == false)
                    res.mat[i][next[i][j]]++;
        return res;
    }
};
dicTree ac;
int main()
{
    ll t, m;
    ac.init();
    string s[10];
    s[1] = "111";
    s[2] = "222";
    s[3] = "333";
    s[6] = "123";
    s[7] = "321";
    s[4] = "212";
    s[5] = "232";

    for (ll i = 1; i <= 7; i++)
    {
        ac.insert(s[i]);
    }
    ac.build();
    Matrix a = ac.get_mat();
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &m);
        Matrix b = a;
        b = mat_pow(b, m);
        ll ans = 0;
        for (ll i = 0; i < ac.sz; i++)
            ans = ans + b.mat[0][i];
        printf("%lld\n", ans % mod);
    }
    return 0;
}
```

方法2:

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
    //freopen("in.txt", "r", stdin);
    //填数字的时候带上模数之后的
    ll t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", linear_seq::gao(VI{3, 9, 20, 46, 106, 244, 560, 1286, 2956, 6794}, n-1));
    }
    return 0;
}
```



