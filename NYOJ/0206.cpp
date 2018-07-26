 
#include<stdio.h>
int main()
{
    int i,c[1002]= {0,1};
    long long a,b,d;
    for(i=2; i<1001; i++)
        c[i]=c[i-1]+i;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        a=c[a];
        b=c[b];
        d=a*b;
        printf("%lld\n",d);
    }
    return 0;
}        