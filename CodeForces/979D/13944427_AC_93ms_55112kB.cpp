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
#define inf 0x3f3f3f3f
typedef long long ll;
const int N = 2e5 + 10;
int a[N];
struct dicTree
{
    struct node
    {
        int next[2];
    } tree[N * 32];
    int minn[N]; //记录当前节点插入进来的最小的值
    int root, sz;
    int newnode()
    {
        tree[sz].next[0] = tree[sz].next[1] = -1;
        sz++;
        return sz - 1;
    }
    void init()
    {
        sz = 0;
        mem(minn, inf);
        root = newnode();
    }
    void insert(int x)
    {
        int p = x;
        int now = root;
        minn[now] = min(minn[now], p);
        for (int i = 31; i >= 0; i--)
        {
            int to = (x >> i) & 1;
            if (tree[now].next[to] == -1)
                tree[now].next[to] = newnode();
            now = tree[now].next[to];
            //printf("now=%d\n", now);
            minn[now] = min(minn[now], p);
            // printf("minn[%d]=%d\n", now, minn[now]);
        }
    }
    int find(int x, int p)
    {
        int now = root;
        if (minn[now] > p)
            return -1;
        for (int i = 31; i >= 0; i--)
        {
            int to = (x >> i) & 1;
            if (tree[now].next[to ^ 1] != -1 && minn[tree[now].next[to ^ 1]] <= p)
                to ^= 1;
            now = tree[now].next[to];
        }
        return minn[now];
    }
} ac;
int main()
{
    //freopen("in.txt", "r", stdin);
    int t, op, x, k, s;
    ac.init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            a[x] = 1;
            ac.insert(x);
        }
        else
        {
            scanf("%d%d%d", &x, &k, &s);
            if (x % k != 0)
            {
                puts("-1");
                continue;
            }
            if (k == 1)
            {
                printf("%d\n", ac.find(x, s - x));
                continue;
            }
            int maxx = -1, ans = -1;
            for (int v = k; v <= s - x; v += k)
                if (a[v] && (v ^ x) > maxx)
                {
                    maxx = v ^ x;
                    ans = v;
                }
            printf("%d\n", ans);
        }
    }
    return 0;
}