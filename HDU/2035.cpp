#include <stdio.h>
int pow_mod(int a,int b,int c)
{
    a=a%c;
    int ans=1;
    while(b)
    {
        if(b%2==1)
            ans=ans*a%c;
        a=a*a%c;
        b=b/2;
    }
    return ans;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b))
    {
        if(a==0&&b==0)
            break;
        printf("%d\n",pow_mod(a,b,1000));
    }
    return 0;
}
