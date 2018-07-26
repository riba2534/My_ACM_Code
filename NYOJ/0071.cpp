 
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int weight,numr;
        scanf("%d %d",&weight,&numr);
        int a[350];
        for(int i=0; i<numr; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+numr);
        int num=0;
        int i=0,j=numr-1;
        while(i<=j)
        {
            if(a[i]+a[j]>weight)
            {
                j--;
                num++;
            }
            else
            {
                i++;
                j--;
                num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
        