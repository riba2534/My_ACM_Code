#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pir;
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
const int N = 2e5 + 10;
char s[N];
//int vis[N];
void solve()
{
    //mem(vis, 0);
    int n;
    map<int, int> vis;
    int ans = 0, flag = 0;
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n - 3; i++)
    {
        if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C')
        {
            vis[i] = 1;
            ans++;
        }
    }
    for (int i = 1; i <= n - 2; i++)
    {
        if (vis[i])
            continue;
        if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'C' && vis[i + 1] == 0)
            flag = 1;
        else if (s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C' && vis[i - 1] == 0)
            flag = 1;
        else if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P')
            flag = 1;
    }
    printf("%d\n", ans + flag);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
