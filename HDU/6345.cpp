#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 1e5 + 20;
const int inf = 0x3f3f3f3f;
char s[N];
int sum[N][30];
int minn[N][20];

void RMQ(int num)
{
    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= num; ++i)
            if (i + (1 << j) - 1 <= num)
                minn[i][j] = min(minn[i][j - 1], minn[i + (1 << (j - 1))][j - 1]);
}
int main()
{
    int t, n, m, a, b, q = 1;
    scanf("%d", &t);
    while (t--)
    {
        mem(sum, 0);
        printf("Case #%d:\n", q++);
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++)
        {
            minn[i][0] = s[i] - 'A';
            for (int j = 0; j < 26; j++)
                if (j == s[i] - 'A')
                    sum[i][j] = sum[i - 1][j] + 1;
                else
                    sum[i][j] = sum[i - 1][j];
        }
        RMQ(n);
        while (m--)
        {
            scanf("%d%d", &a, &b);
            int k = (int)(log(b - a + 1.0) / log(2.0));
            int minnum = min(minn[a][k], minn[b - (1 << k) + 1][k]);
            // printf("-->%c\n", minnum + 'A');
            // printf("(%d--%d)\n", sum[b][minnum], sum[a - 1][minnum]);
            int ans = sum[b][minnum] - sum[a - 1][minnum];
            printf("%d\n", ans);
        }
    }
    return 0;
}
