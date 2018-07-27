#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <cmath>  
#include <string>  
#include <iostream>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define N 1000+20  
#define M 10000+20  
#define MOD 1000000000+7  
#define inf 0x3f3f3f3f  
using namespace std;  
int n,m;  
int map[N][N],dis[N];  
bool vis[N];  
void init()  
{  
    for(int i=1; i<=n; i++)  
        for(int j=1; j<=n; j++)  
            i==j?map[i][j]=0:map[i][j]=inf;  
}  
void Prim()  
{  
    int minn;  
    int k;  
    for(int i=1; i<=n; i++)  
    {  
        dis[i]=map[1][i];  
        vis[i]=0;  
    }  
    vis[1]=1;//从1号点开始  
    int sum=0;  
    for(int i=1; i<=n-1; i++)  
    {  
        minn=inf;  
        for(int j=1; j<=n; j++)  
        {  
            if(!vis[j]&&dis[j]<minn)  
            {  
                minn=dis[j];  
                k=j;  
            }  
        }  
  
        vis[k]=1;  
        sum+=dis[k];  
        for(int j=1; j<=n; j++)  
            if(!vis[j]&&map[k][j]<dis[j])  
                dis[j]=map[k][j];  
    }  
    printf("%d\n",sum);  
}  
int main()  
{  
    while(~scanf("%d",&n))  
    {  
        int x;  
        init();  
        for(int i=1; i<=n; i++)  
        {  
            for(int j=1; j<=n; j++)  
            {  
                scanf("%d",&x);  
                map[i][j]=min(map[i][j],x);  
            }  
        }  
        scanf("%d",&m);  
        int a,b;  
        for(int i=1; i<=m; i++)  
        {  
            scanf("%d%d",&a,&b);  
            map[a][b]=map[b][a]=0;  
        }  
        Prim();  
    }  
    return 0;  
}  