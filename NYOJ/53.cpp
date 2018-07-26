 
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a[7][2];
        for(int i=0; i<7; i++)
        {
            for(int j=0; j<2; j++)
                scanf("%d",&a[i][j]);
        }
        int maxx=00,max=0;
        for(int i=0; i<7; i++)
        {
            if(a[i][0]+a[i][1]>a[i+1][0]+a[i+1][1]&&a[i][0]+a[i][1]>8&&a[i][0]+a[i][1]>max)
                max=a[i][0]+a[i][1];
//            if(a[i][0]+a[i][1]>8&&a[i][0]+a[i][1]>maxx)
//                maxx=i;
           //printf("当前a[%d][0]=%d,a[%d][1]=%d,max=%d\n",i,a[i][0],i,a[i][1],max);

        }
        for(int i=0; i<7; i++)
        {
            if(a[i][0]+a[i][1]==max)
            {
                maxx=i;
                break;
            }

        }
        if(maxx==0&&max==0)
        {
            printf("%d\n",maxx);
        }
        else
        {
            printf("%d\n",maxx+1);
        }


    }
    return 0;
}        