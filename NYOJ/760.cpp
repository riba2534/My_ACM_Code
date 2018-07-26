 
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
#define rson m + 1, r, rt << 1 | 1
#define inf 0x3f3f3f3f
typedef long long ll;
const int N = 100000 + 10;
map<int, int> vis;
int a[N], b[N], c[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        vis.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            vis[a[i]] = i;
        }
        int nn = 0, x;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            if (vis.find(x) != vis.end())
                b[nn++] = vis[x];
        }
        int len = 0;
        for (int i = 0; i < nn; i++)
        {
            int p = lower_bound(c, c + len, b[i]) - c;
            c[p] = b[i];
            if (p == len)
                len++;
        }
        printf("%d\n", len);
    }
    return 0;
}        