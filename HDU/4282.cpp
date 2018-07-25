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
int maxx, k;
inline int f(int x, int y, int z)
{
    return pow(x * 1.0, z * 1.0) + pow(y * 1.0, z * 1.0) + x * y * z - k;
}
int judge(int x, int z)
{
    int l = x + 1, r = maxx;
    if (f(x, l, z) > 0 || f(x, r, z) < 0)
        return 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int ans = f(x, m, z);
        if (ans == 0)
            return 1;
        else if (ans > 0)
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d", &k) && k)
    {
        int ans = 0;
        for (int z = 2; z < 31; z++)
        {
            maxx = pow(k * 1.0, 1.0 / z);
            for (int x = 1; x <= maxx; x++)
            {
                if (judge(x, z))
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}