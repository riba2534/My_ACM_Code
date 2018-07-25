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
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=50000+20;
const double pi=acos(-1.0);
int main()
{
    int n,d;
    while(~scanf("%d%d",&n,&d))
    {
        double ans=0,x;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&x);
            ans+=(1/2.0)*(d*d*1.0)*sin((x/180.0)*pi);
        }
        printf("%.3lf\n",ans);
    }


    return 0;
}