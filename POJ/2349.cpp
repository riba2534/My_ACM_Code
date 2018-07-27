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
#define N 20000+20  
#define M 500000+20  
#define MOD 1000000000+7  
#define inf 0x3f3f3f3f  
using namespace std;  
int m,k;  
int pre[N];  
double ans[550];  
struct node  
{  
    int u,v;  
    double w;  
} G[M];  
struct node1  
{  
    double x,y;  
} zz[M];  
bool cmp(node a,node b)  
{  
    return a.w<b.w;  
}  
void init(int n)  
{  
    for(int i=1; i<=n; i++)  
        pre[i]=i;  
}  
int find(int x)  
{  
    if(x==pre[x])  
        return x;  
    else  
    {  
        pre[x]=find(pre[x]);  
        return pre[x];  
    }  
}  
int mix(int x,int y)  
{  
    int fx=find(x);  
    int fy=find(y);  
    if(fx!=fy)  
    {  
        pre[fy]=fx;  
        return 1;  
    }  
    return 0;  
}  
double dist(double x1, double y1, double x2, double y2)  
{  
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));  
}  
void Kruskal(int n)  
{  
    k=0;  
    for(int i=0; i<m; i++)  
        if(mix(G[i].u,G[i].v))  
        {  
            ans[k++]=G[i].w;  
  
            if(k==n-1)  
                break;  
        }  
}  
int main()  
{  
    int t,s,p;  
    double x,y;  
    scanf("%d",&t);  
    while(t--)  
    {  
        m=0;  
        scanf("%d%d",&s,&p);  
        init(p);  
        for(int i=1; i<=p; i++)  
            scanf("%lf%lf",&zz[i].x,&zz[i].y);  
        for(int i=1; i<=p; i++)  
            for(int j=i+1; j<=p; j++)  
            {  
                G[m].u=i;  
                G[m].v=j;  
                G[m++].w=dist(zz[i].x,zz[i].y,zz[j].x,zz[j].y);  
                G[m].u=j;  
                G[m].v=i;  
                G[m++].w=dist(zz[i].x,zz[i].y,zz[j].x,zz[j].y);  
            }  
        sort(G,G+m,cmp);  
        Kruskal(p);  
        printf("%.2lf\n",ans[p-s-1]);  
    }  
    return 0;  
}  