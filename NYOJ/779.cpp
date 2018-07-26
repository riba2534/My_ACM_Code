 
#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int i=0;
        if(n<=k)
            printf("2\n");
        else
        {
            n*=2;
            while(n>0)
            {
                n-=k;
                ++i;
            }
            printf("%d\n",i);
        }
    }
    return 0;
}        