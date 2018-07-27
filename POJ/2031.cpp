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
#define N 100+20  
#define M 10000+20  
#define MOD 1000000000+7  
#define inf 0x3f3f3f3f  
using namespace std;  
int n,m;  
double map[N][N],dis[N];  
bool vis[N];  
struct node  
{  
    double x,y,z,r;  
} G[N];  
void init()  
{  
    for(int i=1; i<=n; i++)  
        for(int j=1; j<=n; j++)  
            i==j?map[i][j]=map[j][i]=0:map[i][j]=map[j][i]=inf;//初始化  
}  
void Prim()  
{  
    double minn;  
    int k;  
    for(int i=1; i<=n; i++)  
    {  
        dis[i]=map[1][i];  
        vis[i]=0;  
    }  
    vis[1]=1;  
    double sum=0;  
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
    printf("%.3lf\n",sum);  
}  
double dist(node a,node b)  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));  
}  
int main()  
{  
    while(~scanf("%d",&n)&&n)  
    {  
        init();  
        mem(map,0);  
        mem(dis,0);  
        mem(vis,0);  
        for(int i=1; i<=n; i++)  
            scanf("%lf%lf%lf%lf",&G[i].x,&G[i].y,&G[i].z,&G[i].r);  
        for(int i=1; i<=n-1; i++)  
            for(int j=i+1; j<=n; j++)  
            {  
                double temp=dist(G[i],G[j]);  
                if(temp-G[i].r-G[j].r<=0)//算出两个球是否相交  
                    map[i][j]=map[j][i]=0;  
                else  
                    map[i][j]=map[j][i]=temp-G[i].r-G[j].r;  
            }  
        Prim();  
    }  
    return 0;  
}  