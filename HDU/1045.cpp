#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N = 15;
char map[N][N];
int n, maxx;
int judge(int x, int y)
{
    for (int i = y; i >= 0; i--)
    {
        if (map[x][i] == 'X')
            break;
        if (map[x][i] == 'P')
            return 0;
    }
    for (int i = x; i >= 0; i--)
    {
        if (map[i][y] == 'X')
            break;
        if (map[i][y] == 'P')
            return 0;
    }
    return 1;
}
void dfs(int num, int step)
{
    if (num == n * n)
    {
        maxx = max(maxx, step);
        return;
    }
    int x = num / n, y = num % n;
    if (map[x][y] == '.' && judge(x, y))
    {
        map[x][y] = 'P';
        dfs(num + 1, step + 1);
        map[x][y] = '.';
    }
    dfs(num + 1, step);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n) && n)
    {
        maxx = 0;
        for (int i = 0; i < n; i++)
            scanf("%s", map[i]);
        dfs(0, 0);
        printf("%d\n", maxx);
    }
    return 0;
}