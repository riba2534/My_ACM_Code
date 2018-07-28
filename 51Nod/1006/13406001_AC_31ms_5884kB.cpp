#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=1000+20;
int dp[N][N];
int get_num(string a,string b)
{
    a="0"+a;
    b="0"+b;
    int len1=a.size()-1;
    int len2=b.size()-1;
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[len1][len2];
}
string get_lcs(string a,string b)
{
    a="0"+a;
    b="0"+b;
    int len1=a.size()-1;
    int len2=b.size()-1;
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    string ans="";
    for(int i=len1,j=len2;i>=1&&j>=1;)
    {
        if(a[i]==b[j])
        {
            ans+=a[i];
            i--,j--;
        }
        else if(dp[i][j-1]>=dp[i-1][j])
            j--;
        else
            i--;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<get_lcs(a,b)<<endl;
    return 0;
}
