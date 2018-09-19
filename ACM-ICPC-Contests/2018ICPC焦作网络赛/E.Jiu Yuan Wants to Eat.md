# 描述

> You ye Jiu yuan is the daughter of the Great GOD Emancipator. And when she becomes an adult, she will be queen of Tusikur, so she wanted to travel the world while she was still young. In a country, she found a small pub called Whitehouse. Just as she was about to go in for a drink, the boss Carola appeared. And ask her to solve this problem or she will not be allowed to enter the pub. The problem description is as follows:
>
> There is a tree with nn nodes, each node ii contains weight a[i]a[i], the initial value of a[i]a[i] is 00. The root number of the tree is 11. Now you need to do the following operations:
>
> 1)1) Multiply all weight on the path from uu to vv by xx
>
> 2)2) For all weight on the path from uu to vv, increasing xx to them
>
> 3)3) For all weight on the path from uu to vv, change them to the **bitwise NOT** of them
>
> 4)4) Ask the sum of the weight on the path from uu to vv
>
> The answer modulo 2^{64}264.
>
> Jiu Yuan is a clever girl, but she was not good at algorithm, so she hopes that you can help her solve this problem. Ding\backsim\backsim\backsim∽∽∽
>
> The **bitwise NOT** is a unary operation that performs logical negation on each bit, forming the ones' complement of the given binary value. Bits that are 00 become 11, and those that are 11 become 00. For example:
>
> NOT 0111 (decimal 7) = 1000 (decimal 8)
>
> NOT 10101011 = 01010100

### Input

> The input contains multiple groups of data.
>
> For each group of data, the first line contains a number of nn, and the number of nodes.
>
> The second line contains (n - 1)(n−1) integers b_ibi, which means that the father node of node (i +1)(i+1) is b_ibi.
>
> The third line contains one integer mm, which means the number of operations，
>
> The next mm lines contain the following four operations:
>
> At first, we input one integer opt
>
> 1)1) If opt is 11, then input 33 integers, u, v, xu,v,x, which means multiply all weight on the path from uu to vv by xx
>
> 2)2) If opt is 22, then input 33 integers, u, v, xu,v,x, which means for all weight on the path from uu to vv, increasing xx to them
>
> 3)3) If opt is 33, then input 22 integers, u, vu,v, which means for all weight on the path from uu to vv, change them to the **bitwise NOT** of them
>
> 4)4) If opt is 44, then input 22 integers, u, vu,v, and ask the sum of the weights on the path from uu to vv
>
> 1 \le n,m,u,v \le 10^51≤n,m,u,v≤105
>
> 1 \le x < 2^{64}1≤x<264

### Output

> For each operation 44, output the answer.

#### 样例输入

```
7
1 1 1 2 2 4
5
2 5 6 1
1 1 6 2
4 5 6
3 5 2
4 2 2
2
1
4
3 1 2
4 1 2
3 1 1
4 1 1
```

#### 样例输出

```
5
18446744073709551613
18446744073709551614
0
```

#### 题目来源

[ACM-ICPC 2018 焦作赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E7%84%A6%E4%BD%9C%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

给你一棵树，你要支持如下操作:

- `1 u v x`:在树上u到v路径上的所有点的值增加v
- `2 u v x`:在树上u到v路径上的所有点的值乘v
- `3 u v`:在树上u到v路径上的所有点的值按位取反
- `4 u v`:查询u到v路径上的所有点权和

要求所有的操作对于$2^{64}$取模。

1 2 操作是树链剖分的经典操作。

那么3操作，按位取反就可以转化为两个操作，先给这个值+1在乘以-1.

线段树维护的时候在线段树`pushdown`向下更新的时候,先更新区间和的左右儿子，根据我们规定的优先度，**儿子的值=此刻儿子的值\*爸爸的乘法lazy+儿子的区间长度*爸爸的加法lazy**，然后再分别维护乘法的lazy和加法的lazy，最后取消标记

在`update`更新的时候，当更新到乘法的时候，需要更新**区间和，乘法lazy和加法lazy**;当更新加法的时候，只需要更新**区间和**和**加法的lazy**就可以了。

剩下的就是树剖的经典操作了，取模因为用`unsigned long long`会自动溢出，不用管.

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define mem(a, b) memset(a, b, sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
const ull N = 1e5 + 10;
ull n, m;
ull first[N], tot;
ull son[N], id[N], fa[N], cnt, dep[N], siz[N], top[N];
ull mul[N << 2], add[N << 2], sum[N << 2];
ull res = 0;
struct edge
{
    ull v, next;
} e[N * 2];
void add_edge(ull u, ull v)
{
    e[tot].v = v;
    e[tot].next = first[u];
    first[u] = tot++;
}
void init()
{
    mem(first, -1);
    tot = 0;
    cnt = 0;
}
void pushup(ull rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(ull l, ull r, ull rt)
{
    mul[rt] = 1;
    add[rt] = 0;
    if (l == r)
    {
        sum[rt] = 0;
        return;
    }
    ull m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(ull l, ull r, ull rt)
{
    ull m = (l + r) >> 1;
    sum[rt << 1] = sum[rt << 1] * mul[rt] + add[rt] * (m - l + 1);
    sum[rt << 1 | 1] = sum[rt << 1 | 1] * mul[rt] + add[rt] * (r - m);
    mul[rt << 1] *= mul[rt];
    mul[rt << 1 | 1] *= mul[rt];
    add[rt << 1] = add[rt << 1] * mul[rt] + add[rt];
    add[rt << 1 | 1] = add[rt << 1 | 1] * mul[rt] + add[rt];
    mul[rt] = 1;
    add[rt] = 0;
}
void update1(ull L, ull R, ull k, ull l, ull r, ull rt) //乘法
{
    if (L <= l && r <= R)
    {
        sum[rt] *= k;
        mul[rt] *= k;
        add[rt] *= k;
        return;
    }
    pushdown(l, r, rt);
    ull m = (l + r) >> 1;
    if (L <= m)
        update1(L, R, k, lson);
    if (R > m)
        update1(L, R, k, rson);
    pushup(rt);
    return;
}
void update2(ull L, ull R, ull k, ull l, ull r, ull rt) //加法
{
    if (L <= l && r <= R)
    {
        add[rt] += k;
        sum[rt] += k * (r - l + 1);
        return;
    }
    pushdown(l, r, rt);
    ull m = (l + r) >> 1;
    if (L <= m)
        update2(L, R, k, lson);
    if (R > m)
        update2(L, R, k, rson);
    pushup(rt);
    return;
}
void query(ull L, ull R, ull l, ull r, ull rt)
{
    if (L <= l && r <= R)
    {
        res += sum[rt];
        return;
    }
    pushdown(l, r, rt);
    ull m = (l + r) >> 1;
    if (L <= m)
        query(L, R, lson);
    if (R > m)
        query(L, R, rson);
}

void dfs1(ull u, ull f, ull deep)
{
    dep[u] = deep;
    fa[u] = f;
    siz[u] = 1;
    son[u] = 0;
    ull maxson = 0; //不能为-1,因为ull没有负数
    for (ull i = first[u]; ~i; i = e[i].next)
    {
        ull v = e[i].v;
        if (v == f)
            continue;
        dfs1(v, u, deep + 1);
        siz[u] += siz[v];
        if (siz[v] > maxson)
        {
            son[u] = v;
            maxson = siz[v];
        }
    }
}
void dfs2(ull u, ull topf)
{
    id[u] = ++cnt;
    top[u] = topf;
    if (!son[u])
        return;
    dfs2(son[u], topf);
    for (ull i = first[u]; ~i; i = e[i].next)
    {
        ull v = e[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
void updrange1(ull x, ull y, ull k) //u-->v乘x
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update1(id[top[x]], id[x], k, 1, n, 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update1(id[x], id[y], k, 1, n, 1);
}
void updrange2(ull x, ull y, ull k) //u-->v加x
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update2(id[top[x]], id[x], k, 1, n, 1);

        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update2(id[x], id[y], k, 1, n, 1);
}
ull qrange(ull x, ull y)
{
    ull ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res = 0;
        query(id[top[x]], id[x], 1, n, 1);
        ans += res;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) //使x深度较小
        swap(x, y);
    res = 0;
    query(id[x], id[y], 1, n, 1);
    ans += res;
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ull op, u, v, x;
    while (~scanf("%llu", &n))
    {
        init();
        for (ull i = 2; i <= n; i++)
        {
            scanf("%llu", &x);
            add_edge(x, i);
            add_edge(i, x);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        build(1, n, 1);
        scanf("%llu", &m);
        while (m--)
        {
            scanf("%llu%llu%llu", &op, &u, &v);
            if (op == 1)
            {
                scanf("%llu", &x);
                updrange1(u, v, x);
            }
            else if (op == 2)
            {
                scanf("%llu", &x);
                updrange2(u, v, x);
            }
            else if (op == 3)
            {
                updrange2(u, v, 1);
                updrange1(u, v, -1);
            }
            else if (op == 4)
            {
                printf("%llu\n", qrange(u, v));
            }
        }
    }
    return 0;
}
```

