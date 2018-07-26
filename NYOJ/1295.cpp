 
#include<stdio.h>
int main()
{
    long long a;
    while(scanf("%lld",&a))
    {
        if(a==0)
            break;
        if(a>0)
            printf("%lld\n",a);
        else
            printf("%lld\n",-a);
    }
    return 0;
}
        