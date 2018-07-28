## 题目描述 

> 黑魔法咒语被描述为一个 长为 n 的，仅包含小写英文字母 'a'...'i' 的字符串，在托米所在的星球，魔法造成的每次有效伤害都是来自他的一个子序列，对于每一个 'a'... 'i' 的排列(共 9! 种)，若作为咒语的子序列出现, 就会造成 1 的伤害
>

## 输入描述:

>
> 一行输入一个字符串 s
>


## 输出描述:

>
> 一行输出一个数，表示伤害值
>




## 输入

```
aabcdefghi
```

## 输出

```
1
```

## 备注:

>
> |s| ≤  3000
>



# 思路

题目给出了一个字符串$s$，

给出了一个原串$t="abcdefghi"$,问在$t$的所有串的排列中，有多少个串是在$s$的子序列中出现的.

首先定义:

- `dp[i][j]`表示当前第`i`个位置向后跳转到字母`j`的位置

我们可以通过预处理,然后在枚举全排列，利用dp数组跳着找，也就是加速暴力的过程



# 代码

```cpp
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef long long ll;
const int N = 3e3 + 10;
const int inf = 0x3f3f3f3f;
int dp[N][10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            dp[i][j] = n;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            dp[i][s[j] - 'a'] = min(dp[i][s[j] - 'a'], j);
    string t = "abcdefghi";
    int ans = 0;
    do
    {
        int now = 0, cnt = 0;
        while (cnt < 9)
        {
            now = dp[now][t[cnt] - 'a'];
            if (now < n)
                cnt++;
            else
                break;
        }
        if (cnt == 9)
            ans++;

    } while (next_permutation(t.begin(), t.end()));
    cout << ans << endl;

    return 0;
}
```

