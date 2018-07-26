 
#include <stdio.h>
#include<stdio.h>
int pow_mod(int a,int b,int c)
{
    int s=1;
    a=a%c;
    while(b!=0)
    {
        if(b&1)
            s=s*a%c;
        a=a*a%c;
        b>>=1;
    }
    return s;
}

int main()
{
    int a,b,i,s;
    while(~scanf("%d%d",&a,&b))
    {
        printf("%d\n",pow_mod(a,b,10));
    }

    return 0;
}        