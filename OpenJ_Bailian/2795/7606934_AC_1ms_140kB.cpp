#include <stdio.h>
#include <algorithm>
using namespace std;
struct baobei
{
    int weight;
    int value;
    double xjb;
} a[200];
bool cmp(baobei x,baobei y)
{
    return x.xjb>y.xjb;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int w,n;
        scanf("%d %d",&w,&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&a[i].weight,&a[i].value);
            a[i].xjb=(1.0*a[i].value)/(1.0*a[i].weight);
        }
        sort(a,a+n,cmp);
//        for(int i=0; i<n; i++)
//        {
//            printf("weight=%d,value=%d,xjb=%lf\n",a[i].weight,a[i].value,a[i].xjb);
//        }
        double sum=0.0;
        for(int i=0; i<n; i++)
        {
            if(w>=a[i].weight)
            {
                sum+=a[i].value*1.0;
                w-=a[i].weight;
            }
            else
            {
                sum+=a[i].xjb*w;
                break;
            }
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
