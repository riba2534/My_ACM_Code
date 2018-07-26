 
#include <stdio.h>
int main()
{
	int n, b;
	while (scanf("%d %d", &n, &b) != EOF)
	{
		int sum = n/b;
		/*
		for (int i = 1; i <= n; i++)
		{
			if (i%b == 0)
			{
				sum++;
			}
		}
		*/
		printf("%d\n", sum);
	}
	return 0;
}        