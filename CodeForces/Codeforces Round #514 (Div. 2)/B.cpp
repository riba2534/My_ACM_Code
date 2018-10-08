#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 1e3 + 10;
char s[N][N], vis[N][N];
int n, m;
int pd(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return 1;
    return 0;
}
int pc(int x, int y)
{
    if (s[x][y] == '#')
        return 1;
    return 0;
}
void gao(int x, int y)
{
    vis[x][y] = '#';
}
void run(int x, int y)
{
    if (pd(x, y) && pd(x, y + 1) && pd(x, y + 2) && pd(x + 1, y) && pd(x + 1, y + 2) && pd(x + 2, y) && pd(x + 2, y + 1) && pd(x + 2, y + 2))
        if (pc(x, y) && pc(x, y + 1) && pc(x, y + 2) && pc(x + 1, y) && pc(x + 1, y + 2) && pc(x + 2, y) && pc(x + 2, y + 1) && pc(x + 2, y + 2))
            gao(x, y), gao(x, y + 1), gao(x, y + 2), gao(x + 1, y), gao(x + 1, y + 2), gao(x + 2, y), gao(x + 2, y + 1), gao(x + 2, y + 2);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    mem(vis, '.');
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            run(i, j);
    int flag = 1;
    for (int i = 1; i <= n && flag; i++)
    {
        for (int j = 1; j <= m && flag; j++)
        {
            if (s[i][j] != vis[i][j])
            {
                flag = 0;
                break;
            }
        }
    }
    puts(flag ? "YES" : "NO");

    return 0;
}
