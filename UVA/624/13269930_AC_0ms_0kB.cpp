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
#define mod 1000000009
typedef long long ll;
const int N=10000+5;
int a[N],dp[N],n,v;
int vis[25][N];
int main()
{
    while(cin>>v>>n)
    {
        mem(a,0);
        mem(dp,0);
        mem(vis,0);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=v; j>=a[i]; j--)
            {
                if(dp[j]<=dp[j-a[i]]+a[i])
                {
                    dp[j]=dp[j-a[i]]+a[i];
                    vis[i][j]=1;
                }

            }
        }
        for(int i=n-1,k=v; i>=0; i--)
        {
            if(vis[i][k])
            {
                printf("%d ",a[i]);
                k-=a[i];
            }
        }
        printf("sum:%d\n",dp[v]);
    }
    return 0;
}
