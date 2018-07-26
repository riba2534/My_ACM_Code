 
#include <stdio.h>  
#include <algorithm>  
using namespace std;  
struct qujian  
{  
    int x;  
    int y;  
} a[1005];  
bool cmp(qujian x,qujian y)  
{  
    if(x.y==y.y)  
        return x.x<y.x;  
    else  
        return x.y<y.y;  
}  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        for(int i=0; i<n; i++)  
            scanf("%d %d",&a[i].x,&a[i].y);  
        sort(a,a+n,cmp);  
//        for(int i=0; i<n; i++)  
//            printf("%d %d\n",a[i].x,a[i].y);  
        int sum=1;  
        int end=a[0].y;  
        for(int i=1; i<n; i++)  
        {  
            if(a[i].x>end)  
            {  
                end=a[i].y;  
                sum++;  
            }  
        }  
        printf("%d\n",sum);  
    }  
    return 0;  
}          