#include<stdio.h>
int main()
{
    int t;
    double n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&n);
        double ans=0;
        int res=0;
        if(n<=500)
        {
            printf("%.3lf\n",n);
            continue;
        }
        while(n>0)
        {
            res++;
            n-=500.0/(2*res-1);
        }
        ans=500.0*res+(2*res-1)*n;
        printf("%.3lf\n",ans);
    }
    return 0;
}