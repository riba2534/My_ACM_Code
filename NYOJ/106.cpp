 
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct bao
{
    int value;
    int weight;
} a[15];
bool cmp(bao x,bao y)
{
    return x.value>y.value;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s,m,maxv=0;
        scanf("%d %d",&s,&m);
        for(int i=0; i<s; i++)
        {
            scanf("%d %d",&a[i].value,&a[i].weight);
        }
        sort(a,a+s,cmp);
//        printf("\n");
//        for(int i=0; i<s; i++)
//            printf("%d %d\n",a[i].value,a[i].weight);
        int i;
        for(i=0; i<s; i++)
        {
            if(m>a[i].weight)
            {
                m-=a[i].weight;
                maxv+=a[i].value*a[i].weight;
            }
            else
            {
                maxv+=a[i].value*m;
                break;
            }
        }
        printf("%d\n",maxv);

    }
    return 0;
}
        