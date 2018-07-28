#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pir pair<int,int>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1000+20;
const double eps=1e-6;
double d[N],s[N];
int n;
double t;
double solve(double c)
{
    double ans=0;
    for(int i=1; i<=n; i++)
    {
        if(s[i]+c<0)
            return 1e10;
        ans+=d[i]/(s[i]+c);
    }
    return ans;
}
int main()
{
    scanf("%d%lf",&n,&t);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf%lf",&d[i],&s[i]);

    }
    double l=-1e10,r=1e10;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(solve(mid)<t)
            r=mid;
        else
            l=mid;
    }
    printf("%.9lf\n",l);
    return 0;
}
