 
#include <stdio.h>  
#include <algorithm>  
using namespace std;  
struct md  
{  
    int lenth;  
    int weight;  
} a[5001];  
bool cmp(md x,md y)  
{  
    if(x.lenth==y.lenth)  
        return x.weight<y.weight;  
    else  
        return x.lenth<y.lenth;  
  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int n,i,j;  
        int q[5000];  
        scanf("%d",&n);  
        for(i=0; i<n; i++)  
        {  
            scanf("%d %d",&a[i].lenth,&a[i].weight);  
        }  
        sort(a,a+n,cmp);//按照长度从小到大排序  
        q[0]=a[0].weight;  
        int c=1;//记录木棒的时间  
        for(i=1; i<n; i++)//因为已经对涨肚排好序，现在只对重量进行操作  
        {  
            for(j=0; j<c; j++)  
                if(a[i].weight>=q[j])  
                {  
                    q[j]=a[i].weight;//刷新已经出现过的大的重量  
                    break;  
                }  
            if(j>=c)//遍历完所有q如果全小于，次数就增加  
            {  
                q[j]=a[i].weight;  
                c++;  
            }  
        }  
        printf("%d\n",c);  
    }  
  
  
    return 0;  
}          