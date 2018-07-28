//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<set>
//#include<iostream>
//#include <cmath>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10000007
//#define debug() puts("what the fuck!!!")
//#define N (10000+200)
//#define ll long long
//using namespace std;
//int map[105][105];
//int vis[105][105];
//struct node
//{
//  int u,v;
//}G[41000];
//int n,m;
//int main()
//{
//  int t,a,b,c;
//  scanf("%d",&t);
//  while(t--)
//  {
//      mem(map,0);mem(vis,0);
//      scanf("%d%d",&n,&m);
//      for(int i=1; i<=n; i++)
//          for(int j=1; j<=n; j++)
//              map[i][j]=(i==j)?0:inf;
//      for(int i=1; i<=m; i++)
//      {
//          scanf("%d%d%d",&a,&b,&c);
//          G[i].u=a,G[i].v=b;
//          if(map[a][b]>c)
//              map[a][b]=map[b][a]=c;
//      }
//      for(int k=1; k<=n; k++)
//      for(int i=1; i<=n; i++)
//      for(int j=1; j<=n; j++)
//      if(map[i][k]+map[k][j]<map[i][j])
//      {
//          map[i][j]=map[i][k]+map[k][j];
//          vis[i][k]=vis[k][j]=1;
//      }
//      int sum=0;
//      for(int i=1;i<=m;i++)
//      {
//          if(!vis[G[i].u][G[i].v])
//              sum++;
//      }
//      printf("%d\n",sum);
//  }
//  return 0;
//}
//
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int spot=100+10;
int map[spot][spot],b[spot][spot];
int main()
{
	int t,q=0;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,x,y,z,ans=0,i,j,k;
		memset(map,0x3f,sizeof(map));
		scanf("%d%d",&n,&m);
		int last_ans=0;
		for(i=1; i<=m; i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(map[x][y]!=inf)
				last_ans++;
			map[x][y]=min(map[x][y],z);
			map[y][x]=map[x][y];
		}
		for(i=1; i<=n; i++) 
			map[i][i]=0;
		memcpy(b,map,sizeof(b));
		for(k=1; k<=n; k++)
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++)
				{
					if(map[i][j]>map[i][k]+map[k][j])
						map[i][j]=map[i][k]+map[k][j];
				}
		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				for(k=1; k<=n; k++)
				{
					if(map[i][j]<b[i][j]&&b[i][j]!=inf&&i!=j&&i!=k&&k!=j)
					{
						last_ans++;
						break;
					}
					if(map[i][j]==map[i][k]+map[k][j]&&b[i][j]!=inf&&i!=j&&i!=k&&k!=j)
					{
						last_ans++;
						break;
					}
				}
		printf("Case %d: %d\n",++q,last_ans);
	}
	return 0;
}
