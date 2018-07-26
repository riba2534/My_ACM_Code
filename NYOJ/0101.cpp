 
#include<stdio.h>
#include<math.h>
int main()
{
int n;
double x1,y1,x2,y2,ans;
scanf("%d",&n);
while(n--)
{
scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
printf("%.2f\n",ans);
}
return 0;
}        