#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
int map[110][110];
int dp[110][110];
int r, c;
int go[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y]; //dp[x][y]在坐标以(x,y)为顶点，所能达到的最长区域的长度
    for (int i = 0; i < 4; i++)
    {
        int xx = x + go[i][0];
        int yy = y + go[i][1];
        if (map[xx][yy] < map[x][y] && xx >= 1 && xx <= r && yy >= 1 && yy <= c) //下一步必须必这一步小，且不能越界
            dp[x][y] = max(dp[x][y], dfs(xx, yy));                               //更新每一步的dp值
    }
    // dp[x][y]++; //当前状态的步数加一
    return ++dp[x][y];
}
int main()
{
    //freopen("inn.txt", "r", stdin);
    while (~scanf("%d%d", &r, &c))
    {
        mem(dp, 0);
        int maxx = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d", &map[i][j]);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                maxx = max(maxx, dfs(i, j)); //更新最大值
        printf("%d\n", maxx);
    }
}