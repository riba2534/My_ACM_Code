 
#include <stdio.h>
int main()
{
    int N,n;
    scanf("%d",&N);
    char h = 'A';
    while(N --)
    {
        scanf("%d",&n);
        n = n + 1;
        int i,j,k;
        for(i=1; i<=n; i++)
        {
            h = 'A';
            for(j=1; j<=n-i; j++)
            {
                printf(" ");
            }
            for(k=1; k<=i; k++)
            {
                printf("%c",h);
                h ++;
            }
            for(k = i + 1; k <=2*i - 1; k ++)
            {
                printf("%c",h - 2);
                h --;
            }
            printf("\n");
        }
        for(i=n - 1; i>=0; i--)
        {
            h = 'A';
            for(j=n - 1-i; j>=0; j--)
            {
                printf(" ");
            }
            for(k=i - 1; k>=0; k--)
            {
                printf("%c",h);
                h ++;
            }
            for(k = 2 * i - 3; k >=i - 1; k --)
            {
                printf("%c",h - 2);
                h --;
            }
            printf("\n");
        }
    }
    return 0;
}
        