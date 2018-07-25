#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
int dp[10][3];
/*
dp[i][0]:长度为i,吉利数字的个数
dp[i][1]:长度为i,最高位为2的吉利数字个数
dp[i][2]:长度为i，不吉利数字的个数
*/
void init()
{
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    for(int i=1;i<=6;i++)
    {
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//在最高位加上除4之外的9个数字,和2之前的6
        dp[i][1]=dp[i-1][0];//在i-1的最高位加上2
        dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];
        //在已有不吉利数字前加任意数字，或者无不吉利数字的最高位加4，或者在2前面加6
    }
}
int bit[10];
int solve(int n)
{
    int len=0,tmp=n;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    bit[len+1]=0;
    int ans=0,flag=0;//ans记录不吉利数字个数
    //flag不吉利数字是否出现过
    for(int i=len;i>=1;i--)
    {
        ans+=dp[i-1][2]*bit[i];//每一个不吉利数字可以加上0~bit[i]-1个数字
        if(flag)//高位出现4或62
            ans+=dp[i-1][0]*bit[i];//前一位的吉利数字的个数加上0~bit[i]-1个数字
        else
        {
            if(bit[i]>4) ans+=dp[i-1][0];//加上4
            if(bit[i]>6) ans+=dp[i-1][1];//加上6
            if(bit[i+1]==6&&bit[i]>2) ans+=dp[i][1];//当前的长度的首位为2个吉利数字个数
            if(bit[i]==4||(bit[i+1]==6&&bit[i]==2)) flag=1;
        }
    }
    if(flag) ans++;
    return tmp-ans;


}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    init();
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        printf("%d\n",solve(m)-solve(n-1));
    }

    return 0;
}