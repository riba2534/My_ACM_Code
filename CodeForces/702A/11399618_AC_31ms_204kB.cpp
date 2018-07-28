#include<stdio.h>
int a[100020];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int maxx=0,sum=1;
        for(int i=1; i<n; i++)
        {
            if(a[i]>a[i-1])
                sum++;
            else
            {
                if(maxx<sum)
                    maxx=sum;
                sum=1;
            }
        }
        if(maxx<sum)
            maxx=sum;
        printf("%d\n",maxx);
    }
    return 0;
}
