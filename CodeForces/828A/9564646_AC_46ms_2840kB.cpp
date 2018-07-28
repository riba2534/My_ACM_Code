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
int num[N];
int main()
{
	int n,a,b,c=0;
	int sum=0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0; i<n; i++)
		scanf("%d",&num[i]);
	for(int i=0; i<n; i++)
	{
		if(num[i]==1)
		{
			if(a>0)
				a--;
			else if(b>0)
			{
				b--;
				c++;
			}
			else if(c>0)
				c--;
			else
				sum++;
		}
		else if(b>0)
			b--;
		else
			sum+=2;
	}
	printf("%d\n",sum);
	return 0;
}
