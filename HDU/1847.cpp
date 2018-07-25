#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define rson m + 1, r, rt << 1 | 1
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int, int> pir;
/*
f[]:可以取走的石子个数,必须要升序
vis[]:用来求解mex{}
sg[]:存储sg的值
n:f[]下标
*/
const int N = 1e3 + 10;
int f[N], sg[N], n;
int sg_dfs(int x)
{
    if (~sg[x])
        return sg[x];
    int vis[N]; //必须定义在里面
    mem(vis, 0);
    for (int i = 1; i <= n; i++)
        if (x >= f[i])
        {
            sg_dfs(x - f[i]);
            vis[sg[x - f[i]]] = 1;
        }
    for (int i = 0;; i++)
        if (!vis[i])
            return sg[x] = i;
}
void init()
{
    mem(sg, -1);
    sg[0] = 0;
    n = 0;
    for (int i = 1; i <= 1000; i *= 2)
        f[++n] = i;
    sg_dfs(1000);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    init();
    int x;
    while (~scanf("%d", &x))
    {
        if (sg[x])
            printf("Kiki\n");
        else
            printf("Cici\n");
    }
    return 0;
}
