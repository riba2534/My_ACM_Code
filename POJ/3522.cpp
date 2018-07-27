#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define N 12000
#define M 100000+50
#define ll long long
using namespace std;
int n,m,ans;
struct node
{
	int u,v,w;
} map[N];
int pre[N];
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
	sort(map+1,map+m+1,cmp);
	for(int i=1; i<=m; i++)
	{
		init();
		int cnt=0,minn=inf,maxx=0;
		for(int j=i; j<=m; j++)
		{
			if(mix(map[j].u,map[j].v))
			{
				cnt++;
				minn=min(minn,map[j].w);
				maxx=max(maxx,map[j].w);
			}
			if(cnt==n-1)
				break;
		}
		if(cnt==n-1)
			ans=min(ans,maxx-minn);
	}
}
int main()
{
	int x,y,z;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		ans=inf;
		for(int i=1; i<=m; i++)
			scanf("%d%d%d",&map[i].u,&map[i].v,&map[i].w);
		Kruskal();
		if(ans==inf)
			puts("-1");
		else
			printf("%d\n",ans);
	}
	return 0;
}
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//const int inf=0x3f3f3f3f;
//const int maxn=100+10;
//const int maxv=10000;
//
//struct edge
//{
//    int u,v,w;
//} E[maxv];
//int pre[maxn];
//int n,m;
//
//void init()
//{
//    for(int i=1; i<=n; ++i)
//        pre[i]=i;
//}
//
//bool cmp(edge a,edge b)
//{
//    return a.w<b.w;
//}
//
//int Find(int x)
//{
//    if(x==pre[x])
//        return x;
//    return pre[x]=Find(pre[x]);
//}
//
//int main()
//{
//    while(scanf("%d%d",&n,&m),n||m)
//    {
//        for(int i=0; i<m; ++i)
//            scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
//        sort(E,E+m,cmp);
//        int ans=inf;
//        for(int i=0; i<m; ++i)
//        {
//            init();
//            int min_x=inf,max_x=0,cnt=0;
//            for(int j=i; j<m; ++j)
//            {
//                int fx=Find(E[j].u),fy=Find(E[j].v);
//                if(fx!=fy)
//                {
//                    ++cnt;
//                    max_x=max(max_x,E[j].w);
//                    min_x=min(min_x,E[j].w);
//                    pre[fx]=fy;
//                    if(cnt==n-1)
//                        break;
//                }
//            }
//            if(cnt==n-1)
//                ans=min(ans,max_x-min_x);
//        }
//        if(ans==inf)
//            printf("-1\n");
//        else
//            printf("%d\n",ans);
//    }
//    return 0;
//}
