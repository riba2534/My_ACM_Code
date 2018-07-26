 
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char a[110];
        int b[110];

        scanf("%s",a);
        int lenth=strlen(a);
        for(int i=0; i<lenth; i++)
        {
            if(a[i]>='a'&&a[i]<='c')
                b[i]=2;
            else if(a[i]>='d'&&a[i]<='f')
                b[i]=3;
            else if(a[i]>='g'&&a[i]<='i')
                b[i]=4;
            else if(a[i]>='j'&&a[i]<='l')
                b[i]=5;
            else if(a[i]>='m'&&a[i]<='o')
                b[i]=6;
            else if(a[i]>='p'&&a[i]<='s')
                b[i]=7;
            else if(a[i]>='t'&&a[i]<='v')
                b[i]=8;
            else if(a[i]>='w'&&a[i]<='z')
                b[i]=9;
        }
        for(int i=0;i<lenth;i++)
        {
            printf("%d",b[i]);
        }
        printf("\n");

    }
    return 0;
}        