#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 300
#define ll long long
using namespace std;
int dp[N][N];//dp[i][j]表示i~j这个区间的最大括号匹配数
char s[N];
int is(char a,char b)
{
    if(a=='('&&b==')')
        return 1;
    if(a=='['&&b==']')
        return 1;
    return 0;
}
int main()
{
    while(scanf("%s",s+1)&&strcmp(s+1,"end"))
    {
        mem(dp,0);
        int len=strlen(s+1);
       // printf("len=%d\n",len);
        for(int i=len-1; i>=1; i--)
            for(int j=i+1; j<=len; j++)
            {
              // printf("i=%d,j=%d\n",i,j);
                if(is(s[i],s[j]))
                    dp[i][j]=dp[i+1][j-1]+2;
                for(int k=i; k<=j; k++)
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k][j]);
            }
        printf("%d\n",dp[1][len]);
    }
    return 0;
}
