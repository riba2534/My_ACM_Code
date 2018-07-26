 
#include <stdio.h>
#include <algorithm>
using namespace std;
struct stu
{
    char name[100];
    int qimo;
    int banji;
    char ganbu;
    char xibu;
    int lunwen;
    int sum;
} ren[105];


bool cmp(stu a,stu b)
{
    return a.sum>b.sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int x;
        int zongshu=0;
        getchar();
        scanf("%d",&x);
        for(int i=0; i<x; i++)
        {
            scanf("%s %d %d %c %c %d",ren[i].name,&ren[i].qimo,&ren[i].banji,&ren[i].ganbu,&ren[i].xibu,&ren[i].lunwen);
        }
        for(int i=0;i<x;i++)
        {
            ren[i].sum=0;
        }
        for(int i=0; i<x; i++)
        {
            if(ren[i].qimo>80&&ren[i].lunwen>=1)
                ren[i].sum+=8000;
            if(ren[i].qimo>85&&ren[i].banji>80)
                ren[i].sum+=4000;
            if(ren[i].qimo>90)
                ren[i].sum+=2000;
            if(ren[i].qimo>85&&ren[i].xibu=='Y')
                ren[i].sum+=1000;
            if(ren[i].banji>80&&ren[i].ganbu=='Y')
                ren[i].sum+=850;
            zongshu+=ren[i].sum;
        }
        stable_sort(ren,ren+x,cmp);
        printf("%s\n%d\n%d\n",ren[0].name,ren[0].sum,zongshu);
    }
    return 0;
}


        