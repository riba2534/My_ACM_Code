 
#include <stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
       int a[10];
       int b;
       for(int i=0;i<10;i++)
       {
           scanf("%d",&a[i]);
       }
       scanf("%d",&b);
       b+=30;
       int sum=0;
       for(int i=0;i<10;i++)
       {
           if(b>=a[i])
            sum++;
       }
       printf("%d\n",sum);
   }



    return 0;
}        