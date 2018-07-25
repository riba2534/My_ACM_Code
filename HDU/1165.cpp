#include<stdio.h>
int dfs(int m,int n)
{
    if(n==0)return dfs(m-1,1);
    if(m==1)return n+2;
    if(m==2)return 2*n+3;
    if(m==3)return 2*dfs(3,n-1)+3;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==1)printf("%d\n",n+2);
        else if(m==2)printf("%d\n",2*n+3);
        else printf("%d\n",dfs(3,n));
    }
    return 0;
}
