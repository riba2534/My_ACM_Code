#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100000+20
#define inf 0x3f3f3f3f
#define M 1000000+2000
#define LL long long
using namespace std;
int h[N],vis[N];
int main()
{
    int n,m,k,q=1;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        mem(h,0);mem(vis,0);
        for(int i=0; i<n; i++)
            scanf("%d",&h[i]);
        sort(h,h+n);
        int a,b,s=1;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            int left=lower_bound(h,h+n,s+1)-h;
            int right=lower_bound(h,h+n,a+1)-h;
            s=b;
            vis[left]++;
            vis[right]--;
        }
        int num=0,sum=0;
        for(int i=0;i<n;i++)
        {
            num+=vis[i];
            if(num>=k)
                sum++;
        }
        printf("Case %d: %d\n",q++,sum);
    }
    return 0;
}


