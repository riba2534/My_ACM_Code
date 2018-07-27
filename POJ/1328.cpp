#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct island
{
    int x;
    int y;
    double xz;
    double xy;
} a[500000];
bool cmp(island x,island y)
{
    if(x.xy==y.xy)
        return x.xz<y.xz;
    else
        return x.xy<y.xy;
}
int main()
{
    int n,d;
    int q=0;
    while(1)
    {
        q++;
        int flag=0;
        scanf("%d %d",&n,&d);
        if(n==0&&d==0)break;
        for(int i=0; i<n; i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        for(int i=0; i<n; i++)
        {

            if(a[i].y>d)
            {
                flag=1;
                printf("Case %d: -1\n",q);
                break;
            }
            a[i].xz=(a[i].x*1.0)-sqrt((d*d*1.0)-(a[i].y*a[i].y*1.0));
            a[i].xy=(a[i].x*1.0)+sqrt((d*d*1.0)-(a[i].y*a[i].y*1.0));
        }
        if(flag)continue;
        sort(a,a+n,cmp);
        int sum=1;
        double end1=a[0].xy;
        for(int i=0; i<n; i++)
        {
            if(a[i].xz>end1)
            {
                end1=a[i].xy;
                sum++;
            }

        }
        printf("Case %d: %d\n",q,sum);

    }
    return 0;
}
