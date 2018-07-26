 
#include<stdio.h>
int main()
{
char name[100];
double number,price,sum;
sum=0;
while(scanf("%s%lf%lf",name,&number,&price)!=EOF)
{
sum+=number*price;
}
printf("%.1lf\n",sum+0.05);
return 0;
}        