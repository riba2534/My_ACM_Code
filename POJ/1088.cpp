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
        return dp[x][y]; //dp[x][y]��������(x,y)Ϊ���㣬���ܴﵽ�������ĳ���
    for (int i = 0; i < 4; i++)
    {
        int xx = x + go[i][0];
        int yy = y + go[i][1];
        if (map[xx][yy] < map[x][y] && xx >= 1 && xx <= r && yy >= 1 && yy <= c) //��һ���������һ��С���Ҳ���Խ��
            dp[x][y] = max(dp[x][y], dfs(xx, yy));                               //����ÿһ����dpֵ
    }
    // dp[x][y]++; //��ǰ״̬�Ĳ�����һ
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
                maxx = max(maxx, dfs(i, j)); //�������ֵ
        printf("%d\n", maxx);
    }
}