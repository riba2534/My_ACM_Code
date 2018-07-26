 
#include<stdio.h> 
#define IP 3.1415926
int main()
{
double R,A;
int a;
while(scanf("%lf",&R)!=EOF)
{
A=(4*IP*R*R*R)/3;
A=A+0.5;
a=int(A);
printf("%d\n",a);
}
return 0;

}        