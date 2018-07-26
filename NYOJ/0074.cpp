 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n, a, b, c, A, B, C, num;
	while (1)
	{
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
			break;
		else
		{
			num = 0;
			a = m % 10; 
			b = (m - a) % 100; 
			c = (m - a - b);
			A = n % 10;
			B = (n - A) % 100;
			C = (n - A - B);
			if (a + A >= 10)
			{
				num++;
				b += (a + A);
			}
			if (b + B >= 100)
			{
				num++;
				c += (b + B);
			}
			if (c + C >= 1000)
				num++;
			printf("%d\n", num);
		}
	}
	return 0;
}        