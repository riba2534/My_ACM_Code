 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100000+10
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int n,k,pos;
int a[100];
stack<int>s;
int dfs(int step,int sum)
{
	if(step==n) return sum==k;
	if(dfs(step+1,sum)) return 1;
	if(dfs(step+1,sum+a[step]))
	{
		s.push(a[step]);
		return 1;
	}
	return 0;
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		while(!s.empty())s.pop();

		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		if(dfs(0,0))
		{
			puts("YES");
			while(!s.empty())
			{
				int x=s.top();
				printf("%d ",x);
				s.pop();
			}
			puts("");
		}
		else
			puts("NO");
	}
	return 0;
}
        