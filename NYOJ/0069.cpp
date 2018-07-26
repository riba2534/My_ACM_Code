 
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,t;
    double d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        d=0;
        for(i=1; i<=n; i++)
            d+=log10(i);
        printf("%d\n",(int) d+1);
    }
    return 0;
}
        