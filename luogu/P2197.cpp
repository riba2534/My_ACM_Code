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
typedef pair<int, int> pir;
const int N = 1e6 + 10;
int main()
{
   // freopen("in.txt", "r", stdin);
    int t, n, x;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            ans ^= x;
        }
        if (ans == 0)
            puts("No");
        else
            puts("Yes");
    }

    return 0;
}