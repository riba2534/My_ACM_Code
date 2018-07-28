#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
char a[2000],b[2000];
int dp[2000][2000];//dp[i][j]表示匹配到a字符串的第i个字符和b字符串的第j个字符时的最大匹配数
int main()
{
    while(~scanf("%s%s",a,b))
    {
        int len1=strlen(a);
        int len2=strlen(b);
        mem(dp,0);
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
