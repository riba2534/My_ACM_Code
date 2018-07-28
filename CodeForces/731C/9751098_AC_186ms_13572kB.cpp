#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 1000007
#define N 200000+20
#define M 100000+50
#define ll long long
using namespace std;
int n,m,k;
int a[N],pre[N];
vector<int>v[N];
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
void mix(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		pre[fy]=fx;
}
int main()
{
	int x,y;
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);//目前的颜色
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);//读入每天穿的颜色，并且加入并查集
		mix(x,y);
	}
	for(int i=1; i<=n; i++)
		v[find(i)].push_back(a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()<=1)
			continue;
		map<int,int>mp;
		int maxx=0;
		for(int j=0;j<v[i].size();j++)
		{
			mp[v[i][j]]++;
			maxx=max(maxx,mp[v[i][j]]);
		}
		ans+=v[i].size()-maxx;
	}
	printf("%d\n",ans);
	return 0;
}

