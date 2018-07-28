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
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=50000+20;
int n,m;
struct node
{
    int op,x;
} num[N];
int ans[N],vis[N],is[N];
int main()
{
    int t,op,x;
    scanf("%d",&t);
    while(t--)
    {
        mem(ans,0);
        mem(vis,0);
        mem(is,0);
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&num[i].op,&num[i].x);
        }

        for(int i=m; i>=1; i--)
        {
            if(!vis[i])
            {
                int x=num[i].x;
                if(num[i].op==3)
                    vis[x]=1;
                else if(num[i].op==2)
                {
                    if(is[x]==0)
                    {
                        ans[x]=0;
                        is[x]=1;
                    }
                }
                else if(num[i].op==1)
                {
                    if(is[x]==0)
                    {
                        ans[x]=1;
                        is[x]=1;
                    }
                }
            }
        }
        int res=0;
        for(int i=1; i<=n; i++)
            if(ans[i])
                res++;
        printf("%d\n",res);
        for(int i=1; i<=n; i++)
            if(ans[i])
                printf("%d ",i);
        printf("\n");
    }
    return 0;
}


