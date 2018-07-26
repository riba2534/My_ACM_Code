 
#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    char a[11];
    while(t--)
    {
       scanf("%s",a);
       int len=strlen(a);
       for(int i=len-1;i>=0;i--)
       {
        if(a[i]=='0'||a[i]=='1')
            printf("O");
        else if(a[i]=='2'||a[i]=='3')
            printf("T");
        else if(a[i]=='4'||a[i]=='5')
            printf("F");
        else if(a[i]=='6'||a[i]=='7')
            printf("S");
        else if(a[i]=='8')
            printf("E");
        else if(a[i]=='9')
            printf("N");
       }
       printf("\n");
    }
    return 0;
}        