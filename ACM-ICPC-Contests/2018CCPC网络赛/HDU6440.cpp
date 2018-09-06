#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
        int flag = 0;
        for (int j = 0; j < p; j++)
        {
            if (!flag)
            {
                printf("%d", (i + j) % p);
                flag = 1;
            }
            else
                printf(" %d", (i + j) % p);
        }
        printf("\n");
    }
    for (int i = 0; i < p; i++)
    {
        int flag = 0;
        for (int j = 0; j < p; j++)
        {
            if (!flag)
            {
                printf("%d", (i * j) % p);
                flag = 1;
            }
            else
                printf(" %d", (i * j) % p);
        }
        printf("\n");
    }
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
