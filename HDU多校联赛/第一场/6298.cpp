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
int main()
{
    ll t, n;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        if (n % 3 == 0)
            printf("%lld\n", n * n * n / 27);
        else if (n % 4 == 0)
            printf("%lld\n", n * n * n / 32);
        else
            puts("-1");
    }
    return 0;
}