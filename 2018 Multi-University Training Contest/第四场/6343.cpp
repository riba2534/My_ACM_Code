#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        printf("%d\n", (int)sqrt(abs(a[n] - a[1])));
    }
    return 0;
}
