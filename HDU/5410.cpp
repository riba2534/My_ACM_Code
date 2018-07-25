#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N (2000+20)
#define M 200010
#define MOD (1000000000+7)
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
int m,n,dp[N];
struct node
{
    int w,a,b;
} zz[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,0);
        scanf("%d%d",&m,&n);
        for(int i=0; i<n; i++)
            scanf("%d%d%d",&zz[i].w,&zz[i].a,&zz[i].b);
        for(int i=0; i<n; i++)
        {
            for(int j=m; j>=zz[i].w; j--)//01背包
                dp[j]=max(dp[j],dp[j-zz[i].w]+zz[i].a+zz[i].b);
            for(int j=zz[i].w; j<=m; j++)//完全背包
                dp[j]=max(dp[j],dp[j-zz[i].w]+zz[i].a);
        }
        int sum=-1;
        for(int i=0; i<=m; i++)
            sum=max(sum,dp[i]);
        printf("%d\n",sum);
    }
    return 0;
}