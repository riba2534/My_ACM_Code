#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const double pi=acos(-1.0);
int main()
{
    int d,h,v,e;
    scanf("%d%d%d%d",&d,&h,&v,&e);
    double s=(d/2.0)*(d/2.0)*pi;//算出面积
    double v1=s*h*1.0;//算出初始体积
    if(v-s*e<=1e-5)//确定误差范围
        puts("NO");
    else
        printf("YES\n%.10lf\n",v1/(v-s*e));
    return 0;
}
