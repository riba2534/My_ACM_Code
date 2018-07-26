 
#include <stdio.h>
#include<math.h>
int sushu(int n)
{
    int flag,i;
    flag=1;
    if(n==0||n==1)
        flag=0;
    for( i=2; i<=sqrt(n); i++)
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
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(sushu(n))
            printf("%d\n",n);
        else
        {
            for(i=n; sushu(i)!=1; i++);
            for(j=n; sushu(j)!=1; j--);
            if(i-n>=n-j)
            {
                if(i-n==n-j)
                    printf("%d\n",i);
                else
                    printf("%d\n",j);
            }
            else
                printf("%d\n",i);
        }
    }
    return 0;
}        