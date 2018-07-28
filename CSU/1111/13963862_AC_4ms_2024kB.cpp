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
#define inf 0x3f3f3f3f
typedef long long ll;
const int N = 1e6 + 10;
int main()
{
   // freopen("in.txt", "r", stdin);
    int t, x, y, z;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &x, &y, &z);
        float m = (x + y) / 3.0;
        float ans = (x - m) * z / m;
        printf("%d\n", (int)(ans + 0.5));
    }

    return 0;
}/////