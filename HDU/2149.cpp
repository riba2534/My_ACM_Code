#include <stdio.h>
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n%(m+1)==0)
            printf("none\n");
        else
        {
            if(n<=m)
            {
                printf("%d",n);
                for(int i=n+1;i<=m;i++)
                    printf(" %d",i);
                printf("\n");
            }
            else
                printf("%d\n",n%(m+1));
        }
    }
    return 0;
}

