#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 1e5 + 10;
int t1[N], t2[N], c[N], r[N], sa[N], rak[N], height[N];
bool cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int str[], int sa[], int rak[], int height[], int n, int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;
    for (i = 0; i < m; i++)
        c[i] = 0;
    for (i = 0; i < n; i++)
        c[x[i] = str[i]]++;
    for (i = 1; i < m; i++)
        c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--c[x[i]]] = i;
    for (j = 1; j <= n; j <<= 1)
    {
        p = 0;
        for (i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j)
                y[p++] = sa[i] - j;
        for (i = 0; i < m; i++)
            c[i] = 0;
        for (i = 0; i < n; i++)
            c[x[y[i]]]++;
        for (i = 1; i < m; i++)
            c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
    int k = 0;
    n--;
    for (i = 0; i <= n; i++)
        rak[sa[i]] = i;
    for (i = 0; i < n; i++)
    {
        if (k)
            k--;
        j = sa[rak[i] - 1];
        while (str[i + k] == str[j + k])
            k++;
        height[rak[i]] = k;
    }
}

int n, a[N], k;
bool check(int mid)
{
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (height[i] >= mid)
        {
            cnt++;
            continue;
        }
        if (cnt >= k)
            return true;
        cnt = 1;
    }
    if (cnt >= k)
        return true;
    return false;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &k))
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            temp = max(temp, a[i]);
        }
        a[n] = 0;
        da(a, sa, rak, height, n, temp + 1);
        int l = 0, r = n, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
8 2
2 6 8 3 9 1 7 5 
8 2
2 7 3 3 8 8 8 8 
*/