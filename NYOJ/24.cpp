 
#include <stdio.h>
#include <math.h>
int sushu(int n)
{
    int flag=1;
    if(n==0||n==1)
    {
        flag=0;
    }
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        if(sushu(n)==1)
            printf("%d 0\n",n);
        else
        {
            int a=n,b=n;
            while(sushu(b)!=1)
            {
                b--;
//                if(sushu(b)==1)
//                {
//                    printf("%d ",b);
//                }
            }
            while(sushu(a)!=1)
            {
                a++;
//                if(sushu(a)==1)
//                {
//                    printf("%d ",a);
//                }
            }
            if(a-n>n-b)
            {
                printf("%d %d\n",b,n-b);
            }
            else
            {
                if(a-n==n-b)
                {
                    printf("%d %d\n",b,n-b);
                }
                else
                    printf("%d %d\n",a,a-n);
            }



        }
    }
    return 0;
}
        