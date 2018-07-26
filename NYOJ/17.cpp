 
#include <bits/stdc++.h>
using namespace std;
int dp[10000+100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int maxx=0;
        string s;
        cin>>s;
        int len=s.length();

        for(int i=0; i<len; i++)
        {
            dp[i]=1;
            for(int j=0; j<i; j++)
            {
                if(s[j]<s[i]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            maxx=max(maxx,dp[i]);
        }
        cout<<maxx<<endl;
    }
    return 0;
}
        