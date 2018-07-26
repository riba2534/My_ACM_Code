 
#include <stdio.h>
#include <math.h>
int main()
{
    int a,b;
    int num1[52],num2[52];
    while(1)
    {
        int k=0,m=0;
        scanf("%d%d",&a,&b);
        if(a==0&&b==0)
            return 0;
        while(a>=10)
        {
            num1[k++]=a%10;
            a/=10;
        }
        // printf("%d\n",k);
        num1[k]=a;
        while(b>=10)
        {
            num2[m++]=b%10;
            b/=10;
        }
        // printf("%d\n",m);
        num2[m]=b;
        a=0;
        b=0;
        int t1=k,t2=m;
        for(int i=0; i<=k; i++)
        {
            int l=(int)(pow(10,t1)+0.1);

            a+=num1[i]*l;
       // printf("t1=%d,num1[%d]=%d,a=%d,l=%d\n",t1,i,num1[i],a,l);
            t1--;
        }
        for(int i=0; i<=m; i++)
        {
             int l=(int)(pow(10,t2)+0.1);

            b+=num2[i]*l;
           // printf("t2=%d,num2[%d]=%d,b=%d,l=%d\n",t2,i,num2[i],b,l);
            t2--;
        }
        printf("%d\n",a+b);
    }

    return 0;
}

        