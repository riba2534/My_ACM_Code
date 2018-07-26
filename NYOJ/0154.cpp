 
#include<stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[20];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        if(n%2!=0)
        {
            printf("%d\n",a[(n+1)/2-1]);
        }
        else
        {
            if(a[n/2-1]>a[n/2])
                printf("%d\n",a[n/2-1]);
            else
                printf("%d\n",a[n/2]);
        }

    }
}        