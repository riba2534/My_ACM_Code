 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=100+5;
char s[N];
int dp[N][N];
int judge(char a,char b)
{
    if(a=='['&&b==']')return 1;
    if(a=='('&&b==')')return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0; i<len; i++)dp[i][i]=1;
        for(int k=1; k<len; k++)
        {
            for(int i=0; i+k<len; i++)
            {
                int j=i+k;
                dp[i][j]=dp[i+1][j]+1;
                for(int l=i+1; l<=j; l++)
                    if(judge(s[i],s[l]))
                        dp[i][j]=min(dp[i][j],dp[i+1][l-1]+dp[l][j]-1);
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}

        