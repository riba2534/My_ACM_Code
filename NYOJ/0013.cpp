 
#include <stdio.h>
int main()
{
  int m;
   scanf("%d",&m);
   int a[30];
   a[0]=1;a[1]=1;
   for(int i=2;i<30;i++)
   {
       a[i]=a[i-1]+a[i-2];
   }

   while(m--)
   {
       int n;
       scanf("%d",&n);
       printf("%d\n",a[n-1]);

   }
    return 0;
}        