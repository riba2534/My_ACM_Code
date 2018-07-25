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
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        int ans = 0;
        if (n & 1)
            ans++;
        if (m & 1)
            ans++;
        if (ans == 2)
            puts("What a pity!");
        else
            puts("Wonderful!");
    }
    return 0;
}