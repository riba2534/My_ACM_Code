# 描述

> Dlsj is competing in a contest with n (0 < n \le 20)n(0<n≤20) problems. And he knows the answer of all of these problems.
>
> However, he can submit ii-th problem if and only if he has submitted (and passed, of course) s_isi problems, the p_{i, 1}pi,1-th, p_{i, 2}pi,2-th, ......, p_{i, s_i}pi,si-th problem before.(0 < p_{i, j} \le n,0 < j \le s_i,0 < i \le n)(0<pi,j≤n,0<j≤si,0<i≤n) After the submit of a problem, he has to wait for one minute, or cooling down time to submit another problem. As soon as the cooling down phase ended, he will submit his solution (and get "Accepted" of course) for the next problem he selected to solve or he will say that the contest is too easy and leave the arena.
>
> "I wonder if I can leave the contest arena when the problems are too easy for me."
> "No problem."
> —— CCF NOI Problem set
>
> If he submits and passes the ii-th problem on tt-th minute(or the tt-th problem he solve is problem ii), he can get t \times a_i + b_it×ai+bi points. (|a_i|, |b_i| \le 10^9)(∣ai∣,∣bi∣≤109).
>
> Your task is to calculate the maximum number of points he can get in the contest.

### Input

> The first line of input contains an integer, nn, which is the number of problems.
>
> Then follows nn lines, the ii-th line contains s_i + 3si+3 integers, a_i,b_i,s_i,p_1,p_2,...,p_{s_i}ai,bi,si,p1,p2,...,psias described in the description above.

### Output

> Output one line with one integer, the maximum number of points he can get in the contest.

### Hint

> In the first sample.
>
> On the first minute, Dlsj submitted the first problem, and get 1 \times 5 + 6 = 111×5+6=11 points.
>
> On the second minute, Dlsj submitted the second problem, and get 2 \times 4 + 5 = 132×4+5=13 points.
>
> On the third minute, Dlsj submitted the third problem, and get 3 \times 3 + 4 = 133×3+4=13 points.
>
> On the forth minute, Dlsj submitted the forth problem, and get 4 \times 2 + 3 = 114×2+3=11 points.
>
> On the fifth minute, Dlsj submitted the fifth problem, and get 5 \times 1 + 2 = 75×1+2=7 points.
>
> So he can get 11+13+13+11+7=5511+13+13+11+7=55 points in total.
>
> In the second sample, you should note that he doesn't have to solve all the problems.

#### 样例输入1

```
5
5 6 0
4 5 1 1
3 4 1 2
2 3 1 3
1 2 1 4
```

#### 样例输出1

```
55
```

#### 样例输入2

```
1
-100 0 0
```

#### 样例输出2

```
0
```

#### 题目来源

[ACM-ICPC 2018 南京赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E5%8D%97%E4%BA%AC%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

首先说题意。

要进行一场比赛，这场比赛中有$n$道题目，每一道题目有两个属性$a$和$b$，完成这一道题目所获得的分数为$t \times a+b$(t为时间戳)。但是有一些要求，对于某一道题目，要完成它，必须完成一些前置题目，只有做了前置题目，才可以完成当前的这道题。样例是如下给出的。首先给出一个数字代表$n$，接下来有$n$行，对于每一行首先给出两个数$a$和$b$代表这一道题目的两个属性，接下来给出一个数字$s$，代表完成这道题目之前要完成多少道题目，接下来有$s$个数字，代表这$s$道题目的具体编号是多少.

题目问你，该如何规划，可以使得获得的分数最大，最后输出这个分数。

我们可以看一下$n$的范围，发现只有$20$，所以可能是`状压dp`,我们利用二进制位为1代表这个位置的题目做了，二进制位为0代表当前位置的题目没有做。

对于这个题目，我们做出如下定义(以下`状态`均指二进制状态):

- $dp[state]$：代表解决的问题为`state`这个状态所能获得的最大分数
- $pre[i]$：表示要解决第$i$个问题，需要解决的问题集合，集合用二进制的状态表示
- $cnt[state]$：表示`state`这个状态已经解决的问题数量

那么我们考虑如何利用状态压缩进行转移.

```cpp
遍历 时间戳t=1...n
	遍历 题目编号j=0...n-1
		遍历 状态k=0...(1<<n)-1
			如果 状态k已经解决t-1个问题 且 状态k没有解决第j个问题 且 状态k已经解决了状态j的前置问题
				当k状态解决j问题后所得的值 >= 总状态数(跳过，因为所有的状态一共只有(1<<n))
					continue
				如果当前状态可以更新
					更新当前状态
					记录dp[状态]中的最大值
输出最大值		
```



# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 21;
/*
pre[i]:表示要解决第i个问题，需要解决的问题集合(二进制状态)
dp[state]:表示解决当前状态的问题最多能获得的分数(二进制状态)
cnt[state]:表示state这个状态已经解决的问题数量
*/
ll a[N], b[N], pre[N];
ll dp[N], cnt[N], n;
void solve()
{
    dp[0] = 0;
    ll ans = 0;
    for (ll t = 1; t <= n; t++) //枚举时间
    {
        for (ll j = 0; j < n; j++) //枚举每道题目
        {
            for (ll k = 0; k < (1 << n); k++) //从0～2^n-1个状态
            {
                //如果状态k已经解决t-1个问题 且 状态k没有解决第j个问题 且 状态k已经解决了状态j的前置问题
                if (cnt[k] == t - 1 && !((k >> j) & 1) && (k & pre[j]) == pre[j])
                {
                    if (k | (1 << j) >= (1 << n)) //当k状态解决j问题后所得的值 >= 总状态数就跳过，因为所有的状态一共只有(1<<n)
                        continue;
                    if (dp[k] + a[j] * t + b[j] >= dp[(k | (1 << j))])
                    {
                        dp[k | (1 << j)] = dp[k] + a[j] * t + b[j];
                        cnt[k + (1 << j)] = cnt[k] + 1;
                        ans = max(ans, dp[k + (1 << j)]);
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    ll t, k;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &a[i], &b[i], &t);
        while (t--)
        {
            scanf("%lld", &k);
            pre[i] |= (1 << (k - 1));
        }
    }
    solve();
    return 0;
}
```



