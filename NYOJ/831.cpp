 
#include <stdio.h>
int main()
{
    int a[210];
    int n;
    while(~ scanf("%d",&n))
    {
        int sum=0,q;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sum+=n;
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
        }
       // printf("%d\n",sum);
        q=n/5;
        sum+=(5*q);
        printf("%d\n",sum);
    }




    return 0;
}        