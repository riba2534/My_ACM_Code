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
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 300
#define ll long long
using namespace std;
int main()
{
    int t,x,n;
    scanf("%d",&t);
    while(t--)
    {
        int sum1=0,sum2=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&x);
            if(x&1)sum1++;
            else sum2++;
        }
        if(sum1>sum2) puts("2 1");
        else puts("2 0");
    }
    return 0;
}
