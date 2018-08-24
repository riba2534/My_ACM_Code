# 描述

> Given a string, we need to find the total number of its distinct substrings.
>

# Input

> T- number of test cases. T<=20;
> Each test case consists of one string, whose length is <= 1000
>

# Output

> For each test case output one number saying the number of distinct substrings.
>

# **Sample Input:**
```
2
CCCCC
ABABA
```
# **Sample Output:**
```
5
9
```
> Explanation for the testcase with string ABABA: 
> len=1 : A,B
> len=2 : AB,BA
> len=3 : ABA,BAB
> len=4 : ABAB,BABA
> len=5 : ABABA
> Thus, total number of distinct substrings is 9.

# 思路

给出一个字符串，求其中不同的子串个数.

一个串的子串个数为`n*(n+1)/2`，减去后缀的相同前缀所作的贡献每一个`height[i]`即为答案.

引用论文:

![TIM截图20180824164632.png](https://i.loli.net/2018/08/24/5b7fc5f86a000.png) 

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
char s[N];
int a[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < n; i++)
            a[i] = s[i];
        a[n] = 0;
        da(a, sa, rak, height, n, 128);
        int ans = n * (n + 1) / 2;
        for (int i = 2; i <= n; i++)
            ans -= height[i];
        printf("%d\n", ans);
    }
    return 0;
}
```

