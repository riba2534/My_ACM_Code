 
#include<stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char a[200];
        scanf("%s",&a);
        int lenth=strlen(a);
        for(int i=0;i<lenth;i++)
        {
            if(a[i]>='A'&&a[i]<='Z')
                a[i]=tolower(a[i]);
            else
            {
                a[i]=toupper(a[i]);
            }
        }
        for(int i=0;i<lenth;i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}        