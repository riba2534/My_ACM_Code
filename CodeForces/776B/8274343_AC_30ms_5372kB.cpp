#include<cstdio>
int p[900005],n,i,j;
int main()
{
    scanf("%d",&n);
    printf("%d\n",n<3?1:2);
    n++;
    for(i=2; i<=n; i++)
    {
        for(j=i; j<=n;)p[j+=i]=1;
        printf("%d ",1+p[i]);
    }
}