#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 100100
#define M 1000000 + 10
#define ll long long
using namespace std;
int main()
{
    ll t, n, x;
    scanf("%lld", &t);
    while (t--)
    {
        priority_queue<ll, vector<ll>, greater<ll>> q; //优先队列，小的先出队
        scanf("%lld", &n);
        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            q.push(x);
        }
        ll sum = 0;
        while (q.size() >= 2)
        {
            ll num = 0;
            sum += q.top();
            num += q.top();
            q.pop();
            sum += q.top();
            num += q.top();
            q.pop();
            q.push(num);
        }
        printf("%lld\n", sum);
        if (t)
            puts("");
    }
    return 0;
}