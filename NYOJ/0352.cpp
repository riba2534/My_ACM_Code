 
#include<stdio.h>
int main()
{
    int f1,f2,f3,f4,i,n;

    while(scanf("%d",&n)&&n)
    {
        f1=1;
        f2=f3=f4=0;
        for(i=0; i<=n; i++)
        {

            f4=f4+f3;
            f3=f2;
            f2=f1;
            f1=f4;
        }
        printf("%d\n",f1+f2+f3+f4);
    }
    return 0;
}        