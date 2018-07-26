 
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
int a[1010],b[1010];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        memset(a,0,sizeof(a));  
        memset(b,0,sizeof(b));  
        for(int i=0; i<n; i++)  
            scanf("%d",&a[i]);  
        for(int i=0; i<n; i++)  
            scanf("%d",&b[i]);  
        sort(a,a+n);  
        sort(b,b+n);//从小到大排序  
        int tian=0;//记录田忌胜利次数  
        int i=0,j=0;  
        int begin=0,end=n-1;//首和尾  
        for(i=0; i<n; i++)  
        {  
            while(a[n-1]>b[end])//比较两者最大的马的速度,直到田忌的马小于国王  
            {  
                n--;  
                end--;  
                tian++;  
                if(i==n)break;  
            }  
            if(i==n)break;  
            if(a[i]==b[begin])//如果两者速度相等  
            {  
                if(a[i]<b[end])//比较田忌的马和国王那个比较速度大的马,如果一样就是平局  
                    tian--;  
                end--;  
            }  
            else if(a[i]>b[begin])//胜利  
            {  
                tian++;  
                begin++;  
            }  
            else if(a[i]<b[begin])//失败  
            {  
                end--;  
                tian--;  
            }  
        }  
        printf("%d\n",tian*200);  
    }  
    return 0;  
}          