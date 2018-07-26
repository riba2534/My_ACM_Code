 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int T,N,i,k;
    int a[201];
    scanf("%d",&T);
    while(T--)
    {
        int index[101]= {0};
        scanf("%d",&N);
        for(i=0; i<2*N; i++)
        {
            scanf("%d",&a[i]);
            index[a[i]]++;
        }
        sort(a,a+2*N);
        for(i=0; i<2*N; i++)
        {
            if(index[a[i]]>=1)
            {
                printf("%d ",a[i]);
                index[a[i]]=0;
            }
        }
        printf("\n");
    }
    return 0;
}        