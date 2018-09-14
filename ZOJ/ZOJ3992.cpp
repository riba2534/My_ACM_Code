#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pir;
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
const int N = 5e5 + 10;
char s[N];
int lnum[N], rnum[N];
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 2; i <= n - 1; i++)
    {
        if (s[i] == 'L')
        {
            lnum[i] = lnum[i - 1] + 1;
            rnum[i] = rnum[i - 1];
        }
        else
        {
            lnum[i] = lnum[i - 1];
            rnum[i] = rnum[i - 1] + 1;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("l[%d]=%d,r[%d]=%d\n", i, lnum[i], i, rnum[i]);
    // }
    // puts("------------------------------");
    int ans = inf;
    if (s[k] == 'L')
    {
        int tmp1 = rnum[k - 1];
        int tmp2 = 1 + lnum[n - 1] - lnum[k];
        ans = min(ans, min(tmp1, tmp2));
    }
    else
    {
        int tmp1 = 1 + rnum[k - 1];       //向左走
        int tmp2 = lnum[n - 1] - lnum[k]; //向右走
        ans = min(ans, min(tmp1, tmp2));
    }
    printf("%d\n", ans);
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
