#include <stdio.h>
#include <string.h>
#define mem(a,b) memset(a,b,sizeof(a))
int prime[100]= {1,1};
int a[50],md[50],n;
void sushu()
{
    int i,j;
    for(i=2; i<=10; i++)
        if(prime[i]==0)
            for(j=2*i; j<=50; j+=i)
                prime[j]=1;
}
void dfs(int step)
{
    int i,j;
    if(step==n+1&&prime[a[n]+a[1]]==0)
    {
        for(i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
        return;
    }
    for(i=2; i<=n; i++)
    {
        if(md[i]==0&&prime[i+a[step-1]]==0)
        {
            a[step]=i;
            md[i]=1;
            dfs(step+1);
            md[i]=0;
        }
    }
    return;

}
int main()
{
    int num=1;
    a[1]=1;
    sushu();
    while(~scanf("%d",&n))
    {
        mem(md,0);
        printf("Case %d:\n",num++);
        dfs(2);
        printf("\n");
    }
    return 0;
}
