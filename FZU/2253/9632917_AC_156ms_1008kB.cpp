//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 1000007
//#define N 8
//#define M 12357
//#define ll long long
//using namespace std;
//int a[100000+50];
//int main()
//{
//  int n;
//  while(~scanf("%d",&n))
//  {
//      int sum=0;
//      for(int i=0; i<n; i++)
//      {
//          scanf("%d",&a[i]);
//          if(a[i]==1)
//          {
//              sum++;
//              a[i]=-1;
//          }
//          else
//              a[i]=1;
//      }
//      int maxx=0,cnt=0;
//      if(a[0]==-1)a[0]=0;
//      for(int i=0; i<n; i++)
//      {
//          cnt+=a[i];
//          maxx=max(maxx,cnt);
//          if(cnt<0)cnt=0;
//      }
//      printf("%d\n",maxx+sum);
//  }
//  return 0;
//}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1e5+10;
int a[maxn],sum[maxn];
int solve(int n)
{
	int i,j,minn=1e5,sum_num=0;
	for(i=1; i<=n; i++)
	{
		sum[i]=sum[i-1]+(a[i]==1?1:-1);
		if(minn>sum[i])
			minn=sum[i];
		sum_num+=a[i];
		if(sum[i]>0) sum[i]=0;
	}
	return sum_num-minn;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i=1; i<=n; i++)
			scanf("%d",&a[i]);
		printf("%d\n",solve(n));
	}
	return 0;
}
