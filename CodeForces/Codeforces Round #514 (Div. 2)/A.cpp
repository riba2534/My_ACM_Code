#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 1e5 + 10;
struct node
{
    int l, r;
} e[N];
bool cmp(node a, node b)
{
    return a.r < b.r;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, l, a, x, y;
    scanf("%d%d%d", &n, &l, &a);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        e[i].l = x;
        e[i].r = x + y;
    }
    sort(e + 1, e + 1 + n, cmp);
    int ans = 0;
    ans += (e[1].l - 0) / a;
    for (int i = 2; i <= n; i++)
    {
        ans += (e[i].l - e[i - 1].r) / a;
    }
    ans += (l - e[n].r) / a;
    printf("%d\n", ans);

    return 0;
}
