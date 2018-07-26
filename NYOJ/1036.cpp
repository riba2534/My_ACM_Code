 
#include <stdio.h>
#include <algorithm>
using namespace std;
struct time
{
    int b;
    int e;
} a[105];
bool cmp(time x,time y)
{
    return x.e<y.e;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int h1,m1,h2,m2;
        for(int i=0; i<n; i++)
        {
            scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
            a[i].b=h1*100+m1;
            a[i].e=h2*100+m2;
            if(a[i].b>a[i].e)
                swap(a[i].b,a[i].e);
        }
        sort(a,a+n,cmp);

        int end=a[0].e;
          int sum=1;
        for(int i=1; i<n; i++) //多区间选取最少公共点
        {
            if(a[i].b>end)
            {
                end=a[i].e;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
        