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
#define N (200000+50)
#define ll long long
using namespace std;
char map[110][110];
int main()
{
	int n,m,tot=0;
	int x1=inf,x2=0,y1=inf,y2=0;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%s",map[i]);
		for(int j=0; j<m; j++)
		{
			if(map[i][j]=='B')
			{
				tot++;

				x1=min(x1,i);
				x2=max(x2,i);
				y1=min(y1,j);
				y2=max(y2,j);
			}
		}
	}
	//printf("tot=%d,%d %d %d %d\n",tot,x1,x2,y1,y2);
	if(!tot)
	{
		puts("1");
		return 0;
	}
	int c=max(x2-x1,y2-y1)+1;
	if(c>n||c>m)
		puts("-1");
	else
		printf("%d\n",c*c-tot);
	return 0;
}
