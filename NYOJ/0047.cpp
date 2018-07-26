 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    int a[1005];
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        while(n>=4)
        {
            if(2*a[1]+a[0]+a[n-1]<a[n-1]+a[n-2]+2*a[0])
                sum+=2*a[1]+a[0]+a[n-1];
            else
                sum+=a[n-1]+a[n-2]+2*a[0];
            n-=2;
        }
        if(n==1)
            sum+=a[0];
        else if(n==2)
            sum+=a[1];
        else if(n==3)
            sum+=a[1]+a[0]+a[2];
        printf("%d\n",sum);
    }
}        