 
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
int t,n,m;
int map[110][110];
int temp[110][110];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		mem(map,0);
		mem(temp,0);
		int maxx=-inf,sum;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%d",&map[i][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				temp[i][j]=temp[i-1][j]+map[i][j];
		for(int i=1; i<=n; i++)
			for(int j=i; j<=n; j++)
			{
				sum=0;
				for(int k=1; k<=m; k++)
				{
					if(sum>0)
						sum+=temp[j][k]-temp[i-1][k];
					else
						sum=temp[j][k]-temp[i-1][k];
					maxx=max(maxx,sum);
				}
			}
		printf("%d\n",maxx);
	}
	return 0;
}
        