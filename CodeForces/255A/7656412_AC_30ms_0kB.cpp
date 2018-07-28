#include <stdio.h>
int q[100];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a=0,b=0,c=0;
        for(int i=1; i<=n; i++)
            scanf("%d",&q[i]);
        int j;
        for(j=1; j<=n; j+=3)
            a+=q[j];
        for(j=2; j<=n; j+=3)
            b+=q[j];
        for(j=3; j<=n; j+=3)
            c+=q[j];
        if(a>b&&a>c)printf("chest\n");
        if(b>a&&b>c) printf("biceps\n");
        if(c>a&&c>b)printf("back\n");
    }
    return 0;
}
