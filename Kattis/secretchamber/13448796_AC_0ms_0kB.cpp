#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pir pair<int,int>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=60+20;
int n,m;
int dp[N][N];
int main()
{
    char c1,c2;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>c1>>c2;
        dp[c1-'a'][c2-'a']=1;
    }
    for(int k=0; k<26; k++)
        for(int i=0; i<26; i++)
            for(int j=0; j<26; j++)
                if(dp[i][k]&&dp[k][j])
                    dp[i][j]=1;
    string s1,s2;
    while(m--)
    {
        cin>>s1>>s2;
        int len1=s1.size(),len2=s2.size();
        if(len1!=len2)
        {
            puts("no");
        }
        else
        {
            int flag=1;
            for(int i=0; i<len1&&flag; i++)
            {
                if(s1[i]!=s2[i]&&!dp[s1[i]-'a'][s2[i]-'a'])
                    flag=0;

            }
            if(flag)puts("yes");
            else puts("no");
        }


    }



    return 0;
}
