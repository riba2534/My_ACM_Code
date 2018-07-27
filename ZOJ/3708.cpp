#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int x[N],y[N];
int vis[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
            scanf("%d",&x[i]);
        for(int i=0; i<m; i++)
            scanf("%d",&y[i]);
        int sum=0;
        for(int i=0; i<m; i++)
        {
            if(vis[x[i]][y[i]]==0)
            {
                vis[x[i]][y[i]]=vis[y[i]][x[i]]=1;
                sum++;
            }

        }
        printf("%.3lf\n",1.0*sum/n);
    }
    return 0;
}