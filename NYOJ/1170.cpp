 
#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
using namespace std;  
int a[10010];  
void fun(int x,int y)  
{  
    if(a[x]==2)//当a[x]=2时，直接给左边加，因为3*后面的数比后面的数*2大  
    {  
        a[x]++;  
        return;  
    }  
    if(a[x]==0)//当a[x]=0时，就继续往左边有值的地方找  
    {  
        x--;  
    }  
    a[x]<=a[y]?a[x]++:a[y]++;//如果前面的小就靠前面加  
}  
int main()  
{  
    int n,i;  
    while(~scanf("%d",&n))  
    {  
        for(i=0; i<n; i++)  
            scanf("%d",&a[i]);  
        if(a[0]==1&&n>1)//先特判a[0]  
        {  
            a[0]=0;  
            a[1]++;  
        }  
        for(i=1; i<n-1; i++)//遍历第二个到倒数第二个  
        {  
            if(a[i]==1)  
            {  
                a[i]=0;//把有1的地方处理后标记成0  
                fun(i-1,i+1);//执行函数  
            }  
        }  
        if(a[n-1]==1&&n>1)//判断倒数第一个数  
        {  
            for(i=n-2; !a[i]; i--);//从倒数第二个数找到一个非0数  
            a[i]++;  
            a[n-1]=0;  
        }  
        int sum=1;  
        for(i=0; i<n; i++)  
        {  
            if(a[i])  
               sum=( sum*=a[i])%10086;//注意这里要给10086取模  
        }  
        printf("%d\n",sum);  
    }  
    return 0;  
}          