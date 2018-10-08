#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
int main()
{
    int n;
    scanf("%d", &n);
    int x = 1;
    while (n)
    {
        for (int i = 1; i <= n - (n / 2); i++)
        {
            printf("%d ", x);
        }
        if (n == 3)
        {
            printf("%d ", 3 * x);
            break;
        }
        n /= 2, x *= 2;
    }
    puts("");
    return 0;
}
