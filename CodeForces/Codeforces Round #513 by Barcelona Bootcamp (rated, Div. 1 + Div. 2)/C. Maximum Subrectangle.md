# 描述

> You are given two arrays aa and bb of positive integers, with length nn and mm respectively.
>
> Let cc be an n×mn×m matrix, where ci,j=ai⋅bjci,j=ai⋅bj.
>
> You need to find a subrectangle of the matrix cc such that the sum of its elements is at most xx, and its area (the total number of elements) is the largest possible.
>
> Formally, you need to find the largest number ss such that it is possible to choose integers x1,x2,y1,y2x1,x2,y1,y2 subject to 1≤x1≤x2≤n1≤x1≤x2≤n, 1≤y1≤y2≤m1≤y1≤y2≤m, 
>
> $\sum_{i=x_1}^{x_2}{\sum_{j=y_1}^{y_2}{c_{i,j}}} \leq x.$



# Input

> The first line contains two integers nn and mm (1≤n,m≤20001≤n,m≤2000).
>
> The second line contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤20001≤ai≤2000).
>
> The third line contains mm integers b1,b2,…,bmb1,b2,…,bm (1≤bi≤20001≤bi≤2000).
>
> The fourth line contains a single integer xx (1≤x≤2⋅1091≤x≤2⋅109).

## Output

> If it is possible to choose four integers x1,x2,y1,y2x1,x2,y1,y2 such that 1≤x1≤x2≤n1≤x1≤x2≤n, 1≤y1≤y2≤m1≤y1≤y2≤m, and ∑x2i=x1∑y2j=y1ci,j≤x∑i=x1x2∑j=y1y2ci,j≤x, output the largest value of (x2−x1+1)×(y2−y1+1)(x2−x1+1)×(y2−y1+1) among all such quadruplets, otherwise output 00.



### input

```
3 3
1 2 3
1 2 3
9
```

### output

```
4
```

### input

```
5 1
5 4 2 4 5
2
5
```

output

```
1
```

### Note

> Matrix from the first sample and the chosen subrectangle (of blue color):
>
> ![img](http://codeforces.com/predownloaded/ae/28/ae28666c932a1c7bf8dd7a7ad8f40adcd7290893.png)
>
> Matrix from the second sample and the chosen subrectangle (of blue color):
>
> ![img](http://codeforces.com/predownloaded/c1/6e/c16ecaf1ac759d218c5057e722c06961e38816be.png)

# 思路

给你两个数组$a[],b[]$,现在我们可以由这两个数组构造出一个矩阵$c$,矩阵$c$中的元素是$c[i][j]=a[i]*b[j]$

然后给你一个数$x$,让你在矩阵c中找出一个子矩阵，使得这个矩阵的面积最大，且满足这个子矩阵中所有元素之和小于x.

因为c中的每一个元素是由数组a和b推导出来的，所以我们要求矩阵c中的任意一个矩阵的和就可以通过a数组对应位置的和(就是c中的行)乘以b数组对应位置的和(就是c中的列).

我们枚举a数组和b数组的间隔，我们可以求出间隔为`0~n-1`和`0~m-1`的和的最小值(用前缀和实现).然后计算出`h[i]*c[j]<=x`的值的最大的`i*j`就是答案。



# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f
const ll N = 2000 + 10;
ll a[N], b[N], n, m, x;
ll h[N], c[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];
    }
    scanf("%lld", &x);
    mem(h, inf), mem(c, inf);
    for (ll l = 0; l <= n; l++)
    {
        for (ll i = 1; i + l <= n; i++)
        {
            ll j = i + l;
            h[l] = min(h[l], a[j] - a[i - 1]);
        }
    }
    for (ll l = 0; l <= m; l++)
    {
        for (ll i = 1; i + l <= m; i++)
        {
            ll j = i + l;
            c[l] = min(c[l], b[j] - b[i - 1]);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            if (h[i - 1] * c[j - 1] <= x)
                ans = max(ans, i * j);
    printf("%lld\n", ans);
    return 0;
}

```



