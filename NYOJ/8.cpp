 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct rectangle
{
    int num;
    int l;
    int h;
} rec[1002];

bool cmp(rectangle x,rectangle y)
{
    if(x.num!=y.num) return x.num<y.num;
    if(x.l!=y.l) return x.l<y.l;
    return x.h<y.h;
}

int main()
{
    int n,m,chang,kuan;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%d",&m);
            for(int i=0; i<m; i++)
            {
                scanf("%d%d%d",&rec[i].num,&chang,&kuan);
                rec[i].l=max(chang,kuan);
                rec[i].h=min(chang,kuan);
            }
            sort(rec,rec+m,cmp);
            printf("%d %d %d\n",rec[0].num,rec[0].l,rec[0].h);
            for(int i=1; i<m; i++)
            {
                if(!(rec[i].num==rec[i-1].num&&rec[i].l==rec[i-1].l&&rec[i].h==rec[i-1].h))
                    printf("%d %d %d\n",rec[i].num,rec[i].l,rec[i].h);
            }
        }
    }
    return 0;
}
        