 
#include<stdio.h>
int main()
{
    int i,n,a[15];
    scanf("%d",&n);
    while(n--)
    {
        for(i=0; i<12; i++)
            scanf("%d",&a[i]);
        int t=0,sum=0;
        for(i=0; i<12; i++)
        {
            t+=300-a[i];
            if(t<0)
            {
                printf("-%d\n",i+1);
                break;
            }
            if(t/100>0)
            {
                sum+=(t/100)*100;
                t=t%100;
            }
        }
        if(i==12)
            printf("%.lf\n",sum*1.2+t);
    }
}        