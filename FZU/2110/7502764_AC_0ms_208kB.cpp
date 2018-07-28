#include <stdio.h>
#include <math.h>
#include <string.h>
struct zb
{
    double x;
    double y;
} q[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf",&q[i].x,&q[i].y);
        double a,b,c;
        int i,j,k,sum=0;
        for(i=0; i<n-2; i++)
            for(j=i+1; j<n-1; j++)
                for(k=j+1; k<n; k++)
                {
                    a=(q[i].x-q[j].x)*(q[i].x-q[j].x)+(q[i].y-q[j].y)*(q[i].y-q[j].y);
                    b=(q[i].x-q[k].x)*(q[i].x-q[k].x)+(q[i].y-q[k].y)*(q[i].y-q[k].y);
                    c=(q[j].x-q[k].x)*(q[j].x-q[k].x)+(q[j].y-q[k].y)*(q[j].y-q[k].y);
                    if(a+b>c&&a+c>b&&b+c>a)
                        sum++;
                }
        printf("%d\n",sum);
    }
    return 0;
}