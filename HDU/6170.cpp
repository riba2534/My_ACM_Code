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
#define mod 1000007
#define ll long long
using namespace std;
const int N=2500+10;
char a[N],b[N];
bool dp[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        mem(dp,0);
        a[0]=b[0]='0';
        gets(a+1);
        gets(b+1);
        int lena=strlen(a)-1;
        int lenb=strlen(b)-1;
        dp[0][0]=true;
        for(int i=1;i<=lenb;i++)
        {
            if(i==2&&b[i]=='*')
                dp[2][0]=true;
            for(int j=1;j<=lena;j++)
            {
                if(b[i]=='.'||b[i]==a[j])
                    dp[i][j]=dp[i-1][j-1];
                else if(b[i]=='*')
                {
                    dp[i][j]=dp[i-2][j]|dp[i-1][j];
                    if((dp[i-1][j-1]||dp[i][j-1])&&a[j-1]==a[j])//Æ¥ÅäÁ¬ÐøµÄ*
                        dp[i][j]=true;
                }
            }
        }
        if(dp[lenb][lena])puts("yes");
        else puts("no");



    }
  return 0;
}
