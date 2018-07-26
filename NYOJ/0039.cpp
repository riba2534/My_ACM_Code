 
#include<stdio.h>

int main()

{

int n, x, y, z;

while (1)

{

scanf("%d", &n);

if (n == 0)

break;

x = n / 100;

y = n / 10 % 10;

z = n % 10;

if (x*x*x + y*y*y + z*z*z == n)

printf("Yes\n");

else

printf("No\n");

}

return 0;

}        