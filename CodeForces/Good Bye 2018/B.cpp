#include <bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("in.txt", "r", stdin);
    int n, a = 0, b = 0, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d%d", &x, &y);
        a += x, b += y;
    }
    //printf("a=%d,b=%d,n=%d\n", a, b, n);
    printf("%d %d\n", a / n, b / n);

    return 0;
}
