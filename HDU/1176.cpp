#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
int dp[100005][15];  
  
int main()  
{  
    int n,x,t,i,j,end;  
    while(~scanf("%d",&n),n)  
    {  
        end = 0;  
        memset(dp,0,sizeof(dp));  
        while(n--)  
        {  
            scanf("%d%d",&x,&t);  
            dp[t][x+1]++;//向右位移，省去边界  
            end = max(end,t);//找出最长时间  
        }  
        for(i = end;i>=0;i--)  
        {  
            for(j = 1;j<=11;j++)  
            {  
                dp[i][j] += max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));  
            }  
        }  
        printf("%d\n",dp[0][6]);  
    }  
  
    return 0;  
}  