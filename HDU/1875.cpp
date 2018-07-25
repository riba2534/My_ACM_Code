//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//#include <iostream>
//#include<math.h>
//using namespace std;
//struct hu
//{
//    int u;
//    int v;
//    double w;
//} e[20000];
//int t,n,m,i,j,s;
//int f[200];
//int cmp(hu a,hu b)
//{
//    return a.w<b.w;
//}
//int getf(int q)
//{
//    if(f[q]==q)
//        return q;
//    else
//    {
//        f[q]=getf(f[q]);
//        return f[q];
//    }
//}
//int F(int x,int y)
//{
//    int t1,t2;
//    t1=getf(x);
//    t2=getf(y);
//    if(t1!=t2)
//    {
//        f[t2]=t1;
//        return 1;
//    }
//    return 0;
//}
//int main()
//{
//    int x[200],y[200];
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        for(i=1; i<=n; i++)
//            f[i]=i;
//        int k=1;
//        for(i=1; i<=n; i++)
//        {
//            scanf("%d%d",&x[i],&y[i]);
//            for(j=1; j<i; j++)
//            {
//                e[k].u=i;
//                e[k].v=j;
//                e[k].w=sqrt((double)(x[i]-x[j])*(double)(x[i]-x[j])+(double)(y[i]-y[j])*(double)(y[i]-y[j]));
//                cout<<"w="<<e[k].w<<endl;
//                k++;
//            }
//        }
//        sort(e+1,e+k+1,cmp);
//        double sum=0;
//        int cnt=0;
//        for(i=1; i<=k; i++)
//        {
//            if(e[i].w<10||e[i].w<1000)
//                continue;
//            if(F(e[i].u,e[i].v))
//            {
//                cnt++;
//                sum+=e[i].w*100;
//            }
//            if(cnt==n-1)
//                break;
//        }
//        if(cnt<n-1)
//            printf("oh!\n");
//        else
//            printf("%.1lf\n",sum);
//    }
//    return 0;
//}
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
int n,len;
int pre[N],x[N],y[N];
struct node
{
    int u,v;
    double w;
} map[M];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
void init()
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
void Kruskal()
{
    sort(map+1,map+1+len,cmp);
    int cnt=0;
    double sum=0;
    for(int i=1; i<=len; i++)
    {
        if(map[i].w<10||map[i].w>1000)
            continue;
        if(mix(map[i].u,map[i].v))//判断是否已经连接
        {
            cnt++;
            sum+=map[i].w*100;
        }
        if(cnt==n-1)
            break;
    }
    if(cnt<n-1)
        printf("oh!\n");
    else
        printf("%.1lf\n",sum);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init();
        double w;
        len=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=1; j<i; j++)//枚举所有的岛
            {
                w=sqrt((double)(x[i]-x[j])*(double)(x[i]-x[j])+(double)(y[i]-y[j])*(double)(y[i]-y[j]));
                map[len].u=i;
                map[len].v=j;
                map[len].w=w;
             
                len++;
            }
        }
        Kruskal();
    }
    return 0;
}
