# 描述

> You are given two strings *s* and *t* consisting of small Latin letters, string *s* can also contain '?' characters.
>
> Suitability of string *s* is calculated by following metric:
>
> Any two letters can be swapped positions, these operations can be performed arbitrary number of times over any pair of positions. Among all resulting strings *s*, you choose the one with the largest number of non-intersecting occurrences of string *t*. Suitability is this number of occurrences.
>
> You should replace all '?' characters with small Latin letters in such a way that the suitability of string *s* is maximal.
>
> #Input
>
> The first line contains string *s* (1 ≤ |*s*| ≤ 106).
>
> The second line contains string *t* (1 ≤ |*t*| ≤ 106).
>
> #Output
>
> Print string *s* with '?' replaced with small Latin letters in such a way that suitability of that string is maximal.
>
> If there are multiple strings with maximal suitability then print any of them.



## input



```
?aa?
ab
```

## output



```
baab
```

## input

```
??b?
za
```

## output

```
azbz
```

## input

```
abcd
abacaba
```

## output

```
abcd
```

## Note

> In the first example string "baab" can be transformed to "abab" with swaps, this one has suitability of 2. That means that string "baab" also has suitability of 2.
>
> In the second example maximal suitability you can achieve is 1 and there are several dozens of such strings, "azbz" is just one of them.
>
> In the third example there are no '?' characters and the suitability of the string is 0.

# 思路

给你两个串s和t，s串中可能包含若干个`?`，现在已知s串中的字母可以任意交换位置，题目让你把`?`填满，使得最终的s串包含的t串最多。

我们可以用`vextor`存一下`?`的位置，然后贪心的不断的枚举t串中的字符，如果字符在a中存在则不填，否则填，直到把问号填完。

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[300];
int main()
{
    vector<int> pos;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            pos.push_back(i);
        a[s[i]]++;
    }
    int flag = 1;
    while (flag)
        for (char ch : t)
            if (a[ch])
                a[ch]--;
            else if (pos.size())
            {
                s[pos[pos.size() - 1]] = ch;
                pos.pop_back();
            }
            else
            {
                flag = 0;
                break;
            }
    cout << s << endl;

    return 0;
}
```

