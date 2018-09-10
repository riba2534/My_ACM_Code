# 描述

> There's a beach in the first quadrant. And from time to time, there are sea waves. A wave ( xx , yy ) means the wave is a rectangle whose vertexes are ( 00 , 00 ), ( xx , 00 ), ( 00 , yy ), ( xx , yy ). Every time the wave will wash out the trace of former wave in its range and remain its own trace of ( xx , 00 ) -> ( xx , yy ) and ( 00 , yy ) -> ( xx , yy ). Now the toad on the coast wants to know the total length of trace on the coast after n waves. It's guaranteed that a wave will not cover the other completely.

### Input

> The first line is the number of waves n(n \le 50000)n(n≤50000).
>
> The next nn lines，each contains two numbers xx yy ,( 0 < x0<x , y \le 10000000y≤10000000 )，the ii-th line means the ii-th second there comes a wave of ( xx , yy ), it's guaranteed that when 1 \le i1≤i , j \le nj≤n ，x_i \le x_jxi≤xj and y_i \le y_jyi≤yj don't set up at the same time.

### Output

> An Integer stands for the answer.

### Hint：

> As for the sample input, the answer is 3+3+1+1+1+1=103+3+1+1+1+1=10

[![img](https://res.jisuanke.com/img/upload/36b67f52cd1e0e6ac91ed22078f0c564f9c8a8aa.png)](https://res.jisuanke.com/img/upload/36b67f52cd1e0e6ac91ed22078f0c564f9c8a8aa.png)

#### 样例输入

```
3
1 4
4 1
3 3
```

#### 样例输出

```
10
```

#### 题目来源

[ACM-ICPC 2018 徐州赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E5%BE%90%E5%B7%9E%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

题目定义了海的波浪是一个矩形，每一次给定一个坐标，波浪就会形成一个原点和当前点的矩形。一浪接着一浪，新的矩形就可能部分覆盖住原来的矩形，题目保证任意两个矩形都不相互覆盖，现在求在经过n次波浪之后，现在留下来的矩形的边长是多少。

因为题目保证了两个矩形一定不相互完全覆盖。我们知道新的波浪会覆盖以前的波浪，那么最后一个波浪一定没有被覆盖，是完整的矩形，所以我们先存一下每个波浪的坐标，然后倒着来。

用两个`set`来维护矩形的横坐标和纵坐标，首先把0插入到两个`set`之中，然后每一次查询比当前横纵坐标小的第一个值(可以先用set.lower_bound查出大于等于它的第一个数，然后迭代器--)，由于题目保证了不相互覆盖，那么查到的横纵坐标的差的绝对值就可以累加到答案中，然后再把当前的横纵坐标插入.

累加完成后就是答案。



# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef pair<int, int> pir;
const int N = 1e5 + 10;
struct node
{
    int a, b;
} e[N];
set<int> sx, sy;
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        e[i].a = a, e[i].b = b;
    }
    sx.insert(0), sy.insert(0);
    ll ans = 0;
    for (int i = n; i >= 1; i--)
    {
        a = e[i].a, b = e[i].b;
        auto it = sx.lower_bound(a);
        --it;
        ans += (a - *it);
        sx.insert(a);
        it = sy.lower_bound(b);
        --it;
        ans += (b - *it);
        sy.insert(b);
    }
    printf("%lld\n", ans);
    return 0;
}
```



