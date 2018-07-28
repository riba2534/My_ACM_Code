#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define LL long long
#define INF 1e9
#define N 200005
using namespace std;
int q, op, x, ans, now, a[N], k, mx, s, b[35], sz, minn[N], ch[N * 30][3];
void insert(int x)
{
    int p = x;
    for (int i = 0; i <= 30; i++)
        b[i] = x % 2, x /= 2;
    int u = 0;
    minn[0] = min(minn[0], p);
    for (int i = 30; i >= 0; i--)
    {
        if (!ch[u][b[i]])
        {
            ch[u][b[i]] = ++sz;
            minn[sz] = INF;
        }
        u = ch[u][b[i]];
        minn[u] = min(minn[u], p);
        //printf("p=%d\n", p);
    }
}
int find(int x, int p)
{
    for (int i = 0; i <= 30; i++)
        b[i] = x % 2, x /= 2;
    int u = 0;
    if (minn[0] > p)
        return -1;
    for (int i = 30; i >= 0; i--)
    {
        if (ch[u][b[i] ^ 1] && minn[ch[u][b[i] ^ 1]] <= p)
            u = ch[u][b[i] ^ 1];
        else
            u = ch[u][b[i]];
        // if (i == 0)
        //     return minn[u];
    }
    return minn[u];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &q);
    minn[0] = INF;
    while (q--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            a[x] = 1;
            insert(x);
        }
        else
        {
            scanf("%d%d%d", &x, &k, &s);
            if (x % k != 0)
            {
                printf("-1\n");
                continue;
            }
            if (k == 1)
            {
                printf("%d\n", find(x, s - x));
                continue;
            }
            mx = -1;
            ans = -1;
            for (int v = k; v <= s - x; v += k)
                if (a[v] && ((v ^ x) > mx))
                {
                    mx = v ^ x;
                    ans = v;
                }
            printf("%d\n", ans);
        }
    }
}