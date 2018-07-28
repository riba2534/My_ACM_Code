#include <bits/stdc++.h>
using namespace std;
const int N=1000+20;
int dp[N][N];
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    s1="$"+s1;
    s2="$"+s2;
    int len1=s1.size()-1;
    int len2=s2.size()-1;
    for(int i=0; i<=len1; i++) dp[i][0]=i;
    for(int j=0; j<=len2; j++) dp[0][j]=j;
    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(s1[i]==s2[j]?0:1));
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}

//f[i][j]=min(f[i-1][j-1]+same[i][j],min(f[i-1][j]+1,f[i][j-1]+1))
