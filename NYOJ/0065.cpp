 
#include <stdio.h>
int main()
{
	int q, i = 0;
	scanf("%d",&q);
	while (1)
	{
		int m, sum = 0;
		scanf("%d", &m);
		for (int j = 1; j <= m; ++j)
		{
			int t = 1;
			for (int i = 1; i <= j; i += 2)
			{
				t *= i;
			}
			sum += t;
		}
		printf("%d\n", sum);

		i++;
		if (i >= q)
			break;
	}
	return 0;
}        