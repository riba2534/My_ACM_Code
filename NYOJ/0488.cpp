 
#include <stdio.h>
#include <string.h>
#define mem(a,b) memset(a,b,sizeof(a))
int prime[100]= {1,1};
int a[50],md[50],n;//a来存放素数环里的数，md是做标记
int flag;
void sushu()
{
    int i,j;
    for(i=2; i<=10; i++)
        if(prime[i]==0)
            for(j=2*i; j<=50; j+=i)
                prime[j]=1;//把不是素数的标记为1
}
void dfs(int step)
{
    int i,j;
    if(step==n+1&&prime[a[n]+a[1]]==0)//结束条件，这个代码是从a[1]开始的
    {
        flag=0;
        for(i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
        return;
    }
    for(i=2; i<=n; i++)
    {
        if(md[i]==0&&prime[i+a[step-1]]==0)
        {
            a[step]=i;//给素数环填数
            md[i]=1;//标记一下走过的
            dfs(step+1);//搜索下一步
            md[i]=0;//标记回来
        }
    }
    return;
}
int main()
{
    int num=1;
    a[1]=1;//从1开始的
    sushu();
    while(~scanf("%d",&n)&&n)
    {

        flag=1;
        mem(md,0);
        printf("Case %d:\n",num++);
        if(n%2==0||n==1)
        dfs(2);
        if(flag)printf("No Answer\n");
    }
    return 0;
}
        