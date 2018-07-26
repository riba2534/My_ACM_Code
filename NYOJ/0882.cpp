 
#include<stdio.h>
#include<string.h>
int a[100];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i=0,j;
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&k);
        while(n)
        {
            a[i++]=n%k;
            n/=k;
        }
        for(j=i-1; j>0; j--)
            printf("%d",a[j]);
        printf("%d\n",a[j]);
    }
    return 0;
}        