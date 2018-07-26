 
 
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define min(a,b) (a<b?a:b)
const int N=2005;
int q[27],dp[N][N];
char p[N],l[3];
int main()
{   int n,m,aa,ss;
    while(~scanf("%d%d",&n,&m))
    {     memset(dp,0,sizeof(dp));
          scanf("%s",p);
          for(int i=0;i<n;i++)
          {
                scanf("%s",l);
                scanf("%d%d",&aa,&ss);
                q[l[0]-'a']=min(aa,ss);
          }
           for(int i=1;i<m;i++)
           {
                 for(int j=i-1;j>=0;j--)
                 {
                       dp[j][i]=min(dp[j+1][i]+q[p[j]-'a'],dp[j][i-1]+q[p[i]-'a']);
                       if(p[i]==p[j])
                        dp[j][i]=min(dp[j][i],dp[j+1][i-1]);
                 }
           }
           printf("%d\n",dp[0][m-1]);
    }
    return 0;
}
                