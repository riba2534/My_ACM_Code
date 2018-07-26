 
#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,c,d;
        scanf("%lf%lf%lf",&a,&b,&c);
        d=(a+b-c)*10000;
        if((int)d==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
        