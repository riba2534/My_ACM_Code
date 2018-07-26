 
#include<stdio.h>
int count;
int fun(int a,int b)
{
    if(a%b==0)
    {
        return 1+fun(a/b,b);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n,a,b,sum;
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        count=0;
        sum=0;
        scanf("%d%d",&a,&b);
        for(j=b; j<=a; j+=b)
        {
            sum+=fun(j,b);
        }
        printf("%d\n",sum);
    }
    return 0;
}
        