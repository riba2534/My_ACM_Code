#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>
#define N 1000000+50
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m,a[N],sum[N],ans[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(sum,0);
        int maxx=0;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[a[i]]++;
            maxx=max(maxx,a[i]);
        }
        mem(ans,0);
        for(int i=m; i<=maxx; i++)
            for(int j=i; j<=maxx; j=j+i)
            {
                ans[i]+=sum[j];
               // if(sum[j]==0)
               //     printf("****************\n");

            }
        int maxx2=0;
        for(int i=m; i<=maxx; i++)
        {
           // printf("ans[%d]=%d\n",i,ans[i]);
            maxx2=max(maxx2,ans[i]);
        }

        printf("%d\n",maxx2);
    }
    return 0;
}
