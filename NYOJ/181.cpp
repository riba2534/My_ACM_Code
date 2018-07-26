 
#include<stdio.h>
long long jiecheng(long long n)
{
    return n==0?1:jiecheng(n-1)*n;
}
int main()
{
   long long t;
   scanf("%lld",&t);
   while(t--)
   {
       long long n,sum=1;
       scanf("%lld",&n);
       if(n==1)
        printf("1\n");
       else
       {
           for(long long i=2;i<=n;i++)
           {
               if(i%2==0)
               sum+=jiecheng(i);
               else
                sum-=jiecheng(i);
           }

           printf("%lld\n",sum);
       }
   }

    return 0;

}
        