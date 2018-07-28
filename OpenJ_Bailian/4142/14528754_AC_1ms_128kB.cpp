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
const int N = 2e5 + 10;
const double eps=1e-7;
double f(double x)
{
    double ans=pow(x,5)-15.0*pow(x,4)+85.0*pow(x,3)-225.0*pow(x,2)+274.0*x-121.0;
    return ans;
}
int main()
{
    double l=1.5,r=2.4;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(f(mid)>0)
            l=mid;
        else
            r=mid;
    }
    printf("%lf\n",l);
    return 0;
}
