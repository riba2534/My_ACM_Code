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
#define N 330
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int pre[N];
struct node
{
	int u,v,w;
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
	init();
	sort(map+1,map+m+1,cmp);
	int cnt=0,sum=0;
	for(int i=1; i<=m; i++)
	{
		if(mix(map[i].u,map[i].v))
		{
			cnt++;
			sum=max(sum,map[i].w);
		}
		if(cnt==n-1)
			break;
	}
	printf("%d %d\n",n-1,sum);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d%d%d",&map[i].u,&map[i].v,&map[i].w);
	Kruskal();
	return 0;
}
