 
#include <stdio.h>
int main()
{
int n;
scanf("%d", &n);
int y[12] = {31,0,31,30,31,30,31,31,30,31,30,31 };
while (n--)
{
int a, b, c, tianshu = 0;
scanf("%d %d %d", &a, &b, &c);
if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
{
//闰年
y[1] = 29;
for (int i = 1; i <b; i++)
{
tianshu = tianshu + y[i-1];
}
tianshu += c;
//tianshu += 1;
printf("%d\n", tianshu);
}
else
{
//平年
y[1] = 28;
for (int i = 1; i < b; i++)
{
tianshu = tianshu + y[i-1];
}
tianshu += c;
//tianshu -= 1;
printf("%d\n", tianshu);
}
}
return 0;
}        