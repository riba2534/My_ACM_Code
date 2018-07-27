#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100000+7;
int a[N],sum[N],vis[N];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        mem(vis,-1);
        vis[0]=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=(sum[i-1]+a[i])%n;
        }
        for(int i=1; i<=m; i++)
        {
            if(vis[sum[i]]==-1)
                vis[sum[i]]=i;
            else
            {
                //printf("%d\n",i-vis[sum[i]]);
                for(int j=vis[sum[i]]+1; j<=i; j++)
                {
                    printf("%d ",j);
                }
                break;
            }
        }
//        for(int i=1; i<=m; i++)
//        {
//            printf("%d ",sum[i]);
//        }
        puts("");
    }
    return 0;
}
