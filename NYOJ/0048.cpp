 
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[1010];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=0;
    sort(a,a+n);
    int b[1010];
    for(int k=0;k<n;k++)
    {
        if(a[k]==a[k+1])
            sum++;
    }
    printf("%d\n",n-sum);
    int j;
    for(j=0; j<n; j++)
    {
        if(a[j]!=a[j+1])

        {
            //b[j]=a[j];
            printf("%d ",a[j]);
        }
    }
//    printf("%d\n",sum);
//    for(int i=0;i<j-sum;i++)
//    {
//        printf("%d ",b[i]);
//    }



    return 0;
}        