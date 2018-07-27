#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    while(1)
    {
        int n,r,a[1010];
        scanf("%d %d",&r,&n);
        if(r==-1&&n==-1)return 0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int i=0,ans=0;
        while(i<n)
        {
            int s=a[i++];//先让s指向第一个点
            while(i<n&&a[i]<=s+r)i++;//在半径的覆盖范围内就把i次数+1
            int p=a[i-1];
            while(i<n&&a[i]<=p+r)i++;
            ans++;//记录标记的点的个数
        }
        printf("%d\n",ans);
    }
    return 0;
}
