 
#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[100],b[100];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            x+=a[i];
            y+=b[i];
        }
        if(x>y)
            printf("X\n");
        else if(x==y)
            printf("none\n");
        else if(x<y)
            printf("Y\n");


    }
}        