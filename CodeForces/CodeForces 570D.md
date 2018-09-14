# 描述

> Roman planted a tree consisting of *n* vertices. Each vertex contains a lowercase English letter. Vertex 1 is the root of the tree, each of the *n* - 1 remaining vertices has a parent in the tree. Vertex is connected with its parent by an edge. The parent of vertex *i* is vertex *p**i*, the parent index is always less than the index of the vertex (i.e., *p**i* < *i*).
>
> The depth of the vertex is the number of nodes on the path from the root to *v* along the edges. In particular, the depth of the root is equal to 1.
>
> We say that vertex *u* is in the subtree of vertex *v*, if we can get from *u* to *v*, moving from the vertex to the parent. In particular, vertex *v* is in its subtree.
>
> Roma gives you *m* queries, the *i*-th of which consists of two numbers *v**i*, *h**i*. Let's consider the vertices in the subtree *v**i* located at depth *h**i*. Determine whether you can use the letters written at these vertices to make a string that is a palindrome. The letters that are written in the vertexes, can be rearranged in any order to make a palindrome, but all letters should be used.

# Input

> The first line contains two integers *n*, *m* (1 ≤ *n*, *m* ≤ 500 000) — the number of nodes in the tree and queries, respectively.
>
> The following line contains *n* - 1 integers *p*2, *p*3, ..., *p**n* — the parents of vertices from the second to the *n*-th (1 ≤ *p**i* < *i*).
>
> The next line contains *n* lowercase English letters, the *i*-th of these letters is written on vertex *i*.
>
> Next *m* lines describe the queries, the *i*-th line contains two numbers *v**i*, *h**i* (1 ≤ *v**i*, *h**i* ≤ *n*) — the vertex and the depth that appear in the *i*-th query.

# Output

> Print *m* lines. In the *i*-th line print "Yes" (without the quotes), if in the *i*-th query you can make a palindrome from the letters written on the vertices, otherwise print "No" (without the quotes).

## input

```
6 5
1 1 1 3 3
zacccd
1 1
3 3
4 1
6 1
1 2
```

## output

```
Yes
No
Yes
Yes
Yes
```

## Note

> String *s* is a palindrome if reads the same from left to right and from right to left. In particular, an empty string is a palindrome.
>
> Clarification for the sample test.
>
> In the first query there exists only a vertex 1 satisfying all the conditions, we can form a palindrome "z".
>
> In the second query vertices 5 and 6 satisfy condititions, they contain letters "с" and "d" respectively. It is impossible to form a palindrome of them.
>
> In the third query there exist no vertices at depth 1 and in subtree of 4. We may form an empty palindrome.
>
> In the fourth query there exist no vertices in subtree of 6 at depth 1. We may form an empty palindrome.
>
> In the fifth query there vertices 2, 3 and 4 satisfying all conditions above, they contain letters "a", "c" and "c". We may form a palindrome "cac".

# 思路

题目给了一个$n$个节点的树,每一个节点上都有一个字母。然后有$m$组查询，每次查询`v h`，代表查询以`v`为根的子树，在原来的树中深度为`h`的点上面的字母能否构成一个回文串。

首先能够成一个回文串的条件是: **最多只有一个字母出现奇数次**

首先我们对这一棵树按照`dfs`序进行深搜，存储一下，进入这个点的时间戳`l[i]`和离开这个点的时间戳`r[i]`，这样当一个点的时间戳`>=l[i] && <=r[i]`就说明这个点是原来的点的子节点。

在`dfs`的时候用`vector`存储一下当前这一层的每一个字母出现的点的时间戳`l[i]`.

最后查询的时候遍历一下每一个字母二分找到这一层中，`>=l[x] && <=r[x]`的个数，这样就知道满足条件的字母出现了多少次，然后我们利用最多只有一个字母出现奇数次的性质来判断是可以构成回文串。

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pir;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 5e5 + 10;
vector<int> e[N];
vector<int> dp[N][27];
int l[N], r[N], id, dep[N];
char s[N];
int n, m;
void dfs(int u, int deep)
{
    dep[u] = deep;
    l[u] = ++id;
    dp[deep][s[u]].push_back(id);
    for (auto v : e[u])
        dfs(v, deep + 1);
    r[u] = id;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int x;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &x);
        e[x].push_back(i);
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i] - 'a';
    dfs(1, 1);
    int h;
    while (m--)
    {
        scanf("%d%d", &x, &h);
        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            int num = upper_bound(dp[h][i].begin(), dp[h][i].end(), r[x]) - lower_bound(dp[h][i].begin(), dp[h][i].end(), l[x]);
            if (num & 1)
            {
                sum++;
                if (sum > 1)
                    break;
            }
        }
        if (sum > 1)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
```

