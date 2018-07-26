 
#include<malloc.h>
#include<stdio.h>
//#include<string.h>

int main()
{
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    int a[n];
    for(i=0; i<n; i++)
    {
        a[i]=0;
    }

    for(i=0; i<n; i++)
        for(j=1; j<=k; j++)
        {
            if((i+1)%j==0)
            {
                if(a[i]==0)
                    a[i]=1;
                else
                    a[i]=0;
            }
        }
    for(i=0; i<n; i++)
        if(a[i]==1)
            printf("%d ",i+1);
    printf("\n");
    return 0;
}        