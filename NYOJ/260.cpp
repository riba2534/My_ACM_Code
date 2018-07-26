 
#include <stdio.h>
int main()
{
	int n,i=0;
	
	scanf("%d",&n);
	while(1)
	{
		int t,j=1,sum=0;
		scanf("%d",&t);
		while(j<=t)
		{
			sum=sum+( j * (j + 1) / 2);
			j++;
		}

		printf("%d\n",sum);
		i++;
		if(i>=n)
			break;
	}

	return 0;
}        