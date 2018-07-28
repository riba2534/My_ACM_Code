#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
const int maxn=1005;
int map[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        int m,n;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&map[i][j]);
        }
        for(int j=1; j<=n; j++)
        {
            int flag=0;
            for(int i=1; i<=m; i++)
            {
                if(map[i][j]==1)
                    flag++;
                else
                    flag=0;
                dp[i][j]=flag;
            }
        }
        //------------------------------------------------------
//        for(int i=1;i<=n;i++)
//        {
//            printf("\n");
//            for(int j=1;j<=m;j++)
//            {
//                printf("%d ",dp[i][j]);
//            }
//        }








        //-------------------------------------------------------
        int result=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(dp[i][j]>result)
                {
                    int min_num=dp[i][j];
                    int flag_j=j;
                    for(; flag_j<=m&&min_num>result; flag_j++)
                    {
                        min_num=min(min_num,dp[i][flag_j]);
                        result=max(result,min(min_num,flag_j-j+1));
                    }
                    j=flag_j-1;
                }
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
