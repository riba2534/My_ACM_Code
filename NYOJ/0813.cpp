 
#include<stdio.h>
int main()
{
int a,b,i,j,p;
while(scanf("%d%d",&a,&b)!=EOF,a,b)
{
p=0;
for(i=1;i<a;i++)
{
j=a-i;
if(b==j*i)
{
printf("YES\n");
p=1;
break;
}
}
if(p==0)
printf("NO\n");
}
return 0;
}        