#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 10000+20
#define M 1000000+10
#define LL long long
using namespace std;
char a[1010];
int pow(int x, int y)
{
    int sum = 1;
    for (int i = 1; i <= y; i++)
        sum *= x;
    return sum;
}
int main()
{
    int x;
    while (~scanf("%d", &x))
    {
        scanf("%s", a);
        int len = strlen(a);
        int ans = 0, cnt, tot, flag, flog1, flog2;
        for (int i = 0; i<len; i++)
        {
            flog1 = 0, flog2 = 0;
            if (a[i] == '-')
            {
                flag = 1; i++;
            }
            else
            {
                flag = 0;
                if (a[i] == '+')
                    i++;
            }
            if (a[i] >= '0'&&a[i] <= '9'&&i<len)
            {
                flog1 = 1;
                cnt = 0;
                while (a[i] >= '0'&&a[i] <= '9'&&i<len)
                {
                    cnt = cnt * 10 + (a[i] - '0');
                    i++;
                }
            }
            if (a[i] == 'X'&&i<len)
            {
                flog2 = 1;
                if (a[i + 1] == '^')
                {
                    i += 2;
                    int t = 0;
                    while (a[i] >= '0'&&a[i] <= '9'&&i<len)
                    {
                        t = t * 10 + (a[i] - '0');
                        i++;
                    }
                    i--;
                    tot = pow(x, t);
                }
                else
                    tot = x;
            }
            if (flag)
            {
                if (flog1&&flog2)
                    ans -= cnt*tot;
                else if (flog1)
                    ans -= cnt;
                else if (flog2)
                    ans -= tot;
            }
            else
            {
                if (flog1&&flog2)
                    ans += cnt*tot;
                else if (flog1)
                    ans += cnt;
                else if (flog2)
                    ans += tot;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}