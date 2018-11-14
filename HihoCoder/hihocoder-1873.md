### 描述

> A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position 0) and wants to get to the other bank (position 200). Luckily, there are 199 leaves (from position 1 to position 199) on the river, and the frog can jump between the leaves. When at position p, the frog can jump to position p+1 or position p+2.
>
> How many different ways can the small frog get to the bank at position 200? This is a classical problem. The solution is the 201st number of Fibonacci sequence. The Fibonacci sequence is constructed as follows: F1=F2=1;Fn=Fn-1+Fn-2.
>
> Now you can build some portals on the leaves. For each leaf, you can choose whether to build a portal on it. And you should set a destination for each portal. When the frog gets to a leaf with a portal, it will be teleported to the corresponding destination immediately. If there is a portal at the destination, the frog will be teleported again immediately. If some portal destinations form a cycle, the frog will be permanently trapped inside. Note that You cannot build two portals on the same leaf.
>
> Can you build the portals such that the number of different ways that the small frog gets to position 200 from position 0 is M?

### 输入

> There are no more than 100 test cases.
>
> Each test case consists of an integer M, indicating the number of ways that the small frog gets to position 200 from position 0. (0 ≤ M < 232)

### 输出

> For each test case:
>
> The first line contains a number K, indicating the number of portals.
>
> Then K lines follow. Each line has two numbers ai and bi, indicating that you place a portal at position ai and it teleports the frog to position bi.
>
> You should guarantee that 1 ≤ K, ai, bi ≤ 199, and ai ≠ aj if i ≠ j. If there are multiple solutions, any one of them is acceptable.

## 样例输入

```
0
1
5
```

## 样例输出

```
2
1 1
2 1
2
1 199
2 2
2
4 199
5 5
```

# 思路

先说题意，给你一个坐标轴，有一个青蛙，要从$0$这个位置跳到$200$这个位置，他的起始位置为$0$.

青蛙每次可以向后跳$1$步或者$2$步,现在你可以给某个点放置一个传送门，规定传送门的起始和终止位置，那么青蛙到达这个点后会从传送门的起点瞬移到传送门的终点，规定一个点最多只能放置一个传送门，如果一个传送门的终点有一个传送门，那么青蛙可以连续传送。

现在给出你一个方案数$M$，你需要在这个坐标轴上放置传送门，使得青蛙从$0$到$200$这个位置的方案数恰好为$M$

构造题，假设当前青蛙所在位置为$x$，因为他每次可以向后跳1或2步，那么构造两个门`(x,x+2)`,`(x+1,x)`，这样无论青蛙怎么跳，最后都会停在`x+2`这个位置上。那么方案数就变成了原来的一半。

所以我们可以根据$M$的奇偶性，当$M$为偶数的时候就构造`(x,x+2)`,`(x+1,x)`使得方案数变成原来的一半，当$M$为奇数的时候，就可以构造从当前点直接连到199，`(x,199)`,使得方案数减一，那么方案数就变成了偶数，按照原来的方法继续构造即可，一直到方案数为1时，直接给当前位置连接到199即可。

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pir;
int main()
{
    ll n;
    while (~scanf("%lld", &n))
    {
        if (n == 0)
            printf("2\n1 1\n2 1\n");
        else if (n == 1)
            printf("2\n1 199\n2 2\n");
        else
        {
            vector<pir> v;
            ll now = 1;
            while (n != 1)
            {
                if (n & 1)
                {
                    v.push_back(pir(now, 199));
                    now += 2;
                    v.push_back(pir(now, now + 2));
                    v.push_back(pir(now + 1, now));
                    now += 3;
                }
                else
                {
                    v.push_back(pir(now, now + 2));
                    v.push_back(pir(now + 1, now));
                    now += 3;
                }
                n >>= 1;
            }
            v.push_back(pir(now - 1, 199));
            printf("%lld\n", v.size());
            for (auto ans : v)
                printf("%lld %lld\n", ans.first, ans.second);
        }
    }
    return 0;
}

```

