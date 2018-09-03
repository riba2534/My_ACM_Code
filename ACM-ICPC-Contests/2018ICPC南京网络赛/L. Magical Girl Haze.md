## 描述

> There are NN cities in the country, and MM directional roads from uu to v(1\le u, v\le n)v(1≤u,v≤n). Every road has a distance c_ici. Haze is a Magical Girl that lives in City 11, she can choose no more than KK roads and make their distances become 00. Now she wants to go to City NN, please help her calculate the minimum distance.

### Input

> The first line has one integer T(1 \le T\le 5)T(1≤T≤5), then following TT cases.
>
> For each test case, the first line has three integers N, MN,M and KK.
>
> Then the following MM lines each line has three integers, describe a road, U_i, V_i, C_iUi,Vi,Ci. There might be multiple edges between uu and vv.
>
> It is guaranteed that N \le 100000, M \le 200000, K \le 10N≤100000,M≤200000,K≤10,
> 0 \le C_i \le 1e90≤Ci≤1e9. There is at least one path between City 11 and City NN.

### Output

> For each test case, print the minimum distance.

#### 样例输入

```
1
5 6 1
1 2 2
1 3 4
2 4 3
3 4 1
3 5 6
4 5 2
```

#### 样例输出

```
3
```

#### 题目来源

[ACM-ICPC 2018 南京赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E5%8D%97%E4%BA%AC%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

给出一个$n$个点$m$条边的有向图，要从$1$点走到$n$点，有$k$次机会使得某一条边的花费变成$0$,求从$1$走到$n$的最小花费.

题意和[BZOJ2763飞行路线(分层最短路，dijkstra的堆优化)](https://blog.csdn.net/riba2534/article/details/82353768)一模一样，都是分层最短路.

我们需要利用类似动态规划的思想来进行转移。

我们定义:

- $dis[i][j]$：从起点`st`到`i`点，使用了`j`次优惠机会所使用的最小花费.
- $vis[i][j]$：从起点`st`到`i`点，使用了`j`次优惠机会这个状态有没有被标记

我们需要对普通的迪杰斯特拉转移的时候进行一些改变：

1. 不使用免费机会的时候：

   ```cpp
   如果 到点u的花费dis[u][k]+从u到v的边权w<到v的边权dis[v][k]
   	正常转移更新:dis[v][k]=dis[u][k]+w
   	加入堆q.push(node(v,k,dis[v][k]))
   ```

2. 使用免费机会的时候:

   ```cpp
   如果 到点u的时候使用了k次机会的花费dis[u][k]<到v点的时候使用了k+1次机会的边权dis[v][k+1]
   	这条边免费更新dis[v][k+1]=dis[u][k]
   	加入堆q.push(node(v,k+1,dis[v+1][k]))
   ```

剩下的就是迪杰斯特拉的堆优化模板了。

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
int first[N], tot;
int n, m, k;
struct edge
{
    int v, w, next;
} e[N * 2];
void add_edge(int u, int v, int w)
{
    e[tot].v = v, e[tot].w = w;
    e[tot].next = first[u];
    first[u] = tot++;
}
void init()
{
    mem(first, -1);
    tot = 0;
}
struct node
{
    int id, k, now;
    node() {}
    node(int _id, int _k, int _now)
    {
        id = _id, k = _k, now = _now;
    }
    bool friend operator<(node a, node b)
    {
        return a.now > b.now;
    }
};
int dis[N][12], vis[N][12];
void dijkstra(int st)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dis[i][j] = inf;
            vis[i][j] = 0;
        }
    }
    dis[st][0] = 0;
    priority_queue<node> q;
    q.push(node(st, 0, 0));
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        if (!vis[u.id][u.k])
        {
            vis[u.id][u.k] = 1;
            for (int i = first[u.id]; ~i; i = e[i].next)
            {
                int v = e[i].v, w = e[i].w;
                if (!vis[v][u.k] && dis[u.id][u.k] + w < dis[v][u.k])
                {
                    dis[v][u.k] = dis[u.id][u.k] + w;
                    q.push(node(v, u.k, dis[v][u.k]));
                }
                if (u.k < k && !vis[v][u.k] && dis[u.id][u.k] < dis[v][u.k + 1])
                {
                    dis[v][u.k + 1] = dis[u.id][u.k];
                    q.push(node(v, u.k + 1, dis[v][u.k + 1]));
                }
            }
        }
    }
}
void solve()
{
    int u, v, w;
    scanf("%d%d%d", &n, &m, &k);
    init();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    dijkstra(1);
    int ans = inf;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dis[n][i]);
    printf("%d\n", ans);
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

