 
#include<stdio.h>
int jc(int a)
{
    if(a == 1)
        return 1;
    else
        return a * jc(a - 1);
}
int main()
{
    int x, y;
    while(scanf("%d,%d", &x)!=EOF)
        printf("%d\n", jc(x));
    return 0;
}        