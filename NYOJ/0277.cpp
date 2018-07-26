 
#include<stdio.h>
#include<string.h>
int main()
{
    int t,n;
    char s[10],a[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        strcpy(a,s);
        n=n-1;
        while(n--)
        {
            scanf("%s",s);
            if(strcmp(a,s)>0)
                strcpy(a,s);
        }
        printf("%s\n",a);
    }
    return 0;
}
        