//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<set>
//#include<iostream>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10000007
//#define debug() puts("what the fuck!!!")
//#define ll long long
//using namespace std;
//const int N=2e5+20;
//int main()
//{
//  int n,x;
//  scanf("%d%d",&n,&x);
//  if(n&1)
//  {
//      for(int i=0; i<n; i++)
//          printf("%d ",x);
//  }
//  else
//  {
//      printf("0 ");
//      for(int i=0; i<n-1; i++)
//          printf("%d ",x);
//  }
//  puts("");
//  return 0;
//}
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define CLR(a,b) memset(a,(b),sizeof(a))

const int MAXM = 1e3+10;
const int MAXN = 1e5+10;
const int mod = 1e9+7;

int main()
{
	int n, x;
	scanf("%d%d",&n,&x);
	if(n == 1)
	{
		puts("YES");
		printf("%d\n",x);
		return 0;
	}
	if(n == 2)
	{
		if(x==0)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			printf("0 %d\n",x);
		}
		return 0;
	}
	int ans = 0;
	puts("YES");
	for(int i = 1; i < n-2; i++)
	{
		printf("%d ",i);
		ans ^= i;
	}
	int k1 = 1<<18;
	int k2 = 1<<17;
	printf("%d %d %d\n",k1,k2,k1^k2^ans^x);
	return 0;
}
