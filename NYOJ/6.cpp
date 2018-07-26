 
#include<stdio.h>
#include<math.h>
double f(double r)
{
double b=2*sqrt(r*r-1);
return b;
}
int main()
{
int N;
scanf("%d",&N);
while(N--)
{
int n,j,i,d=0;
scanf("%d",&n);
double a[610],t,s=0;
for(i=0; i<n; i++)
scanf("%lf",&a[i]);
for(i=0; i<n; i++)
for(j=0; j<n-i-1; j++)
if(a[j]<=a[j+1])
t=a[j],a[j]=a[j+1],a[j+1]=t;
for(i=0; i<n; i++)
{
s+=f(a[i]);
d++;
if(s>=20)
break;
}
printf("%d\n",d);
}
}        