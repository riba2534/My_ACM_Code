 
#include<stdio.h>
int a[10001];
#define max(a,b,c) (a>b?a:b)>c?(a>b?a:b):c
#define min(a,b,c) (a<b?a:b)<c?(a<b?a:b):c
int main()
{
    int N,n,x;

    while(scanf("%d",&n)!=EOF)
    {
        int count=0,t1,t2,maxx=0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i=i+3)
        {
            t1=t2=0;
            count++;
            if(count%2==0)//偶数
                t1=min(a[i],a[i+1],a[i+2]);
            else
                t2=max(a[i],a[i+1],a[i+2]);
            maxx=max(maxx,t1,t2);
        }
        printf("%d\n",maxx);
    }
    return 0;
}        