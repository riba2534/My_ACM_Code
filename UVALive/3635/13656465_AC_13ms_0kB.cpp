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
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 999999999
typedef long long ll;
const int N=1e5+20;
const double pi=acos(-1.0);
const double eps=1e-5;
int n,f;
double s[N];
int judge(double x)
{
    int sum=0;
    for(int i=1; i<=n; i++)
        sum+=floor(s[i]/x);
    return sum>=f+1;
}
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&f);
        double maxx=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            s[i]=pi*x*x;
            maxx=max(maxx,s[i]);
        }
        double l=0,r=maxx;
        while(r-l>eps)
        {
            double mid=(l+r)/2;
            if(judge(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%.4lf\n",l);
    }
    return 0;
}
