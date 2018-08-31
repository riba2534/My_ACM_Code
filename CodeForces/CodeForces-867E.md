# 描述

> You can perfectly predict the price of a certain stock for the next *N* days. You would like to profit on this knowledge, but only want to transact one share of stock per day. That is, each day you will either buy one share, sell one share, or do nothing. Initially you own zero shares, and you cannot sell shares when you don't own any. At the end of the *N* days you would like to again own zero shares, but want to have as much money as possible.
>

# Input

> Input begins with an integer *N* (2 ≤ *N* ≤ 3·105), the number of days.
>
> Following this is a line with exactly *N* integers *p*1, *p*2, ..., *p**N* (1 ≤ *p**i* ≤ 106). The price of one share of stock on the *i*-th day is given by *p**i*.
>

# Output

> Print the maximum amount of money you can end up with at the end of *N* days.
>

## input


```
9
10 5 4 7 9 12 6 2 10
```

## output

```
20
```

## input

```
20
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4
```

## output

```
41
```

## Note

> In the first example, buy a share at 5, buy another at 4, sell one at 9 and another at 12. Then buy at 2 and sell at 10. The total profit is  - 5 - 4 + 9 + 12 - 2 + 10 = 20.



# 思路

你知道未来n天的所有的股票在当天的价格，你在一天只能买入或者卖出一支股票，买入股票当天的价格的钱，卖出则获得当天的股票的价格的钱，让你使得最后的股票总收益最大，问最大的收益是多少.

我们肯定是要贪心的低买高卖，考虑用优先队列（小顶堆）维护这一过程，我们每次得到一个新的价格，将其和堆顶的价格比较，如果比堆顶的价格低，就直接放入堆中，如果比堆顶的价格高，就意味着我们可以提前以堆顶的价格买入一个物品，然后以当前价格卖出，因此我们可以算出本次收益加到总收益中，这样我们就要将堆顶pop掉，然后将本次价格push两次入堆，push两次是因为我们若以堆顶的价格买入，不一定最终是以当前价格卖出的，当前价格有可能只是我们贪心的一个跳板，例如价格1，2，3，10，如果我们以1买入，2卖出，3买入，10卖出我们只能获得8，然而如果我们以1买入，10卖出，2买入，3卖出就可以获得10，我们贪心的过程中肯定会1买入2卖出，而这次2卖出只是我们10卖出的跳板，并不一定是非要在2卖出，因此将某价格加入两次的作用分别是：

1. 做中间价
2. 做所有可能买入价中的一个（就和比堆顶低的价格直接扔入堆中一样的作用）

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
    //freopen("in.txt", "r", stdin);
    ll n, x;
    ll ans = 0;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        if (q.empty() || x <= q.top())
        {
            q.push(x);
        }
        else
        {
            ans += x - q.top();
            q.pop();
            q.push(x), q.push(x);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
```

