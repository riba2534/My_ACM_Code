 
#include<stdio.h>
int main()
{
    int a,b,c;
    int n;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&a,&b);
        if(a+b>n&&a+n>b&&b+n>a)
            printf("Great,you are genius!\n ");
        else
            printf("oh,my god!\n");
    }
    return 0;
}
        