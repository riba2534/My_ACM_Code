#include<stdio.h>
#include<string.h>
int a[40][40];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
        {
            a[i][0]=1;
            a[i][i]=1;
        }
        for(i=2; i<n; i++)
            for(j=1; j<=i-1; j++)
                a[i][j]=a[i-1][j]+a[i-1][j-1];
        for(i=0; i<n; i++)
        {
            for(j=0; j<i; j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d",a[i][i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
