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
const int N = 1e6 + 10;
multiset<int> s;
int a[N], ans1[N], ans2[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        s.clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (i <= k)
                s.insert(a[i]);
        }
        for (int i = 1; i <= n - k + 1; i++)
        {
            int j = i + k - 1;
            ans1[i] = *s.begin();
            ans2[i] = *s.rbegin();
            s.erase(s.find(a[i]));
            s.insert(a[j + 1]);
        }
        for (int i = 1; i <= n - k + 1; i++)
        {
            printf("%d ", ans1[i]);
        }
        printf("\n");
        for (int i = 1; i <= n - k + 1; i++)
        {
            printf("%d ", ans2[i]);
        }
        printf("\n");
    }
    return 0;
}