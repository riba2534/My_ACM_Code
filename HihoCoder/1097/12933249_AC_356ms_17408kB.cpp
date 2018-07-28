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
const int N=1e3+10;
const int M=1e4+10;
int e[N][N],vis[N],dis[N],n;
void prim()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=e[1][i];
        vis[i]=0;
    }
    vis[1]=1;
    int sum=0;
    for(int i=1; i<=n-1; i++)
    {
        int minn=inf,k=1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        vis[k]=1;
        sum+=dis[k];
        for(int j=1; j<=n; j++)
            if(!vis[j]&&e[k][j]<dis[j])
                dis[j]=e[k][j];
    }
    printf("%d\n",sum);
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&e[i][j]);
    prim();
    return 0;
}
