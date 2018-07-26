 
#include<stdio.h>
int main()
#define pi 3.1415926 
{
int n;
double s,m;
scanf("%d",&n);
while(n--)
{
scanf("%lf",&m);
s=(pi*m*m)/3;
printf("%.2lf\n",s);
}
return 0;
}        