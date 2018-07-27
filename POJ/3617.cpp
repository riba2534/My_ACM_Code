#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char a[2016];
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("\n%c",&a[i]);
        int a1=0,b1=n-1,p=0,l;
        while(a1<=b1)
        {
            l=0;
            for(int i=0; a1+i<=b1; i++)
            {
                if(a[a1+i]<a[b1-i])
                {
                    l=1;
                    break;
                }
                else if(a[a1+i]>a[b1-i])break;
            }
            if(l)
                printf("%c",a[a1++]);
            else
                printf("%c",a[b1--]);
            if(++p == 80)
            {
                putchar('\n');
                p = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
