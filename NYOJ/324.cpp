 
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
int cnt;
int main()
{
	int m,t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=1;
		scanf("%d",&m);
		while(m--)
		{
			cnt=(cnt+1)*2;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
        