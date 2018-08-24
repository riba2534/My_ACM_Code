# 描述

小Hi平时的一大兴趣爱好就是演奏钢琴。我们知道一个音乐旋律被表示为长度为 N 的数构成的数列。小Hi在练习过很多曲子以后发现很多作品自身包含一样的旋律。

旋律可以表示为一段连续的数列，相似的旋律在原数列不可重叠，比如在1 2 3 2 3 2 1 中 2 3 2 出现了一次，2 3 出现了两次，小Hi想知道一段旋律中出现次数至少为两次的旋律最长是多少？

[解题方法提示](http://hihocoder.com/problemset/problem/1407#)

# 输入

第一行一个整数 N。1≤N≤100000

接下来有 N 个整数，表示每个音的数字。1≤数字≤1000

# 输出

一行一个整数，表示答案。

# 样例输入

```
8
1 2 3 2 3 2 3 1
```

# 样例输出

```
2
```
# 思路

求不可重叠最长重复子串。和`POJ1743`一样

1. 二分最大长度k，然后按照`height[i]>=k`来分组
2. 找出每一组的sa的最大值和最小值，当`MAX-MIN>=k`的时候证明两个串不重叠，满足条件



# 代码

```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 1e5 + 10;
int t1[N], t2[N], c[N], r[N], sa[N], rak[N], height[N];
bool cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int str[], int sa[], int rak[], int height[], int n, int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;
    for (i = 0; i < m; i++)
        c[i] = 0;
    for (i = 0; i < n; i++)
        c[x[i] = str[i]]++;
    for (i = 1; i < m; i++)
        c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--c[x[i]]] = i;
    for (j = 1; j <= n; j <<= 1)
    {
        p = 0;
        for (i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j)
                y[p++] = sa[i] - j;
        for (i = 0; i < m; i++)
            c[i] = 0;
        for (i = 0; i < n; i++)
            c[x[y[i]]]++;
        for (i = 1; i < m; i++)
            c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
    int k = 0;
    n--;
    for (i = 0; i <= n; i++)
        rak[sa[i]] = i;
    for (i = 0; i < n; i++)
    {
        if (k)
            k--;
        j = sa[rak[i] - 1];
        while (str[i + k] == str[j + k])
            k++;
        height[rak[i]] = k;
    }
}

int n, a[N];
bool check(int mid)
{
    int maxx = sa[1], minn = sa[1];
    for (int i = 2; i <= n; i++)
    {
        if (height[i] >= mid)
        {
            maxx = max(maxx, sa[i]);
            minn = min(minn, sa[i]);
            continue;
        }
        if (maxx - minn >= mid) //满足不可重叠条件
            return true;
        minn = maxx = sa[i];
    }
    return false;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = 0;
    da(a, sa, rak, height, n, 1100);
    int l = 2, r = n, ans;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", ans);

    return 0;
}
```

