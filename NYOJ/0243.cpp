 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)return 0;
        int a[200];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int min=9999999;
        for(int i=0; i<n; i++)
        {
            if(a[i]<min)
                min=a[i];
        }
        int weizhi;
        for(int i=0; i<n; i++)
        {
            if(a[i]==min)
            {
                weizhi=i;
                break;
            }

        }
        int t=a[0];
        a[0]=a[weizhi];
        a[weizhi]=t;
        for(int i=0; i<n; i++)
            printf("%d ",a[i]);
        printf("\n");
    }

    return 0;
}
        