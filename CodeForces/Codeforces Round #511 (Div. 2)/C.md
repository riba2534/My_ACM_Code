# 描述

Mr. F has nn positive integers, a1,a2,…,ana1,a2,…,an.

He thinks the greatest common divisor of these integers is too small. So he wants to enlarge it by removing some of the integers.

But this problem is too simple for him, so he does not want to do it by himself. If you help him, he will give you some scores in reward.

Your task is to calculate the minimum number of integers you need to remove so that the greatest common divisor of the remaining integers is bigger than that of all integers.

# Input

The first line contains an integer nn (2≤n≤3⋅1052≤n≤3⋅105) — the number of integers Mr. F has.

The second line contains nn integers, a1,a2,…,ana1,a2,…,an (1≤ai≤1.5⋅1071≤ai≤1.5⋅107).

# Output

Print an integer — the minimum number of integers you need to remove so that the greatest common divisor of the remaining integers is bigger than that of all integers.

You should not remove all of the integers.

If there is no solution, print «-1» (without quotes).

## input

```
3
1 2 4
```

## output

```
1
```

## input

```
4
6 9 15 30
```

## output

```
2
```

## input

```
3
1 1 1
```

## output

```
-1
```

## Note

> In the first example, the greatest common divisor is 11 in the beginning. You can remove 11 so that the greatest common divisor is enlarged to 22. The answer is 11.
>
> In the second example, the greatest common divisor is 33 in the beginning. You can remove 66 and 99 so that the greatest common divisor is enlarged to 1515. There is no solution which removes only one integer. So the answer is 22.
>
> In the third example, there is no solution to enlarge the greatest common divisor. So the answer is −1−1.

# 思路

先说题意，给你一堆数，设这些数的`gcd`为`g`,现在要把这些数的`gcd`这个值变大.

首先我们把这些数的`gcd`求出来,因为`a[i]`的范围是`1e5e7`,所以标记一下`a[i]/g`的出现次数.

然后遍历`1.5e7`，类似素数筛法,找出每一个的倍数出现了多少次，求个最大值，然后输出`n-ans`

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 1.5e7 + 10;
int a[N];
int vis[M], cnt[M];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, g = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        g = __gcd(g, a[i]);
    }
    for (int i = 1; i <= n; i++)
        cnt[a[i] / g]++;
    int ans = 0;
    for (int i = 2; i <= M; i++)
    {
        if (!vis[i])
        {
            int res = 0;
            for (int j = i; j < M; j += i)
            {
                vis[j] = 1;
                res += cnt[j];
            }
            ans = max(ans, res);
        }
    }
    printf("%d\n", ans ? n - ans : -1);
    return 0;
}
```

