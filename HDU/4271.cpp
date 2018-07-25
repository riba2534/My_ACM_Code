#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
typedef long long ll;
const int N=1e5+200;
char s[N],t[12],ans[12];
int dp[12][N];
int solve(int l1,int l2,char *s1,char *s2)
{
    int now=INF;
    for(int i=1; i<=l1; i++)
    {
        dp[i][0]=i;
        for(int j=1; j<=l2; j++)
        {
            dp[i][j]=min(dp[i-1][j-1]+(s1[i-1]!=s2[j-1]),min(dp[i-1][j],dp[i][j-1])+1);
            if(i==l1)now=min(now,dp[i][j]);
        }
    }
    return now;
}

int main()
{
    int q;
    while(~scanf("%s",s))
    {
        int n=strlen(s),minn=INF;
        int extend=10;
        for(int i=0; i<=extend; i++)
            s[n+i]=s[i];
        s[n+10]='\0';
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",t);
            int m=strlen(t),now=INF;
            if(m<=n)
            {
                now=solve(m,n+min(n,extend),t,s);
            }
            else
            {
                for(int i=0; i<n; i++)
                    now=min(now,solve(m,n,t,s+i));
            }
            if(minn>now||(minn==now&&strcmp(ans,t)>0))
            {
                minn=now;
                memcpy(ans,t,sizeof(t));
            }
        }
        printf("%s %d\n",ans,minn);
    }
    return 0;
}
