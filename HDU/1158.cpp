#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int dp[20][1000];//表示第几个月保留几个人所需的最小花费
int num[20];//当前月份需要几个人
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int a,b,c,maxx=-1;//a,b,c分别表示聘请的的花费、每月的工资花费、开除一个人的花费
        scanf("%d%d%d",&a,&b,&c);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            maxx=max(maxx,num[i]);//找出人数的最大需求量
        }
        mem(dp,1);//注意这时候把dp初始化任意一个正值就行，这个正值虽然随机但是比1大
        for(int i=num[1]; i<=maxx; i++)
            dp[1][i]=a*i+b*i;//初始化第一个月保留的人数的月花费
        for(int i=2; i<=n; i++)
            for(int j=num[i]; j<=maxx; j++)
                for(int k=0; k<=maxx; k++)
                    if(k<=j) //表示当前状态是由聘请了(j-k)个人得来的
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(j-k)*a+j*b);
                    else//表示当前状态是由解雇了(k-j)个人得来的
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(k-j)*c+j*b);
        int ans=9999999;
        for(int i=0; i<=maxx; i++)
            ans=min(dp[n][i],ans);
        printf("%d\n",ans);
    }
    return 0;
}
