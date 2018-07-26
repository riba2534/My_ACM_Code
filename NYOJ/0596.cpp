 
#include<stdio.h>
int main()
{
int a, b, i, n, sum, c[100];
while (scanf("%d",&n)!=EOF)
{
sum = 0;
if(n == 0)
break;
else
{
for(i = 0; i < n; i ++)
{
scanf("%d%d", &a, &b);
c[i] = a + b;
if(c[i] > sum)
sum = c[i];
}
printf("%d\n",sum);
}
}
return 0;
}        