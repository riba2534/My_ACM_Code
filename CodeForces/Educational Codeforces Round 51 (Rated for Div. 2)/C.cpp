#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int a[N];
char ans[N];
int main()
{
    int n;
    map<int, int> mp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    int sum1 = 0, sum2 = 0;
    for (auto num : mp)
    {
        if (num.second == 1)
            sum1++;
        if (num.second > 2)
            sum2++;
    }
    int flag = 0, k = 0;
    if (sum1 % 2 == 0)
        flag = 1;
    else if (sum2)
    {
        flag = 1;
        k = 1;
    }
    puts(flag ? "YES" : "NO");
    int pos = 0;
    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mp[a[i]] == 1)
            {
                ans[i] = pos & 1 ? 'A' : 'B';
                pos++;
            }
            else if (mp[a[i]] > 2 && k)
            {
                ans[i] = 'A';
                k = 0;
            }
            else
                ans[i] = 'B';
        }
        for (int i = 1; i <= n; i++)
            putchar(ans[i]);
        puts("");
    }

    return 0;
}
