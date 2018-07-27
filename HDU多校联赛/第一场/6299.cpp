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
struct node
{
    int l, r, add;
} a[N];
char s[N];
bool cmp(node A, node B)
{
    if (A.l >= A.r && B.l < B.r)
        return false;
    if (A.l < A.r && B.l >= B.r)
        return true;
    if (A.l >= A.r && B.l >= B.r)
        return A.r > B.r;
    //if (A.l <= B.r && B.l <= B.r)
    return A.l < B.l;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", s);
            int len = strlen(s);
            a[i].l = a[i].r = a[i].add = 0;
            for (int j = 0; j < len; j++)
            {
                if (s[j] == '(')
                    a[i].r++;
                else
                {
                    if (a[i].r > 0)
                    {
                        a[i].r--;
                        a[i].add++;
                    }
                    else
                        a[i].l++;
                }
            }
        }
        sort(a + 1, a + n + 1, cmp);
        int ans = 0, now = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].l > now)
                a[i].l = now;
            ans += a[i].l + a[i].add;
            now -= a[i].l;
            now += a[i].r;
        }
        printf("%d\n", ans * 2);
    }

    return 0;
}