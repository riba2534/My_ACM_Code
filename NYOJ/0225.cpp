 
#include <stdio.h>
#include <math.h>
int sushu(int n)
{
    int flag=1;
    if(n==0||n==1)
        flag=0;
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int sum=1;
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
        {
            if(sushu(i)==1)
            {
               sum = sum*i%1000000;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}        