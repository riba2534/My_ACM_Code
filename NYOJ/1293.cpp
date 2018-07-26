 
#include <stdio.h>
int main()
{
    int a1,a2,a3,b1,b2,b3;
    while(~scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3))
    {
        int n=0;
        if(a3<90&&b3<90)printf("-1\n");
        if(a3<90&&b3>=90)printf("2\n");
        if(a3>=90&&b3<90)printf("1\n");
        if(a3>=90&&b3>=90)
        {
            if(a1+a2+a3>b1+b2+b3)printf("1\n");
            else if(a1+a2+a3==b1+b2+b3)printf("1\n");
            else if(a1+a2+a3<b1+b2+b3)printf("2\n");

        }
    }
    return 0;
}
        