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
const int N = 1e5 + 10;
set<int> se[N];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, op, x, k, s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            for (int i = 1; i <= (int)sqrt(x); i++)
            {
                if (x % i == 0)
                {
                    se[i].insert(x);
                    se[x / i].insert(x);
                }
            }
        }
        else
        {
            scanf("%d%d%d", &x, &k, &s);
            int sum = -1, ans = -1;
            if (x % k)
            {
                printf("%d\n", ans);
                continue;
            }
            auto it = se[k].upper_bound(s - x);
            if (se[k].empty() || it == se[k].begin())
            {
                printf("%d\n", ans);
                continue;
            }
            --it;
            for (; it != se[k].begin(); --it)
            {
                int v = *it;
                if (sum > x + v)
                    break;
                if (sum < (x ^ v))
                {
                    ans = v;
                    sum = x ^ v;
                }
            }
            if (sum < (x ^ *it))
                ans = *it;
            printf("%d\n", ans);
        }
    }
    return 0;
}