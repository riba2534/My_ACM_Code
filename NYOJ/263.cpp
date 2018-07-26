 
#include <stdio.h>
#include <algorithm>
using namespace std;

struct gangguan
{
    int l;
    int r;
    int num;
} guan[1005];
struct guanr
{
    int r;
    int num;
}r[1005];
int bianhao[1005];


bool cmp(gangguan x,gangguan y)
{
    return x.l>y.l;
}
bool cmpr(guanr x,guanr y)
{
    return x.r<y.r;
}
bool cmphao(int a,int b)
{
    return a>b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&guan[i].l,&guan[i].r,&guan[i].num);
        }
        sort(guan,guan+n,cmp);

//        for(int k=0;k<n;k++)
//        {
//            printf("\n第一%d %d %d\n",guan[k].l,guan[k].r,guan[k].num);
//        }

        int b0=guan[0].l,i;
        for(i=0;b0==guan[0].l;i++)
        {
            r[i].r=guan[i].r;
            r[i].num=guan[i].num;
            b0=guan[i].l;
        }
        sort(r,r+i-1,cmpr);

//        for(int k=0;k<i-1;k++)
//        {
//            printf("\n第二%d %d\n",r[k].r,r[k].num);
//        }

        int b1=r[0].r,j=0;
        for(j=0;b1==r[j].r;j++)
        {
//             printf("j=%d\n",j);
            bianhao[j]=r[j].num;
            b1=r[j].r;
        }

        sort(bianhao,bianhao+j,cmphao);
//        for(int k=0;k<j;k++)
//        {
//            printf("\n第三%d\n",bianhao[k]);
//        }

        printf("%d\n",bianhao[0]);







    }

    return 0;
}
        