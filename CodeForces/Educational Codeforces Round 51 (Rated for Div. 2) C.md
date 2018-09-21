# 描述

> Vasya has a multiset ss consisting of nn integer numbers. Vasya calls some number xx nice if it appears in the multiset exactly once. For example, multiset {1,1,2,3,3,3,4}{1,1,2,3,3,3,4} contains nice numbers 22 and 44.
>
> Vasya wants to split multiset ss into two multisets aa and bb (one of which may be empty) in such a way that the quantity of nice numbers in multiset aa would be the same as the quantity of nice numbers in multiset bb (the quantity of numbers to appear exactly once in multiset aaand the quantity of numbers to appear exactly once in multiset bb).

# Input

> The first line contains a single integer n (2≤n≤100)n (2≤n≤100).
>
> The second line contains nn integers s1,s2,…sn (1≤si≤100)s1,s2,…sn (1≤si≤100) — the multiset ss.

# Output

> If there exists no split of ss to satisfy the given requirements, then print "NO" in the first line.
>
> Otherwise print "YES" in the first line.
>
> The second line should contain a string, consisting of nn characters. ii-th character should be equal to 'A' if the ii-th element of multiset ssgoes to multiset aa and 'B' if if the ii-th element of multiset ss goes to multiset bb. Elements are numbered from 11 to nn in the order they are given in the input.
>
> If there exist multiple solutions, then print any of them.

# input

```
4
3 5 7 1
```

# output

```
YES
BABA
```

# input

```
3
3 5 1
```

# output

```
NO
```

# 思路

给你一个集合，现在你要把集合分为两个。

定义一个集合中的**好数**为:这个集合中出现次数为`1`次的数的个数.

现在要求你分出来的这两个集合中的**好数**个数一样(可以为0).

输出的时候按照输入的顺序，分成AB两个集合，在对应位置用AB来标记

首先我们求出题目给出的集合中的出现一次的数的个数`sum1`和出现次数>2的数的个数`sum2`.

当sum1为偶数或者sum2存在就一定可以分。

那么情况就有:

1. sum1出现的次数为奇数且sum2存在
2. sum1出现的次数为偶数，sum2随意

对于情况1，我们可以把sum2中的其中一个数给sum1,这样就相当于出现一次的数字有偶数个，那么就可以分了。比如:`1 1 1 2`我们分为两个集合`A:1 1 2,B:1`,分的时候把出现次数为3的分给自己对立的集合。

对于情况2，因为出现次数为偶数，所以把出现次数为1的数平均分配给两个集合即可。

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int a[N];
char ans[N];
int main()
{
    int n;
    map<int, int> mp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    int sum1 = 0, sum2 = 0;
    for (auto num : mp)
    {
        if (num.second == 1)
            sum1++;
        if (num.second > 2)
            sum2++;
    }
    int flag = 0, k = 0;
    if (sum1 % 2 == 0)
        flag = 1;
    else if (sum2)
    {
        flag = 1;
        k = 1;
    }
    puts(flag ? "YES" : "NO");
    int pos = 0;
    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mp[a[i]] == 1)
            {
                ans[i] = pos & 1 ? 'A' : 'B';
                pos++;
            }
            else if (mp[a[i]] > 2 && k)
            {
                ans[i] = 'A';
                k = 0;
            }
            else
                ans[i] = 'B';
        }
        for (int i = 1; i <= n; i++)
            putchar(ans[i]);
        puts("");
    }

    return 0;
}
```



 