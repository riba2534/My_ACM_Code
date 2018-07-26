 
#include <stdio.h>
int main()
{
    int a[10];
    while(scanf("%d",&a[0])!=EOF)
    {
        for(int i=1;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        int sum=0;
        for(int i=0;i<10;i++)
        {
            if(a[i]%2!=0)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}        