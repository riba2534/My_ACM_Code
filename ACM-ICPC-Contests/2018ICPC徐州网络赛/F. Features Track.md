# 描述

> Morgana is learning computer vision, and he likes cats, too. One day he wants to find the cat movement from a cat video. To do this, he extracts cat features in each frame. A cat feature is a two-dimension vector <xx, yy>. If x_ixi= x_jxj and y_iyi = y_jyj, then <x_ixi, y_iyi> <x_jxj, y_jyj> are same features.
>
> So if cat features are moving, we can think the cat is moving. If feature <aa, bb> is appeared in continuous frames, it will form features movement. For example, feature <aa , bb > is appeared in frame 2,3,4,7,82,3,4,7,8, then it forms two features movement 2-3-42−3−4 and 7-87−8 .
>
> Now given the features in each frames, the number of features may be different, Morgana wants to find the longest features movement.

### Input

> First line contains one integer T(1 \le T \le 10)T(1≤T≤10) , giving the test cases.
>
> Then the first line of each cases contains one integer nn (number of frames),
>
> In The next nn lines, each line contains one integer k_iki ( the number of features) and 2k_i2ki intergers describe k_ikifeatures in ith frame.(The first two integers describe the first feature, the 33rd and 44th integer describe the second feature, and so on).
>
> In each test case the sum number of features NN will satisfy N \le 100000N≤100000 .

### Output

> For each cases, output one line with one integers represents the longest length of features movement.

#### 样例输入复制

```
1
8
2 1 1 2 2
2 1 1 1 4
2 1 1 2 2
2 2 2 1 4
0
0
1 1 1
1 1 1
```

#### 样例输出复制

```
3
```

#### 题目来源

[ACM-ICPC 2018 徐州赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E5%BE%90%E5%B7%9E%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

先说题意，首先是$t$组数据,每组数据第一行是一个$n$,接下来有$n$行,每行最开始有一个数$x$代表这一行有$x$对数，接下来有$x$对数(两个数字为一对)。

题目问在这$n$行之中,连续出现次数最大的那一对数出现的次数。

比如第一个样例`(1,1)`这一对连续出现了3次。



我们首先把这个问题从一个数对转化成一个数字，那么问题会转化成这么一个问题：给你一串数字，求这串数字中连续出现的数字次数的最大值。

那么我们很容易能想一种`dp`的解法，令`dp[i][j]`表示前i个数字中j这个数字出现的最大次数，然后`dp[i][j]=dp[i-1][j]+1`，然后取一个最大值即可。

那么对于这个问题，只不过是把数字转化成了数对，我们可以利用`map`来处理一下这个数对，`map<pair<int,int>,int>mp`,这样就可以把一个数对映射成为一个数字，接下来因为数据范围较大,有$10^5$,我们用到的状态只有当前状态和前一个状态，所以可以利用滚动数组优化一下。



# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef pair<int, int> pir;
const int N = 1e5 + 10;
map<pir, int> mp[2];
void solve()
{
    int n, x, a, b;
    scanf("%d", &n);
    int cur = 0, maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        cur ^= 1;
        mp[cur].clear();
        scanf("%d", &x);
        while (x--)
        {
            scanf("%d%d", &a, &b);
            pir tmp = make_pair(a, b);
            mp[cur][tmp] = mp[cur ^ 1][tmp] + 1;
            maxx = max(maxx, mp[cur][tmp]);
        }
    }
    printf("%d\n", maxx);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
```

