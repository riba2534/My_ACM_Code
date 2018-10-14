# 描述

> Andryusha goes through a park each day. The squares and paths between them look boring to Andryusha, so he decided to decorate them.
>
> The park consists of *n* squares connected with (*n* - 1) bidirectional paths in such a way that any square is reachable from any other using these paths. Andryusha decided to hang a colored balloon at each of the squares. The baloons' colors are described by positive integers, starting from 1. In order to make the park varicolored, Andryusha wants to choose the colors in a special way. More precisely, he wants to use such colors that if *a*, *b* and *c* are distinct squares that *a* and *b* have a direct path between them, and *b* and *c* have a direct path between them, then balloon colors on these three squares are distinct.
>
> Andryusha wants to use as little different colors as possible. Help him to choose the colors!

# Input

> The first line contains single integer *n* (3 ≤ *n* ≤ 2·105) — the number of squares in the park.
>
> Each of the next (*n* - 1) lines contains two integers *x* and *y* (1 ≤ *x*, *y* ≤ *n*) — the indices of two squares directly connected by a path.
>
> It is guaranteed that any square is reachable from any other using the paths.

# Output

> In the first line print single integer *k* — the minimum number of colors Andryusha has to use.
>
> In the second line print *n* integers, the *i*-th of them should be equal to the balloon color on the *i*-th square. Each of these numbers should be within range from 1 to *k*.

## input

```
3
2 3
1 3
```

## output

```
3
1 3 2 
```

## input

```
5
2 3
5 3
4 3
1 3
```

## output

```
5
1 3 2 5 4 
```

## input

```
5
2 1
3 2
4 3
5 4
```

## output

```
3
1 2 3 1 2 
```

## Note

> In the first sample the park consists of three squares: 1 → 3 → 2. Thus, the balloon colors have to be distinct.
>
> ![img](http://codeforces.com/predownloaded/15/d5/15d5e3019b81029bc9f906b57d39a5b644042072.png)Illustration for the first sample.
>
> In the second example there are following triples of consequently connected squares:
>
> - 1 → 3 → 2
> - 1 → 3 → 4
> - 1 → 3 → 5
> - 2 → 3 → 4
> - 2 → 3 → 5
> - 4 → 3 → 5
>
> We can see that each pair of squares is encountered in some triple, so all colors have to be distinct.
>
> ![img](http://codeforces.com/predownloaded/07/fa/07fa42e9aaad0fe29656db148493605d0dfcb30a.png)Illustration for the second sample.
>
> In the third example there are following triples:
>
> - 1 → 2 → 3
> - 2 → 3 → 4
> - 3 → 4 → 5
>
> We can see that one or two colors is not enough, but there is an answer that uses three colors only.
>
> ![img](http://codeforces.com/predownloaded/b7/0d/b70df28032774ef36bae4df1b307f5ef44e14e32.png)Illustration for the third sample.

# 思路

一棵树有n个节点，你需要给它的所有节点图上颜色。相邻三个节点不能有相同颜色，问最少需要多少种颜色。
相邻三个节点的意思是 节点x1与x2相邻，x2与x3相邻，那么x1与x3也相邻, x1,x2,x3颜色各不相同

我们容易推得，颜色的个数就是所有点的度数最大的度数+1.

使用bfs，每次从1开始涂色，把自己的父亲，和祖父标记一下，如果是自己的父亲或者祖父就换颜色，直到不是为止.



# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> e[N];
int vis[N], color[N], in[N], tot = 0;
int fmax(int a, int b, int c)
{
    return max(max(a, b), c);
}
void bfs(int u, int fa)
{

    int num = 1;
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        while (num == color[u] || num == color[fa])
            num++;
        color[v] = num++;
    }
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        bfs(v, u);
    }
}
int main()
{
    int n, u, v;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        in[u]++, in[v]++;
        tot = fmax(tot, in[u], in[v]);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    color[1] = 1;
    bfs(1, 0);
    tot++;
    printf("%d\n", tot);
    for (int i = 1; i <= n; i++)
        printf("%d ", color[i]);
    puts("");
    return 0;
}
```

