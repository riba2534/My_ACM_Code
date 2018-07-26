 
#include<cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,x,y,z;
        scanf("%d%d%d%d",&m,&x,&y,&z);
        printf("%.2f\n",(double)(x*m)/(y-x)*z);
    }
    return 0;
}
        