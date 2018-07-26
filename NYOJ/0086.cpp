 
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
  
using namespace std;  
  
int a[1000001];  
  
bool search(int index,int m)//输入要找的数，和数的个数  
{  
    int start = 0;  
    int end = m -1;//分别定义两个变量，指向头和尾  
    int mid;//中间值  
    while(start <= end)  
    {  
        mid = (start + end)/2;//计算出中间值  
        if(index < a[mid])//当要找的数小于这些数里面中间的那个数时  
            end = mid -1;//尾部就等于中间的那个数  
        else if(index > a[mid])//同理上面的  
            start = mid + 1;  
        else  
            return 1;  
    }  
    return 0;  
}  
int main()  
{  
    int m,n,i,k;  
    scanf("%d%d",&m,&n);  
    for(i = 0; i < m; i++)  
    {  
        scanf("%d",&a[i]);  
    }  
    sort(a,a+m);  
    for(i = 0; i < n; i++)  
    {  
        scanf("%d",&k);  
        printf("%s\n",search(k,m)?"YES":"NO");//重要得在这一句  
    }  
    return 0;  
}          