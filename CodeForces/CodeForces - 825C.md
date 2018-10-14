# 描述

> Although Inzane successfully found his beloved bone, Zane, his owner, has yet to return. To search for Zane, he would need a lot of money, of which he sadly has none. To deal with the problem, he has decided to hack the banks.
>
> ![img](http://codeforces.com/predownloaded/6b/b0/6bb03387ceed0952fedb347260e57c4c162683ff.png)
>
> There are *n* banks, numbered from 1 to *n*. There are also *n* - 1 wires connecting the banks. All banks are initially online. Each bank also has its initial strength: bank *i* has initial strength *a**i*.
>
> Let us define some keywords before we proceed. Bank *i* and bank *j* are neighboring if and only if there exists a wire directly connecting them. Bank *i* and bank *j* are semi-neighboring if and only if there exists an online bank *k* such that bank *i* and bank *k* are neighboring and bank *k* and bank *j* are neighboring.
>
> When a bank is hacked, it becomes offline (and no longer online), and other banks that are neighboring or semi-neighboring to it have their strengths increased by 1.
>
> To start his plan, Inzane will choose a bank to hack first. Indeed, the strength of such bank must not exceed the strength of his computer. After this, he will repeatedly choose some bank to hack next until all the banks are hacked, but he can continue to hack bank *x* if and only if all these conditions are met:
>
> 1. Bank *x* is online. That is, bank *x* is not hacked yet.
> 2. Bank *x* is neighboring to some offline bank.
> 3. The strength of bank *x* is less than or equal to the strength of Inzane's computer.
>
> Determine the minimum strength of the computer Inzane needs to hack all the banks.

# Input

> The first line contains one integer *n* (1 ≤ *n* ≤ 3·105) — the total number of banks.
>
> The second line contains *n* integers *a*1, *a*2, ..., *a**n* ( - 109 ≤ *a**i* ≤ 109) — the strengths of the banks.
>
> Each of the next *n* - 1 lines contains two integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*, *u**i* ≠ *v**i*) — meaning that there is a wire directly connecting banks *u**i* and *v**i*.
>
> It is guaranteed that the wires connect the banks in such a way that Inzane can somehow hack all the banks using a computer with appropriate strength.

# Output

> Print one integer — the minimum strength of the computer Inzane needs to accomplish the goal.

## input

```
5
1 2 3 4 5
1 2
2 3
3 4
4 5
```

## output

```
5
```

## input

```
7
38 -29 87 93 39 28 -55
1 2
2 5
3 2
2 4
1 7
7 6
```

## output

```
93
```

## input

```
5
1 2 7 6 7
1 5
5 3
3 4
2 4
```

## output

```
8
```

## Note

> In the first sample, Inzane can hack all banks using a computer with strength 5. Here is how:
>
> - Initially, strengths of the banks are [1, 2, 3, 4, 5].
> - He hacks bank 5, then strengths of the banks become [1, 2, 4, 5,  - ].
> - He hacks bank 4, then strengths of the banks become [1, 3, 5,  - ,  - ].
> - He hacks bank 3, then strengths of the banks become [2, 4,  - ,  - ,  - ].
> - He hacks bank 2, then strengths of the banks become [3,  - ,  - ,  - ,  - ].
> - He completes his goal by hacking bank 1.
>
> In the second sample, Inzane can hack banks 4, 2, 3, 1, 5, 7, and 6, in this order. This way, he can hack all banks using a computer with strength 93.

# 思路

给了一棵n个节点的树，每个节点有一个权值。定义两个概念:

- 半相邻：i节点和j节点直接有边相连
- 相邻：i和k有一条边,k和j有一条边则i和j相邻

每次挑一个节点hack掉，然后与他半相邻和相邻的所有的节点的权值会加1，然后这个点就成了`离线`状态。删点的规则是:

- x点还没被删
- x是离线的点的邻居
- x的权值小于等于你的初始强度

