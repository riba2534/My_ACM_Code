 
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int i,j,n,sum;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        scanf("%s%s",&a,&b);

        for(i=0; i<strlen(a); i++)
        {

            for(j=0; j<strlen(b); j++)
            {

                sum+=(a[i]-'0')*(b[j]-'0');
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}        