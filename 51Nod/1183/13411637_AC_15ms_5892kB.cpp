#include <bits/stdc++.h>
using namespace std;
const int N=1000+20;
int dp[N][N];
int get_editdis(string s1,string s2)
{
    int len1=s1.size();
    int len2=s2.size();
    for(int i=0; i<=len1; i++)dp[i][0]=i;
    for(int j=0; j<=len2; j++)dp[0][j]=j;
    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:1));
        }
    }
    return dp[len1][len2];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<get_editdis(s1,s2)<<endl;
    return 0;
}
