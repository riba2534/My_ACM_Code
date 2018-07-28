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
const int N = 500 + 10;
int a[N], sum[N];
int num[N][N], dp[N][N];
int get_unhappy(int l, int r) //获得区间[l,r]不愉快值
{
    int a = sum[r] - sum[l - 1]; //1的个数
    int b = (r - l + 1) - a;     //0的个数
    return a * b;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    mem(dp, inf);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            num[i][j] = get_unhappy(i, j);
           // printf("(%d,%d)-->%d\n", i, j, num[i][j]);
        }
    }
    for (int i = 1; i <= k; i++) //马厩
    {
        for (int j = 1; j <= n; j++) //马
        {
            for (int t = 1; t <= j; t++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][t - 1] + num[t][j]);
            }
            //printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
        }
    }
    printf("%d\n", dp[k][n]);

    return 0;
}