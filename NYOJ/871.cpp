 
#include <stdio.h>
#include <algorithm>
using namespace std;
struct xuesheng
{
    int num;
    int score;
    char name[100];
}student[105];
bool cmp(xuesheng x,xuesheng y)
{
    return x.score>y.score;
}
bool cmp1(xuesheng x,xuesheng y)
{
    return x.num<y.num;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%s%d",&student[i].num,&student[i].name,&student[i].score);
        }
        stable_sort(student,student+m,cmp);
//        for(int i=0;i<m;i++)
//        {
//            int s=0;
//            if(student[i].score==student[i+1].score)
//            {
//                s++;
//            }
//            sort(student+i,student+s,cmp1);
//        }
        for(int i=0;i<m;i++)
        {
            printf("%d %s %d\n",student[i].num,student[i].name,student[i].score);
        }


    }
    return 0;
}        