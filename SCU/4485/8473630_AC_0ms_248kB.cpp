#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <string>
#define N 300
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node
{
    int a,b;
}zz[N];
int dp[N];
int n,m;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,0);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d",&zz[i].a,&zz[i].b);
        for(int i=0;i<m;i++)
        {
            for(int j=n;j>=zz[i].a;j--)
            {
                dp[j]=max(dp[j],dp[j-zz[i].a]+zz[i].b);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}