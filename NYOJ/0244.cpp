 
#include <stdio.h>
int main()
{
    int a,b;
    int i,n;
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%x%c%x",&a,&c,&b);
        if(c=='+')
            printf("%o\n",a+b);
        else if(c=='-')
            printf("%o\n",a-b);
    }
    return 0;
}
        