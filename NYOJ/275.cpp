 
#include <stdio.h>
int main()
{
    int a[2000], i;
    long long n;
    while (scanf("%lld", &n)!=EOF)
    {
        if(n==0)
            printf("0");
        else
        {
            i = 0;
            while(n)
            {
                a[i++] = n % 2;
                n = n / 2;
            }
            while(i--)
            {
                printf("%d",a[i]);
            }
        }
        printf("\n");
    }
}        