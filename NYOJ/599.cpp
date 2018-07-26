 
#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h;
        scanf("%d",&h);
        if(h>0&&h<=10)
        {
            printf("1\n");
        }
        else
        {
            if(h%5==0)
            {
                printf("%d\n",(h-10)/5+1);
            }
            else
            {
               printf("%d\n",(h-10)/5+2);
            }

        }
        printf("\n");
    }
    return 0;
}        