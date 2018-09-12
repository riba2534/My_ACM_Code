## 描述

> In a world where ordinary people cannot reach, a boy named "Koutarou" and a girl named "Sena" are playing a video game. The game system of this video game is quite unique: in the process of playing this game, you need to constantly face the choice, each time you choose the game will provide 1-31−3 options, the player can only choose one of them. **Each option has an effect on a "score" parameter in the game.** Some options will increase the score, some options will reduce the score, and some options will change the score to a value multiplied by -1−1 .
>
> That is, if there are three options in a selection, the score will be increased by 11, decreased by 11, or multiplied by -1−1. The score before the selection is 88. Then selecting option 11 will make the score become 99, and selecting option 22 will make the score 77 and select option 33 to make the score -8−8. **Note that the score has an upper limit of 100100 and a lower limit of -100−100.** If the score is 9999 at this time, an option that makes the score +2+2 is selected. After that, the score will change to 100100 and vice versa .
>
> After all the choices have been made, **the score will affect the ending of the game.** If the score is greater than or equal to a certain value kk, it will enter a good ending; if it is less than or equal to a certain value ll, it will enter the bad ending; if both conditions are not satisfied, it will enter the normal ending. Now, Koutarou and Sena want to play the good endings and the bad endings respectively. They refused to give up each other and finally decided to use the "one person to make a choice" way to play the game, Koutarou first choose. Now assume that they all know the initial score, the impact of each option, and the kk, ll values, and decide to choose in the way that works best for them. (That is, they will try their best to play the ending they want. **If it's impossible, they would rather normal ending than the ending their rival wants.)**
>
> Koutarou and Sena are playing very happy, but I believe you have seen through the final ending. Now give you the initial score, the kk value, the ll value, and the effect of each option on the score. Can you answer the final ending of the game?

### Input

> The first line contains four integers n,m,k,ln,m,k,l（1\le n \le 10001≤n≤1000, -100 \le m \le 100−100≤m≤100 , -100 \le l < k \le 100−100≤l<k≤100）, represents the number of choices, the initial score, the minimum score required to enter a good ending, and the highest score required to enter a bad ending, **respectively**.
>
> Each of the next nn lines contains three integers a,b,ca,b,c（a\ge 0a≥0 , b\ge0b≥0 ,c=0c=0 or c=1c=1）,indicates the options that appear in this selection,in which a=0a=0 means there is no option to increase the score in this selection, a>0a>0 means there is an option in this selection to increase the score by aa ; b=0b=0 means there is no option to decrease the score in this selection, b>0b>0 means there is an option in this selection to decrease the score by bb; c=0c=0 means there is no option to multiply the score by -1−1 in this selection , c=1c=1 means there is exactly an option in this selection to multiply the score by -1−1. **It is guaranteed that a,b,ca,b,c are not equal to 00 at the same time**.

### Output

> One line contains the final ending of the game. If it will enter a good ending,print `"Good Ending"`(without quotes); if it will enter a bad ending,print `"Bad Ending"`(without quotes);otherwise print `"Normal Ending"`(without quotes).

#### 样例输入1

```
3 -8 5 -5
3 1 1
2 0 1
0 2 1
```

#### 样例输出1

```
Good Ending
```

#### 样例输入2

```
3 0 10 3
0 0 1
0 10 1
0 2 1
```

#### 样例输出2

```
Bad Ending
```

#### 题目来源

[ACM-ICPC 2018 徐州赛区网络预赛](https://nanti.jisuanke.com/?kw=ACM-ICPC%202018%20%E5%BE%90%E5%B7%9E%E8%B5%9B%E5%8C%BA%E7%BD%91%E7%BB%9C%E9%A2%84%E8%B5%9B)

# 思路

有两个人A,B在玩游戏，他们要玩n回合游戏，游戏的初试分数为m，当游戏结束时A的分数为`[k,100]`这个区间内，A获胜，输出`Good Ending`,如果最后的分数在`[-100,l]`这个区间内，则输出`Bad Ending`.

第一行输出`n,m,k,l`，接下来有n行，每行三个数`a,b,c`,说明在当前状态下，可以有三个选择，分别是给当前的游戏积分增加a积分，减少b积分，或者变成当前积分的相反数.

题目问你在n回合之后，谁会获胜。

我们可以定义三个值表示最后的结果:0,1,2分别代表B胜，A胜，和平局。

我们可以记忆化搜索，状态为：`dp[i][j]`表示第i轮，分数为j的状态。



# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const int N = 1e3 + 10;
int a[N], b[N], c[N];
int dp[N][305];
int n, m, k, l;
unordered_map<int, int> id;
//pos为当前位置，sco为当前分数
int dfs(int pos, int sco)
{
    if (pos == n + 1)
    {
        if (sco >= k)
            return 2; //A胜
        else if (sco <= l)
            return 0; //B胜
        else
            return 1; //平局
    }
    if (~dp[pos][id[sco]])
        return dp[pos][id[sco]];
    if (pos & 1) //A面临的局面
    {
        int ret = 0, tmp = sco;
        tmp = min(100, sco + a[pos]); //加上后最多为100分
        if (a[pos])                   //当前局面的a不为0
            ret = max(ret, dfs(pos + 1, tmp));
        tmp = max(-100, sco + b[pos]); //减少后最少为-100
        if (b[pos])
            ret = max(ret, dfs(pos + 1, tmp));
        if (c[pos])
            ret = max(ret, dfs(pos + 1, -sco));
        return dp[pos][id[sco]] = ret;
    }
    else
    {
        int ret = 2, tmp = sco;
        tmp = min(100, sco + a[pos]); //加上后最多为100分
        if (a[pos])                   //当前局面的a不为0
            ret = min(ret, dfs(pos + 1, tmp));
        tmp = max(-100, sco + b[pos]); //减少后最少为-100
        if (b[pos])
            ret = min(ret, dfs(pos + 1, tmp));
        if (c[pos])
            ret = min(ret, dfs(pos + 1, -sco));
        return dp[pos][id[sco]] = ret;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int cnt = 0;
    for (int i = -100; i <= 100; i++)
        id[i] = ++cnt;
    scanf("%d%d%d%d", &n, &m, &k, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        b[i] = -b[i];
    }
    mem(dp, -1);
    int ans = dfs(1, m);
    if (ans == 2)
        puts("Good Ending");
    else if (ans == 1)
        puts("Normal Ending");
    else
        puts("Bad Ending");
    return 0;
}
```

