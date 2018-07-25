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
typedef long long ll;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
int pre[N], l, r, ans[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            pre[i] = i;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &l, &r);
            pre[r] = min(pre[r], l);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            pre[i] = min(pre[i], pre[i + 1]);
        }
        int pl = 1;
        set<int> val;
        for (int i = 1; i <= n; i++)
            val.insert(i);
        for (int i = 1; i <= n; i++)
        {
            while (pl < pre[i])
            {
                val.insert(ans[pl]);
                pl++;
            }
            ans[i] = *val.begin();
            val.erase(ans[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                printf("%d", ans[i]);
            else
                printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}