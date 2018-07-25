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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 200200
#define M 1000000
#define ll long long
using namespace std;
pair<ll,ll>pp[2000];//第一维存储长度，第二位存储价值
ll dp[5000][5];//dp[i][j]代表前i根木棍，露出的棍子数为j,所能获得的最大价值
int main()
{
    ll t,n,L,q=1;
    scanf("%lld",&t);
    while(t--)
    {
        ll maxx=0;
        scanf("%lld%lld",&n,&L);//物品的种类和个数和筒子空间的容量
        L<<=1;//为了防止出现小数难处理，所以乘以2
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld%lld",&pp[i].first,&pp[i].second);
            pp[i].first<<=1;
            maxx=max(maxx,pp[i].second);
        }
        mem(dp,0);
        for(ll i=1; i<=n; i++)
        {
            for(ll j=L; j>=pp[i].first/2; j--)
            {
                for(ll k=0; k<=2; k++)
                {
                    if(j>=pp[i].first)//当当前的空间容量大于要放的木棍长度时
                        dp[j][k]=max(dp[j][k],dp[j-pp[i].first][k]+pp[i].second);//找出放下这一根木棍与不放这一根木棍的最大值
                    if(k>0)//要露出木棍的时候
                        dp[j][k]=max(dp[j][k],dp[j-pp[i].first/2][k-1]+pp[i].second);
                    maxx=max(maxx,dp[j][k]);
                }
            }
        }
        printf("Case #%lld: %lld\n",q++,maxx);
    }
    return 0;
}
