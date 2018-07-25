#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,k,minn,num;
int map[31][31];
int a[31];
int dfs(int x,int step,int ans)
{
    if(step==num)
        if(minn>ans)minn=ans;
    for(int i=0;i<n;i++)
        if(a[i])
    {
        a[i]=0;
        dfs(i,step+1,ans+map[x][i]);
        a[i]=1;
    }
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        minn=99999;
        num=0;
        mem(a,0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&map[i][j]);
        scanf("%d",&k);
        for(int i=0; i<k; i++)
        {
            int m;
            scanf("%d",&m);
            if(a[m]==0)
            {
                num++;
                a[m]=1;
            }
        }
        dfs(0,0,0);
        printf("%d\n",minn);
    }
    return 0;
}
