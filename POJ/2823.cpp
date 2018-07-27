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
const int N = 1e6 + 10;
deque<pir> q1; //维护最大值
deque<pir> q2; //维护最小值
int x, MIN[N], MAX[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        while (!q1.empty() && q1.back().first >= x) //队列递增
            q1.pop_back();
        q1.push_back(make_pair(x, i));
        if (i >= k)
        {
            while (!q1.empty() && q1.front().second <= i - k) //>的时候出去
                q1.pop_front();
            MIN[i] = q1.front().first;
        }
        while (!q2.empty() && q2.back().first <= x) //队列递减
            q2.pop_back();
        q2.push_back(make_pair(x, i));
        if (i >= k)
        {
            while (!q2.empty() && q2.front().second <= i - k)
                q2.pop_front();
            MAX[i] = q2.front().first;
        }
    }
    for (int i = k; i <= n; i++)
        printf("%d ", MIN[i]);
    puts("");
    for (int i = k; i <= n; i++)
        printf("%d ", MAX[i]);
    puts("");

    return 0;
}
