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
const int N = 1e3 + 10;
int f[N], sg[N], vis[N];
void get_sg(int n)
{
    mem(sg, 0);
    for (int i = 1; i <= n; i++)
    {
        mem(vis, 0);
        for (int j = 1; f[j] <= i; j++)
            vis[sg[i - f[j]]] = 1;
        for (int j = 0;; j++)
            if (!vis[j])
            {
                sg[i] = j;
                break;
            }
    }
}
void init()
{
    int ans = 1;
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= 16; i++)
        f[i] = f[i - 1] + f[i - 2];

    get_sg(1000);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    init();
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) && (a || b || c))
    {
        if (sg[a] ^ sg[b] ^ sg[c])
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}