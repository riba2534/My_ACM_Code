 
#include<stdio.h>
#include<algorithm>
using namespace std;
#define eps 1e-4
const int N=10005;
double w[N],v[N],x[N],max_ave;
int n,k;
bool judge(double a)
{
    for(int i=0; i<n; i++)
        x[i]=v[i]-a*w[i];
    sort(x,x+n);
    double sum=0;
    for(int i=0; i<k; i++)
        sum+=x[n-1-i];
    return sum>=0?true:false;
}
double get_ans()
{
    double l=0,r=max_ave;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(judge(mid))
            l=mid;
        else
            r=mid;
    }
    return l;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        max_ave=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&w[i],&v[i]);
            double tmp=v[i]/w[i];
            if(max_ave<tmp) max_ave=tmp;
        }
        printf("%.2lf\n",get_ans());
    }
    return 0;
}
        