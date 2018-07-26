 
#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stack>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
int a[1000];
int n,k;
bool dfs(int s,int sum)
{
	if(s==n)return sum==k;
	if(dfs(s+1,sum))return 1;
	if(dfs(s+1,sum+a[s]))return 1;
	return 0;
}
int main()
{
	n=0;
	while(~scanf("%d",&n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		scanf("%d",&k);
		if (dfs(0,0))
			printf("Of course,I can!\n");
		else
			printf("Sorry,I can't!\n");
		
	}
	return 0;
}        