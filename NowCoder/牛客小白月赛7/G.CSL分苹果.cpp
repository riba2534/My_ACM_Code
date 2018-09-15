#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
int a[50005];
int dp[50005];
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int v = sum / 2;
    for (int i = 0; i < n; i++)
        for (int j = v; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    int ans1 = sum - dp[v], ans2 = dp[v];
    if (ans1 > ans2)
        swap(ans1, ans2);
    printf("%d %d\n", ans1, ans2);
    return 0;
}
