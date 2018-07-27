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
typedef long long ll;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
struct node
{
    int x, y, id;
} e[N];
bool cmp(node x, node y)
{
    // if (x.x == y.x)
    //     return x.y > y.y;
    return x.x < y.x;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 3 * n; i++)
        {
            scanf("%d%d", &e[i].x, &e[i].y);
            e[i].id = i;
        }
        sort(e + 1, e + 3 * n + 1, cmp);
        for (int i = 1; i <= 3 * n; i += 3)
        {
            printf("%d %d %d\n", e[i].id, e[i + 1].id, e[i + 2].id);
        }
        puts("");
    }

    return 0;
}