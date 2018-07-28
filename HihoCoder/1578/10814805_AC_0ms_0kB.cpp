#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll longlong
using namespace std;
const int N=100+20;
int a[N],vis[N];
int main()
{
	int n,m,k,x;
	while(~scanf("%d%d",&n,&m))
	{
		mem(vis,0);
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		scanf("%d",&k);
		for(int i=0; i<k; i++)
		{
			scanf("%d",&x);
			vis[x]=1;
		}
		int minn=inf,l,r;
		for(int i=0; i<=n-m; i++)
		{
			if(vis[i]) continue;
			int maxb=inf;
			int t=0;
			for(int j=i+1; j<n; j++)
			{
				if(!vis[j])
				{
					if(a[j]<maxb)
					{
						maxb=a[j];
						k=j;
					}
					t++;
					if(t==m-1)break;
				}
			}
			if(t!=m-1)break;
			if(a[i]+a[k]<minn)
			{
				minn=a[i]+a[k];
				l=i;
				r=k;
			}
		}
		printf("%d %d\n",l,r);
	}
	return 0;
}
