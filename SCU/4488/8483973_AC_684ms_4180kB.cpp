//#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define N 1000+10
//#define LL long long
//using namespace std;
//int dp[N][N];
//int n,m;
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d%d",&n,&m);
//        for(int i=0; i<n; i++)
//            for(int j=0; j<m; j++)
//                scanf("%d",&dp[i][j]);
//
//    }
//
//    return 0;
//}
#include<stdio.h>
#include<string.h>

#define maxn   1000+10
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int dp[maxn][maxn];
int n,m,ans;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&dp[i][j]);
        ans=0;
        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++)
            {
                if(dp[i][j]!=0)
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                  //  printf("dp[%d][%d]=min(dp[%d][%d],min(dp[%d][%d],dp[%d][%d]))+1=%d\n",i,j,i-1,j,i,j-1,i-1,j-1,dp[i][j]);
                }
                ans=max(ans,dp[i][j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
