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
#define ll long long
using namespace std;
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	if(n==1)
		printf("YES\n%d\n",x);
	else if(n==2)
	{
		if(x==0)
			puts("NO");
		else
			printf("YES\n0 %d\n",x);
	}
	else
	{
		puts("YES");
		int ans=0;
		for(int i=1; i<n-2; i++)
		{
			printf("%d ",i);
			ans^=i;
		}
		int a=1<<18,b=1<<17;
		printf("%d %d %d\n",a,b,a^b^ans^x);
	}
	return 0;
}
