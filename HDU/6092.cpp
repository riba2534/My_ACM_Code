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
#define N 300
#define ll long long
using namespace std;
int a[10010],b[10010],dp[10010];
int main()
{
    int t,n,m,x;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,0);
        scanf("%d%d",&n,&m);
        int p=0;
        for(int i=0; i<=m; i++)
            scanf("%d",&b[i]);
        dp[0]=1;
        for(int i=1; i<=m; i++)
        {
            int x=b[i]-dp[i];
            for(int j=0; j<x; j++)
            {
                a[p++]=i;
                for(int k=m; k>=i; k--)
                    dp[k]+=dp[k-i];
            }
        }
        for(int i=0;i<p;i++)
        {
            if(i)printf(" ");
            printf("%d",a[i]);
        }
        puts("");
    }
    return 0;
}
