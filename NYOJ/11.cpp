 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int i,n;
		scanf("%d",&n);
		for(i=1; i<=n; i=i+2)
			printf("%d ",i);
		printf("\n");
		for(i=2; i<=n; i=i+2)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}        